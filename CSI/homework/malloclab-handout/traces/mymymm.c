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

#define ALIGNMENT 16

#define ALIGN(size) (((size) + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1))

#define SIZE_T_SIZE (ALIGN(sizeof(size_t)))

#define WSIZE       8       
#define DSIZE       16      
#define CHUNKSIZE  (1<<12)  
#define SEG_LEN     15

#define MAX(x, y) ((x) > (y)? (x) : (y))  

#define PACK(size, alloc)  ((size) | (alloc)) 

#define GET(p)       (*(size_t *)(p))            
#define PUT(p, val)  (*(size_t *)(p) = (size_t)(val))    

#define GET_SIZE(p)  (GET(p) & ~0x7)                  
#define GET_ALLOC(p) (GET(p) & 0x1)                    

#define HDRP(bp)       ((char *)(bp) - WSIZE)                      
#define FTRP(bp)       ((char *)(bp) + GET_SIZE(HDRP(bp)) - DSIZE) 

#define NEXT_BLKP(bp)  ((char *)(bp) + GET_SIZE(((char *)(bp) - WSIZE))) 
#define PREV_BLKP(bp)  ((char *)(bp) - GET_SIZE(((char *)(bp) - DSIZE)))

#define CRT_BLKSZ(bp) GET_SIZE(HDRP(bp))
#define NEXT_BLKSZ(bp) GET_SIZE(HDRP(NEXT_BLKP(bp)))
#define PREV_BLKSZ(bp) GET_SIZE(HDRP(PREV_BLKP(bp)))

#define PRED(bp)       ((char *)(bp) + WSIZE)
#define SUCC(bp)       ((char *)bp)

#define PRED_BLKP(bp)  (GET(PRED(bp)))
#define SUCC_BLKP(bp)  (GET(SUCC(bp)))

static char* heap_listp = 0;
static char* list_start;

static void* extend_heap(size_t size);
static void* coalesce(void* bp);
static void* find_fit(size_t size, int index);
static void  insert_block(char* bp);
static void  remove_block(char* bp);
static void* place(char* bp, size_t asize);
static size_t  get_index(size_t size);

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

    // if (heap_listp == 0)
    //     mm_init();

    if ((bp = find_fit(asize, get_index(asize))) != NULL)
        return place(bp, asize);

    /* 未找到适配，分配更多堆空间 */
    extendsize = MAX(asize, CHUNKSIZE);
    //printf("In mm_malloc | size:%d -> asize: %d extendsize = %d\n\n", size, asize, extendsize);
    if ((bp = extend_heap(extendsize)) == NULL)
        return NULL;

    return place(bp, asize);
}

void mm_free(void* ptr) {
    if (ptr == 0)
        return;

    char* bp = ptr;

    size_t size = GET_SIZE(HDRP(bp));

    if (heap_listp == 0)
        mm_init();

    PUT(HDRP(bp), PACK(size, 0));
    PUT(FTRP(bp), PACK(size, 0));
    coalesce(bp);
}

void* mm_realloc(void* ptr, size_t size) {
    void* oldptr = ptr;
    void* newptr;
    size_t copySize;

    newptr = mm_malloc(size);
    if (newptr == NULL)
        return NULL;
    copySize = *(size_t*)((char*)oldptr - SIZE_T_SIZE);
    if (size < copySize)
        copySize = size;
    memcpy(newptr, oldptr, copySize);
    mm_free(oldptr);
    return newptr;
}

static void* extend_heap(size_t size) {
    char* bp;

    if ((long)(bp = mem_sbrk(size)) == -1)
        return NULL;

    printf("\nextend heap and the pointer is %p\n", bp);
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
        size += PREV_BLKSZ(bp);
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

static void* find_fit(size_t size, int index) {
    char* res;
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

    void* succ = cur;

    while (SUCC_BLKP(succ)) {
        succ = (char*)SUCC_BLKP(succ);
        if ((unsigned int)succ >= (unsigned int)bp) {
            char* tmp = succ;
            succ = (char*)PRED_BLKP(succ);
            PUT(SUCC(succ), bp);
            PUT(PRED(bp), succ);
            PUT(SUCC(bp), tmp);
            PUT(PRED(tmp), bp);
            return;
        }
    }

    PUT(SUCC(succ), bp);
    PUT(PRED(bp), succ);
    PUT(SUCC(bp), NULL);
}

static void remove_block(char* bp) {
    int index = get_index(GET_SIZE(HDRP(bp)));
    char* cur = list_start + index * WSIZE;

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

    if (!GET_ALLOC(HDRP(bp)))
        remove_block(bp);
    if (rm_size >= 2 * DSIZE) {
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
            coalesce(NEXT_BLKP(bp));
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