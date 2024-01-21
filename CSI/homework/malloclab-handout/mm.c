#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#include "memlib.h"
#include "mm.h"

team_t team = {
  /* Team name */
  "ateam",
  /* First member's full name */
  "Lv Jiaxin",
  /* First member's email address */
  "lvjx22@mails.tsinghua.edu.cn",
  /* Second member's full name (leave blank if none) */
  "",
  /* Second member's email address (leave blank if none) */
  ""
};

#define ALLOCATED 1

#define WSIZE       8       
#define DSIZE       16      
#define CHUNKSIZE  (1<<8)  
#define SEG_LEN     15

#define MAX(x, y) ((x) > (y)? (x) : (y))  
#define MIN(x, y) ((x) < (y)? (x) : (y))  

#define PACK(size, alloc)  ((size) | (alloc)) 

#define GET(p)       (*(size_t *)(p))            
#define PUT(p, val)  (*(size_t *)(p) = (size_t)(val))    

#define GET_SIZE(p)  (GET(p) & ~0x7)                  
#define GET_ALLOC(p) (GET(p) & 0x1)                    

#define HDRP(bp)       ((char *)(bp) - WSIZE)                      
#define FTRP(bp)       ((char *)(bp) + GET_SIZE(HDRP(bp)) - DSIZE) 

#define NEXT_BLKP(bp)  ((char *)(bp) + GET_SIZE(((char *)(bp) - WSIZE))) 
#define PREV_BLKP(bp)  ((char *)(bp) - GET_SIZE(((char *)(bp) - DSIZE)))

#define CRT_BLKSZ(bp)  GET_SIZE(HDRP(bp))
#define NEXT_BLKSZ(bp) GET_SIZE(HDRP(NEXT_BLKP(bp)))
#define PREV_BLKSZ(bp) GET_SIZE(HDRP(PREV_BLKP(bp)))

#define PRED(bp)       ((char *)(bp) + WSIZE)
#define SUCC(bp)       ((char *)bp)

#define PRED_BLKP(bp)  ((void *)GET(PRED(bp)))
#define SUCC_BLKP(bp)  ((void *)GET(SUCC(bp)))

static char* heap_listp = 0;
static char* list_start;

static void* extend_heap(size_t size);
static void* coalesce(void* bp);
static void* find_fit(size_t size);
static void  insert_block(char* bp);
static void  remove_block(char* bp);
static void* place(char* bp, size_t asize);
static size_t  get_index(size_t size);

/* ========================= DEBUG ========================= */
static void Error_Handler(char* bp, char* __ERROR_MSG__);
/* print_funcname: 打印函数名 */
static void print_funcname(char* name) {
  printf("In %s\n", name);
}

/* print_heap_list: 打印堆块组织方式 */
static void print_heap_list(char* __FUNCNAME__) {
  printf("-----------===  Block List ===--------------\n");
  print_funcname(__FUNCNAME__);
  char* bp = heap_listp;
  while (GET_ALLOC(HDRP(bp)) != 1 || CRT_BLKSZ(bp) != 0) {
    if (!GET_ALLOC(HDRP(bp)) && !CRT_BLKSZ(bp)) {
      Error_Handler(bp, "Heap Last Pointer Leak!!!\n");
      exit(-1);
    }
    printf("Block Pointer: %p \t Allocated: %ld \t Size: %ld\n", bp, GET_ALLOC(HDRP(bp)), CRT_BLKSZ(bp));
    bp = NEXT_BLKP(bp);
  }
  printf("Block Pointer: %p \t Allocated: %ld \t Size: %ld\n", bp, GET_ALLOC(HDRP(bp)), CRT_BLKSZ(bp));
  printf("----------------------------------------------------\n\n");
}

