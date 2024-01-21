# MALLOC LAB
## 整体思路
**显示空闲链表+分离适配**
- 划分多个大小类，以2的幂次来划分，从32开始，所以依次就是{32, 48}, {64, 80, 96, 112} ...
- 堆的起始位置后存放各个大小类的指针，指向对应大小类中的一个空闲块，然后加上序言块
- 每个普通块有一个表头和表尾，存储大小和是否分配信息，如果已分配，则无其他信息，若未分配，则在表头下方存储后继和前驱，分别指向所属大小类的后一个和前一个空闲块
## 函数实现
### 宏定义
参考书上的还有网上的
https://github.com/YaleXin/CS-APP3e-Labs/blob/main/Malloc-Lab/mm-v3.c
### `int mm_init(void)`
- 初始化所有大小类的根指针，以及分配序言块和第一个普通块的起始部分
- 后面可以看到序言快起始可以看作一个特殊的普通块，它的头和尾就类似普通块的表头和表尾，只是一开始分配信息就是已分配，这样后面的代码就比较好写，而且可以保护在它之前的表结构
```c++
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
  if (extend_heap(512) == NULL)
    return -1;
  return 0;
```

### `void *mm_malloc(size_t size)`
- 先将size转化为最接近16倍数的数，然后去相应的大小类中去找，如果没有找到，就去更大的大小类中去找
- 若找到了，就进行分配，但是考虑到那个块的空间可能比实际需要的大出一些，所以在判断一下是都可以分出一个块
- 若没有找到，那就开辟一个新的空间出来，先看能否和之前的块合并，然后就进行分配，和上述一样，需要考虑块较大时分出一个块
```c++
  size_t asize;
  size_t extendsize;
  char* bp;
  if (size <= DSIZE)
    asize = 2 * DSIZE;
  else
    asize = DSIZE * ((size + (DSIZE)+(DSIZE - 1)) / DSIZE);
  if ((bp = find_fit(asize)) != NULL) return place(bp, asize);
  extendsize = MAX(asize, CHUNKSIZE);
  if ((bp = extend_heap(extendsize)) == NULL) return NULL;
  return place(bp, asize);
```
### `void mm_free(void *ptr)`
- ptr为NULL，直接退出
- 先把分配位标记为0，然后考虑能否进行合并
```c++
  if (bp == 0) return;
  size_t size = GET_SIZE(HDRP(bp));
  PUT(HDRP(bp), PACK(size, 0));
  PUT(FTRP(bp), PACK(size, 0));
  coalesce(bp);
```
### `void *mm_realloc(void *ptr, size_t size)`
- ptr为NULL和size为0的情况都比较简单
- 否则先计算调整后的内存大小，等于当前块就直接返回，否则如果下一个块是空闲的，并且当前块和下一个块的大小合并后足够满足重新分配的需求，就进行合并，更新大小，并将下一个块从空闲列表中移除，如果下一个块是堆的末尾，并且需要扩展堆以满足重新分配的需求，就扩展堆并相应地更新大小，如果以上条件都不满足，就调用mm_malloc来分配新的内存块，然后使用memcpy将数据从旧块复制到新块，最后释放旧块

### 一些辅助函数
```c++
// 扩展堆，并且调用coalesce去合并
static void* extend_heap(size_t size);
// 分四种情况进行合并
static void* coalesce(void* bp);
// 查找是否有某个块满足需求
static void* find_fit(size_t size);
// 把一个空闲块插入对应的空闲链表中去
static void  insert_block(char* bp);
// 把一个块中对应的空闲链表中删除
static void  remove_block(char* bp);
// 分配一个块，并且考虑是否需要切割
static void* place(char* bp, size_t asize);
// 获取对应大小类的根指针相对表头的偏移量
static size_t  get_index(size_t size);
```

## 问题和优化的思路
1. binary中空间利用率低以及时间长
- 这个测例里面就是两种数值，但是一直交替出现，最后在跳着删除，这样堆中虽有很大的可用空间，但是无法使用，而且由于删除的那个较小的块和新的需要分配的块在一个大小类中，所以也会查询很长时间，所以策略就是把小的块往前放，大的块往后放，这样在删除的时候，那些大的块就可以很好的合并，从而提升一些利用率
2. coalescing中空间利用率低
- 这个测例就是不断有两个相同的，然后删除，在来一个二倍大小的块，然后删除，这样重复，一开始想的是这样岂不是会有空间浪费，但是打出调试信息后发现，因为一开始分配的空间和那个4090比较接近，但是又不够分配，所以又要开新的空间，在来一个还是不够，又要分配新的空间，也就是说我一开始分配的那个块一直没有被使用
- 那我首先想的就是加一个判断，如果是第一次进来发现大小不够，就不是去申请一篇新的那样大小的空间，二是在之前的基础上增加一些空间来满足要求，这样实现了之后确实可以有效提高，但是又导致其他测例的利用率下降，所以还是考虑使用其他的办法
- 然后就是想到，那既然一开始分配的块用不到，那我一开始就分配的小一点，这样虽然浪费，但是不多，虽然没能从根本上解决问题，但是确实使利用率上升了，而且一开始分配一个小一点的块，也能更好地使小的块往前，大的块往后
3. 遇到的一些困难
- 首先就是看书上的例子，然后开始改，把wsize和dszie改为8和16，就可以跑起来了，以为只需要这样改，然后在实现显示空闲链表的时候，发现一直段错误，不知道哪里有问题，最后是把地址打出来，发现了问题，原来地址是有48个有效位数的，但是我是用PUT只能存储4字节也就是32位的信息，那这样自然就会段错误，所以就把GET和PUT宏定义改了，这样总算是可以跑一些简单的例子了