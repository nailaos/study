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
  "2022010771",
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
#define CHUNKSIZE   (1<<12)  
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

// 紧邻的前一个/后一个块
#define NEXT_BLKP(bp)  ((char *)(bp) + GET_SIZE(((char *)(bp) - WSIZE))) 
#define PREV_BLKP(bp)  ((char *)(bp) - GET_SIZE(((char *)(bp) - DSIZE)))

// 获取当前块/前面/后面块的大小
#define CRT_BLKSZ(bp)  GET_SIZE(HDRP(bp))
#define NEXT_BLKSZ(bp) GET_SIZE(HDRP(NEXT_BLKP(bp)))
#define PREV_BLKSZ(bp) GET_SIZE(HDRP(PREV_BLKP(bp)))

#define PRED(bp)       ((char *)(bp) + WSIZE)
#define SUCC(bp)       ((char *)bp)

// 空闲链表的前驱和后继
#define PRED_BLKP(bp)  ((void *)GET(PRED(bp)))
#define SUCC_BLKP(bp)  ((void *)GET(SUCC(bp)))

static char* heap_listp = 0;
static char* list_start; // 表头

static void* extend_heap(size_t size);      // 扩展堆
static void* coalesce(void* bp);            // 合并
static void* find_fit(size_t size);         // 寻找适配(首次适配)
static void  insert_block(char* bp);        // 插入空闲块
static void  remove_block(char* bp);        // 删除空闲块
static void* place(char* bp, size_t asize); // 分配并根据剩余大小决定是否分割
static size_t  get_index(size_t size);      // 获取相对全局大小类表的偏移量

int mm_init(void) {
  if ((heap_listp = mem_sbrk((SEG_LEN + 3) * WSIZE)) == (void*)-1)
    return -1;

  int i;
  // 初始化各个大小类的根指针为NULL
  for (i = 0; i < SEG_LEN; i++)
    PUT(heap_listp + i * WSIZE, NULL);
  PUT(heap_listp + ((i + 0) * WSIZE), PACK(DSIZE, 1)); // 序言块头
  PUT(heap_listp + ((i + 1) * WSIZE), PACK(DSIZE, 1)); // 序言块尾
  PUT(heap_listp + ((i + 2) * WSIZE), PACK(0, 1));     // 第一个普通块的头

  list_start = heap_listp;                             // 表头的位置
  heap_listp += ((i + 1) * WSIZE);

  if (extend_heap(512) == NULL)                        // 初始时申请512字节的空间
    return -1;
  return 0;
}

void* mm_malloc(size_t size) {
  if (size == 0)
    return NULL;

  size_t asize;         // 调整后的大小
  size_t extendsize;    // 内存不够需要扩展的大小
  char* bp;             // 返回的内存地址

  if (size <= DSIZE)    // 计算调整后的大小，确保为16的倍数
    asize = 2 * DSIZE;
  else
    asize = DSIZE * ((size + (DSIZE)+(DSIZE - 1)) / DSIZE);

  if ((bp = find_fit(asize)) != NULL)          // 找到了，直接分配并返回
    return place(bp, asize);

  extendsize = MAX(asize, CHUNKSIZE);

  if ((bp = extend_heap(extendsize)) == NULL)  // 扩展出错
    return NULL;

  return place(bp, asize);                     // 分配扩展后的并返回
}

void mm_free(void* bp) {
  if (bp == 0)                   // 无需释放
    return;

  size_t size = GET_SIZE(HDRP(bp));

  PUT(HDRP(bp), PACK(size, 0));  // 标记为空
  PUT(FTRP(bp), PACK(size, 0));
  coalesce(bp);                  // 合并
}

void* mm_realloc(void* ptr, size_t size) {
  if (ptr == NULL)               // 为空直接malloc
    return mm_malloc(size);

  else if (size == 0) {          // size为0相当于释放
    mm_free(ptr);
    return NULL;
  }

  size_t asize, old_size = CRT_BLKSZ(ptr);
  if (size <= DSIZE)             // 计算调整后的大小，确保为16的倍数
    asize = 2 * DSIZE;
  else
    asize = DSIZE * ((size + (DSIZE)+(DSIZE - 1)) / DSIZE);
  char* newptr;

  if (old_size == asize)         // 和旧的size一样，直接返回
    return ptr;

  size_t prev_alloc = GET_ALLOC(FTRP(PREV_BLKP(ptr)));  // 前一个块的分配情况
  size_t next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(ptr)));  // 后一个块的分配情况
  size_t next_size = NEXT_BLKSZ(ptr);                   // 后一个块的大小
  char* next_bp = NEXT_BLKP(ptr);                       // 后一个块的指针
  size_t total_size = old_size;                         // 总大小

  if (prev_alloc && !next_alloc && (old_size + next_size >= asize)) { // 下一个块是空闲的，并且当前块和下一个块的大小合并后足够满足重新分配的需求
    total_size += next_size;
    remove_block(next_bp);
    PUT(HDRP(ptr), PACK(total_size, 1));
    PUT(FTRP(ptr), PACK(total_size, 1));
    place(ptr, total_size);
  } else if (!next_size && asize >= old_size) {  // 下一个块是堆的末尾，并且需要扩展堆以满足重新分配的需求，就扩展堆并相应地更新大小
    size_t extend_size = asize - old_size;
    if ((long)(mem_sbrk(extend_size)) == -1)
      return NULL;
    PUT(HDRP(ptr), PACK(total_size + extend_size, 1));
    PUT(FTRP(ptr), PACK(total_size + extend_size, 1));
    PUT(HDRP(NEXT_BLKP(ptr)), PACK(0, 1));
    place(ptr, asize);
  } else {  // 调用mm_malloc来分配新的内存块，然后使用memcpy将数据从旧块复制到新块，最后释放旧块
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

  if ((long)(bp = mem_sbrk(size)) == -1)  // 分配失败
    return NULL;

  PUT(HDRP(bp), PACK(size, 0));           // 头部写入大小信息，标记为空
  PUT(FTRP(bp), PACK(size, 0));           // 尾部写入大小信息，标记为空
  PUT(HDRP(NEXT_BLKP(bp)), PACK(0, 1));   // 下一个块的头部，也是结尾块，标记为0大小，已分配

  return coalesce(bp);                    // 合并
}