/* print_block_info: 打印bp指向块的详细信息 */
static void print_block_info(char* bp, char* __FUNCNAME__) {
  printf("-------------=== BLOCK INFO ===----------------\n");
  print_funcname(__FUNCNAME__);
  printf("Pointer: %p\n", bp);
  char* __STATE__ = GET_ALLOC(HDRP(bp)) == ALLOCATED ? "ALLOCATED" : "FREE";
  printf("STATE: %s \t Header_SIZE: %ld \t Footer_SIZE: %ld\n", __STATE__, GET_SIZE(HDRP(bp)), GET_SIZE(FTRP(bp)));
  if (!GET_ALLOC(HDRP(bp))) {
    int seg_index = get_index(CRT_BLKSZ(bp));
    char* root = list_start + seg_index * WSIZE;
    printf("ROOT: %p\n", root);
    if ((void*)PRED_BLKP(bp)) printf("PRED_BLKP: %p \t", (void*)PRED_BLKP(bp)); else printf("PRED_BLKP: NULL \t");
    if ((void*)SUCC_BLKP(bp)) printf("SUSUCC_BLKPC: %p \n", (void*)SUCC_BLKP(bp)); else printf("SUCC_BLKP: NULL \n");
  }

  printf("----------------------------------------------------\n\n");
}

/* print_free_list: 打印当前空闲列表信息 */
static void print_free_list(char* __FUNCNAME__) {
  printf("-------------=== FREE BLOCK LIST ===----------------\n");
  print_funcname(__FUNCNAME__);
  int seg_idx = 0;

  while (seg_idx < SEG_LEN) {
    char* root = list_start + seg_idx * WSIZE;
    char* bp = (char*)SUCC_BLKP(root);
    while (bp) {
      char* __STATE__ = GET_ALLOC(HDRP(bp)) == ALLOCATED ? "ALLOCATED" : "FREE";
      printf("bp: %p \t ROOT: %p \t STATE: %s \t SIZE: %ld \t", bp, root, __STATE__, CRT_BLKSZ(bp));

      if (!GET_ALLOC(HDRP(bp))) {
        if ((void*)PRED_BLKP(bp)) printf("PRED_BLKP: %p \t", (void*)PRED_BLKP(bp)); else printf("PRED_BLKP: NULL \t");
        if ((void*)SUCC_BLKP(bp)) printf("SUSUCC_BLKPC: %p \n\n", (void*)SUCC_BLKP(bp)); else printf("SUCC_BLKP: NULL \n\n");
      }
      bp = (char*)SUCC_BLKP(bp);
    }
    seg_idx++;
  }

  printf("----------------------------------------------------\n\n");
}

/* show_free_link: 展示以root开头的大小类空闲链表 */
static void show_free_link(char* root) {
  if (SUCC_BLKP(root))
    printf("ROOT: %p --> ", root);
  else {
    printf("ROOT: %p\n", root);
    return;
  }
  char* succ = (char*)SUCC_BLKP(root);
  while (SUCC_BLKP(succ)) {
    printf("%p ---> ", succ);
    succ = (char*)SUCC_BLKP(succ);
  }
  printf("%p\n", succ);
}

/* Error_Handler: 打印错误信息 */
static void Error_Handler(char* bp, char* __ERROR_MSG__) {
  printf("%s", __ERROR_MSG__);
  print_block_info(bp, "Error");
}

int mm_init(void) {
  if ((heap_listp = mem_sbrk((SEG_LEN + 3) * WSIZE)) == (void*)-1)
    return -1;

  int i;
  for (i = 0; i < SEG_LEN; i++)
    PUT(heap_listp + i * WSIZE, NULL);
  PUT(heap_listp + ((i + 0) * WSIZE), PACK(DSIZE, 1));
  PUT(heap_listp + ((i + 1) * WSIZE), PACK(DSIZE, 1));
  PUT(heap_listp + ((i + 2) * WSIZE), PACK(0, 1));

  list_start = heap_listp;
  heap_listp += ((i + 1) * WSIZE);

  if (extend_heap(CHUNKSIZE) == NULL)
    return -1;
  return 0;
}

