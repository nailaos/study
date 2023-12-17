### NeareastNeighor

1. ##### 算法实现的思路
   - KD-树，先以初始时给的点进行空间划分，依次按照不同的维度去划分，以使点的分布变得均匀，每个节点中保存当前划分的维度，向量值，左右孩子和父亲节点
   ```c++
   struct KDtree {
       int dim;
       int vect[5];
       KDtree* l;
       KDtree* r;
       KDtree* parent;
   }
   ```
   - 最近邻搜索`void findNearest(KDtree* tre, int* ques, long long int& ans)`
     1. 先根据当前维度对应的值决定要进入哪个子空间，直到到达叶子节点，到达之后更新最小距离
     ```c++
     // 判断进入哪一个子空间
     if (ques[dim] < curr->vect[dim]) {
         curr = curr->l;
     } else {
         curr = curr->r;
     }
     // 更新最小距离
     ans = min(ans, distance(ques, curr->vect));
     ```
     2. 开始回溯，判断是否需要进入兄弟空间中去搜索，依据就是当前的最小距离是否小于目标点到两个空间的分界面的距离，直到到达根节点结束
     ```c++
     if (sqrt(ans) > (double)(abs(ques[dim] - curr->parent->vect[dim]))) {
         ans = min(ans, distance(ques, curr->parent->vect));
         // 大于，说明需要进入兄弟节点搜索
         findNearest(curr->brother(), ques, ans);
     } else {
         // 否则，向上回溯
         curr = curr->parent;
     }
     ```
2. ##### 遇到的问题
   - 在效率优化的时候，第一次想着可不可以每个节点都保存多个值，但是那样似乎回溯的时候需要考虑的情况就比较多，因为之前是将一个空间分为两个子空间，而每个节点中保存多个值，就相当于分成了三个子空间，然后也可能想的不到位，没有搞出来
3. ##### 时间复杂度:
   - 建树操作: $O(n(logn)^2)$
   - 查询操作，每次查询最坏情况下为$O(n)$，但是由于数据是随机生成的，所以整体效率会比较不错
4. ##### 空间复杂度: $O(n)$