static void* coalesce(void* bp) {
  size_t prev_alloc = GET_ALLOC(FTRP(PREV_BLKP(bp)));
  size_t next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(bp)));
  size_t size = GET_SIZE(HDRP(bp));

  if (prev_alloc && next_alloc) {          // 前后都不为空
    insert_block(bp);
    return bp;
  } else if (prev_alloc && !next_alloc) {  // 后为空
    size += NEXT_BLKSZ(bp);                // 计算合并后的大小
    remove_block(NEXT_BLKP(bp));           // 删除后面的块
    PUT(HDRP(bp), PACK(size, 0));          // 写入大小信息，标记为空
    PUT(FTRP(bp), PACK(size, 0));
  } else if (!prev_alloc && next_alloc) {  // 前为空(操作类似)
    size += PREV_BLKSZ(bp);
    remove_block(PREV_BLKP(bp));
    PUT(FTRP(bp), PACK(size, 0));
    PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
    bp = PREV_BLKP(bp);
  } else {                                 // 均为空(操作类似)
    size += NEXT_BLKSZ(bp) + PREV_BLKSZ(bp);
    remove_block(PREV_BLKP(bp));
    remove_block(NEXT_BLKP(bp));
    PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
    PUT(FTRP(NEXT_BLKP(bp)), PACK(size, 0));
    bp = PREV_BLKP(bp);
  }
  insert_block(bp);
  return bp;
}

static void* find_fit(size_t size) {
  int index = get_index(size);                 // 获取偏移量
  while (index < SEG_LEN) {
    char* cur = list_start + index * WSIZE;    // 对应大小类的根指针
    char* bp = (char*)SUCC_BLKP(cur);          // 指向的第一个空闲块
    while (bp) {
      if (size <= (size_t)GET_SIZE(HDRP(bp)))  // 大小符合要求，直接返回
        return bp;

      bp = (char*)SUCC_BLKP(bp);               // 取它的后继，继续进行遍历
    }
    index++;                                   // 当前的大小类中没有找到，去更大大小类中去找
  }
  return NULL;                                 // 没有找到，返回NULL
}

static void insert_block(char* bp) {
  int index = get_index(GET_SIZE(HDRP(bp)));   // 获取偏移量
  char* cur = list_start + index * WSIZE;      // 对应大小类的根指针

  if (SUCC_BLKP(cur)) {                        // 链表不为空，把它作为第二个元素插入
    void* succ = SUCC_BLKP(cur);
    PUT(SUCC(cur), bp);
    PUT(SUCC(bp), succ);
    PUT(PRED(bp), cur);
    PUT(PRED(succ), bp);
  } else {                                     // 链表为空，直接插入，它的后继标记为NULL
    PUT(SUCC(cur), bp);
    PUT(PRED(bp), cur);
    PUT(SUCC(bp), NULL);
  }
}

static void remove_block(char* bp) {
  if (SUCC_BLKP(bp) && PRED_BLKP(bp)) {       // 前驱和后继都存在，把前驱和后继连起来
    PUT(SUCC(PRED_BLKP(bp)), SUCC_BLKP(bp));
    PUT(PRED(SUCC_BLKP(bp)), PRED_BLKP(bp));
  } else if (PRED_BLKP(bp)) {                 // 后继不存在，把后继标记为NULL
    PUT(SUCC(PRED_BLKP(bp)), NULL);
  }

  PUT(SUCC(bp), NULL);                        // 清除块自身的前驱和后继信息
  PUT(PRED(bp), NULL);
}

static void* place(char* bp, size_t asize) {
  size_t size = GET_SIZE(HDRP(bp));       // 它本身的大小
  size_t rsize = size - asize;            // 除去分配还剩余的大小

  remove_block(bp);

  if (rsize >= 2 * DSIZE) {               // 剩余大小可以分配为一个块
    if (asize > 96) {                     // 大块往后面放
      PUT(HDRP(bp), PACK(rsize, 0));
      PUT(FTRP(bp), PACK(rsize, 0));
      PUT(HDRP(NEXT_BLKP(bp)), PACK(asize, 1));
      PUT(FTRP(NEXT_BLKP(bp)), PACK(asize, 1));
      insert_block(bp);
      return NEXT_BLKP(bp);
    } else {                              // 小块往前面放
      PUT(HDRP(bp), PACK(asize, 1));
      PUT(FTRP(bp), PACK(asize, 1));
      PUT(HDRP(NEXT_BLKP(bp)), PACK(rsize, 0));
      PUT(FTRP(NEXT_BLKP(bp)), PACK(rsize, 0));
      insert_block(NEXT_BLKP(bp));
    }
  } else {                               // 剩余大小无法分出一个块，直接标记分配信息返回
    PUT(HDRP(bp), PACK(size, 1));
    PUT(FTRP(bp), PACK(size, 1));
  }
  return bp;
}

static size_t get_index(size_t v) {
  size_t index = v / 16;
  size_t num = 0;
  while (index /= 2) {
    num++;
  }
  if (num >= SEG_LEN)  // 不能超出限制，最后一个大小类包含N到正无穷
    num = SEG_LEN - 1;
  return num;
}