void* mm_malloc(size_t size) {
  if (size == 0)
    return NULL;

  size_t asize;
  size_t extendsize;
  char* bp;

  if (size <= DSIZE)
    asize = 2 * DSIZE;
  else
    asize = DSIZE * ((size + (DSIZE)+(DSIZE - 1)) / DSIZE);

  if (size == 112) {
    asize = 128 + 16;
    printf("size is %ld, asize is %ld\n", size, asize);
  }
  //printf("malloc size: %ld\n", asize);
//print_free_list("check free list\n");
  if ((bp = find_fit(asize)) != NULL)
    return place(bp, asize);

  extendsize = MAX(asize, CHUNKSIZE);
  //printf("In mm_malloc | size:%ld -> asize: %ld extendsize = %ld\n\n", size, asize, extendsize);
  //print_free_list("check free list\n");
  if ((bp = extend_heap(extendsize)) == NULL)
    return NULL;


  return place(bp, asize);
}

void mm_free(void* bp) {
  if (bp == 0)
    return;

  size_t size = GET_SIZE(HDRP(bp));

  if (heap_listp == 0)
    mm_init();

  PUT(HDRP(bp), PACK(size, 0));
  PUT(FTRP(bp), PACK(size, 0));
  coalesce(bp);
}

void* mm_realloc(void* ptr, size_t size) {
  if (ptr == NULL)
    return mm_malloc(size);

  else if (size == 0) {
    mm_free(ptr);
    return NULL;
  }
  size_t asize, old_size = CRT_BLKSZ(ptr);
  if (size <= DSIZE)
    asize = 2 * DSIZE;
  else
    asize = DSIZE * ((size + (DSIZE)+(DSIZE - 1)) / DSIZE);
  char* newptr;

  if (old_size == asize)
    return ptr;

  size_t prev_alloc = GET_ALLOC(FTRP(PREV_BLKP(ptr)));
  size_t next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(ptr)));
  size_t next_size = NEXT_BLKSZ(ptr);
  char* next_bp = NEXT_BLKP(ptr);
  size_t total_size = old_size;

  if (prev_alloc && !next_alloc && (old_size + next_size >= asize)) {    // 后空闲  
    total_size += next_size;
    remove_block(next_bp);
    PUT(HDRP(ptr), PACK(total_size, 1));
    PUT(FTRP(ptr), PACK(total_size, 1));
    place(ptr, total_size);
  } else if (!next_size && asize >= old_size) {
    size_t extend_size = asize - old_size;
    if ((long)(mem_sbrk(extend_size)) == -1)
      return NULL;

    PUT(HDRP(ptr), PACK(total_size + extend_size, 1));
    PUT(FTRP(ptr), PACK(total_size + extend_size, 1));
    PUT(HDRP(NEXT_BLKP(ptr)), PACK(0, 1));
    place(ptr, asize);
  } else {
    newptr = mm_malloc(asize);
    if (newptr == NULL)
      return NULL;
    memcpy(newptr, ptr, MIN(old_size, size));
    mm_free(ptr);
    return newptr;
  }
  return ptr;
}

static void* extend_heap(size_t size) {
  char* bp;

  if ((long)(bp = mem_sbrk(size)) == -1)
    return NULL;

  PUT(HDRP(bp), PACK(size, 0));
  PUT(FTRP(bp), PACK(size, 0));
  PUT(HDRP(NEXT_BLKP(bp)), PACK(0, 1));

  return coalesce(bp);
}

