### Kidd

1. ##### 算法实现的思路
   - 压缩数组实现线段树，每个节点都是扑克牌的一个闭区间，p的左孩子为2p，右孩子为2p+1(初始化大小设为4n)
   ```c++
   unsigned long long *seg; // 存储该节点被翻转的次数
   int *lazy; // 存储懒惰翻转的次数
   ```
   - 预处理区间信息，先存下所有会用到的区间值，对于这些值先进行排序操作，然后去除其中的重复元素，同时实现数据的离散化，即如果一个值x出现了，那么说明有一个区间$[x,x]$需要维护，对于x，y位置相邻，但是x和y差值大于1，说明有一个区间$[x+1, y-1]$需要维护，比如说1，2,7，8对应的区间序列就是$[1,1],[2,2],[3,6],[7,7],[8,8]$，然后让之前的每个点成为对应区间的下标，1就是0，2就是1，7就是4，8就是5
   - 更新操作，from和to是目标区间，start和end是当前区间
   ```c++
   void updateTree(int from, int to, int start, int end,   int x) {
       // 包含，则直接返回，反转次数就是区间长度
       if (from <= start && end <= to) {
           seg[x] += (long long)(myRanges[end].end - myRanges[start].start + 1);
       lazy[x]++;
           return;
       }
       int mid = (start + end) / 2;
       // 处理lazy标记
       if (lazy[x] && start != end)
           dealLazy(x, start, end);
       // 说明左树中还有重叠区间
       if (from <= mid)
           updateTree(from, to, start, mid, 2 * x);
       // 说明右树中还有重叠区间
       if (mid < to)
           updateTree(from, to, mid + 1, end, 2 * x + 1);
       seg[x] = seg[2 * x] + seg[2 * x + 1];
   }
   ```
   - 查询操作
   ```c++
   long long int searchTree(int from, int to, int start, int end, int x) {
       // 包含，直接返回seg
       if (from <= start && end <= to)
           return seg[x];
       int mid = (start + end) / 2;
       // lazy下溢
       if (lazy[x] && start != end)
           dealLazy(x, start, end);
       long long sum = 0;
       // 去左树查找
       if (from <= mid)
           sum += searchTree(from, to, start, mid, 2 * x);
       // 去右树查找
       if (mid < to)
           sum += searchTree(from, to, mid + 1, end, 2 * x + 1);
       return sum;
   }
   ```
   - lazy下溢
   ```c++
   void dealLazy(int x, int start, int end) {
       int l = 2 * x;
       int r = 2 * x + 1;
       int mid = (start + end) / 2;
       seg[l] += (long long)lazy[x] * (long long)(myRanges[mid].end - myRanges[start].start + 1);
       seg[r] += (long long)lazy[x] * (long long)(myRanges[end].end - myRanges[mid + 1].start + 1);
       lazy[l] += lazy[x];
       lazy[r] += lazy[x];
       lazy[x] = 0;
   }
   ```
2. ##### 遇到的问题
   - 一开始没有做数据离散化，导致超内存，还有后面如何离散化数据废了点时间想和调试
   - lazy一开始设计的是bool类型，但是这样就无法多次记录翻转
3. ##### 时间复杂度: $O(mlog(m))$
   - 建树: $O(m)$
   - 查询: 单次查询复杂度是$O(logm)$，整体就是$O(mlogm)$
4. ##### 空间复杂度: $O(m)$