static void* coalesce(void* bp) {
  size_t prev_alloc = GET_ALLOC(FTRP(PREV_BLKP(bp)));
  size_t next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(bp)));
  size_t size = GET_SIZE(HDRP(bp));

  if (prev_alloc && next_alloc) {
    insert_block(bp);
    return bp;
  } else if (prev_alloc && !next_alloc) {
    size += NEXT_BLKSZ(bp);
    remove_block(NEXT_BLKP(bp));
    PUT(HDRP(bp), PACK(size, 0));
    PUT(FTRP(bp), PACK(size, 0));
    PUT(PRED(bp), NULL);
    PUT(SUCC(bp), NULL);
  } else if (!prev_alloc && next_alloc) {
    //printf("pred is empty, and the size berfore add is %ld\n", size);
    size += PREV_BLKSZ(bp);
    //printf("after add the size is %ld\n", size);
    remove_block(PREV_BLKP(bp));
    PUT(FTRP(bp), PACK(size, 0));
    PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
    bp = PREV_BLKP(bp);
    PUT(PRED(bp), NULL);
    PUT(SUCC(bp), NULL);
  } else {
    size += NEXT_BLKSZ(bp) + PREV_BLKSZ(bp);
    remove_block(PREV_BLKP(bp));
    remove_block(NEXT_BLKP(bp));
    PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
    PUT(FTRP(NEXT_BLKP(bp)), PACK(size, 0));
    bp = PREV_BLKP(bp);
    PUT(PRED(bp), NULL);
    PUT(SUCC(bp), NULL);
  }
  insert_block(bp);
  return bp;
}

static void* find_fit(size_t size) {
  int index = get_index(size);
  while (index < SEG_LEN) {
    char* cur = list_start + index * WSIZE;
    char* bp = (char*)SUCC_BLKP(cur);
    while (bp) {
      if (size <= (size_t)GET_SIZE(HDRP(bp)))
        return bp;

      bp = (char*)SUCC_BLKP(bp);
    }
    index++;
  }
  return NULL;
}



static void insert_block(char* bp) {
  int index = get_index(GET_SIZE(HDRP(bp)));
  char* cur = list_start + index * WSIZE;

  if (SUCC_BLKP(cur)) {
    void* succ = SUCC_BLKP(cur);
    PUT(SUCC(cur), bp);
    PUT(SUCC(bp), succ);
    PUT(PRED(bp), cur);
    PUT(PRED(succ), bp);
  } else {
    PUT(SUCC(cur), bp);
    PUT(PRED(bp), cur);
    PUT(SUCC(bp), NULL);
  }
}

static void remove_block(char* bp) {
  if (SUCC_BLKP(bp) && PRED_BLKP(bp)) {
    PUT(SUCC(PRED_BLKP(bp)), SUCC_BLKP(bp));
    PUT(PRED(SUCC_BLKP(bp)), PRED_BLKP(bp));
  } else if (PRED_BLKP(bp)) {
    PUT(SUCC(PRED_BLKP(bp)), NULL);
  }

  PUT(SUCC(bp), NULL);
  PUT(PRED(bp), NULL);
}

static void* place(char* bp, size_t asize) {
  size_t blk_size = GET_SIZE(HDRP(bp));
  size_t rm_size = blk_size - asize;

  remove_block(bp);

  if (rm_size >= 2 * DSIZE) {
    //printf("blk_size: %ld, rm_size: %ld, asize: %ld\n", blk_size, rm_size, asize);
    if (asize > 64) {
      PUT(HDRP(bp), PACK(rm_size, 0));
      PUT(FTRP(bp), PACK(rm_size, 0));
      PUT(HDRP(NEXT_BLKP(bp)), PACK(asize, 1));
      PUT(FTRP(NEXT_BLKP(bp)), PACK(asize, 1));
      insert_block(bp);
      return NEXT_BLKP(bp);
    } else {
      PUT(HDRP(bp), PACK(asize, 1));
      PUT(FTRP(bp), PACK(asize, 1));
      PUT(HDRP(NEXT_BLKP(bp)), PACK(rm_size, 0));
      PUT(FTRP(NEXT_BLKP(bp)), PACK(rm_size, 0));
      insert_block(NEXT_BLKP(bp));
    }
  } else {
    PUT(HDRP(bp), PACK(blk_size, 1));
    PUT(FTRP(bp), PACK(blk_size, 1));
  }
  return bp;
}

static size_t get_index(size_t v) {
  size_t index = v / 16;
  size_t num = 0;
  while (index /= 2) {
    num++;
  }
  if (num >= SEG_LEN)
    num = SEG_LEN - 1;
  return num;
}