# BBST

### 1. 数据结构的实现过程及复杂度分析
#### AvlTree
- 节点结构：AVL 树的每个节点包含一个值、指向左右子节点的指针，以及节点的高度信息
- 平衡因子：即左右子树的高度差
    ```c++
    int getBalance(Node* node) {
        return (node) ? Height(node->left) - Height(node->right) : 0;
    }
    ```
- 旋转操作：当节点的平衡因子大于1或小于-1时，说明需要旋转，先实现左旋和右旋，然后依据当前树的结构，选择正确的旋转组合
    ```c++
    int b = getBalance(node);
    if (b > 1) {
        if (getBalance(node->left) >= 0)
            return rotateRight(node);
        else {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }
    // b < -1同理
    ```
- 插入：通过递归比较值的大小，找到插入的位置，每次插入后，更新节点高度，并在需要时重新平衡树
    ```c++
    if (!node) return new Node(val);
    if (val < node->value)
        node->left = insert(node->left, val);
    else ...
    updateHeight(node);
    return rebalance(node);
    ```
- 删除：通过递归比较值的大小，找到需要删除的节点，如果左右孩子均存在就找到后继并且用后继的值代替自己的值，转为删除后继，否则直接删除，每次删除后，更新节点高度，并在需要时重新平衡树

- 搜索：从树根遍历到叶子节点，期间记录遇到的最大的满足条件的值
    ```c++
    int res = -1;
    Node* cur = root;
    while (cur) {
        if (cur->value <= tar) {
            res = max(res, cur->value);
            cur = cur->right;
        } else
            cur = cur->left;
    }
    ```
- 复杂度
    - 插入：$O(logn)$ 最好$O(1)$ 最坏$O(logn)$
    - 删除：$O(logn)$ 最好$O(1)$ 最坏$O(logn)$
    - 查找：$O(logn)$ 最好$O(1)$ 最坏$O(logn)$
#### SplayTree
- 按照ppt上示例代码的思路写的
- 节点结构：Splay 树的每个节点包含一个值、指向左右子节点的指针，以及指向父节点的指针
- 伸展操作：如果祖父存在，就进行双旋，分四种情况分别处理，最后检查一下是否需要进行单旋
    ```c++
    while ((p = node->parent) && (g = p->parent)) {
        Node* gg = g->parent;
        // 4种情况分别处理
        if (node->isLeftChild()) {
            if (p->isLeftChild()) {
                attachAsLC(p->right, g); attachAsLC(node->right, p);
                attachAsRC(p, g); attachAsRC(node, p);
            } else { ... }
        } else { ... }
        if (!gg) node->parent = NULL;
        else
            (g == gg->left) ? attachAsLC(node, gg) : attachAsRC(gg, node);
    }
    if (p = node->parent) {
        if (node->isLeftChild()) {
            attachAsLC(node->right, p); attachAsRC(node, p);
        } else { ... }
    }
    ```
- 插入：先执行搜索找出插入位置并splay至树根，依据目标值和根节点值的大小关系重构树
    ```c++
    if (!root) {
        root = new Node(val); return;
    }
    Node* node = search(val);
    if (node->value < val) {
        node->parent = root = new Node(val, node, node->right);
        if (node->right) { node->right->parent = root; node->right = nullptr; }
    } else { ... }
    ```
- 删除：先执行搜索找出删除位置并splay至树根，记录左右子树，删除树根，合并左右子树
    ```c++
    search(val);
    Node* L = root->left;
    Node* R = root->right;
    delete root;
    if (!R) {
        if (L) L->parent = nullptr; root = L;
    } else {
        R->parent = nullptr; root = R;
        if (L) {
            search(val); L->parent = root; root->left = L;
        }
    }
    ```
- 搜索：和AvlTree一样，不过加一个node去记录那个节点，最后将那个节点旋转至根节点

- 复杂度
    - 插入：$O(logn)$ 最好$O(1)$ 最坏$O(n)$
    - 删除：$O(logn)$ 最好$O(1)$ 最坏$O(n)$
    - 查找：$O(logn)$ 最好$O(1)$ 最坏$O(logn)$

### 2. 设计测例的思路
#### 随机生成
给定数据的大小n，先随机生成n/2个插入的数据，并且确保没有重复的，后面n/2个随机生成插入，删除或查找的数据，确保插入不重复，删除的节点存在
```c++
    cout << n << endl;
    for (int i = 0; i < n / 2; i++) {
        int x = insert(0, M);
        cout << "A " << x << endl;
    }
    for (int i = 0; i < n / 2; i++) {
        int kind = rand() % 3;
        if (kind == 0) {
            int x = insert(0, M); // 随机返回一个[0,M)内可插入的值
            cout << "A " << x << endl;
        } else if (kind == 1) {
            int x = remove(0, M); // 随机返回一个[0,M)内可删除的值
            cout << "B " << x << endl;
        } else {
            int x = find(0, M);  // 随机返回一个[0,M)内的数
            cout << "C " << x << endl;
        }
    }
```

#### 一定局部性
给定组数和组的大小，每一组的元素限制在一个范围里，组与组之间不相交，先生成一半的插入数据，后面一半随机查找，没有考虑删除时因为删除和插入可以看作是等价的，在随机性和局部性方面。

#### 一定局部性+顺序
在上述一定局部性的基础上加上一个条件，每一组中的元素都是按顺序排的。
```c++
    cout << 2 * m * num << endl; // m是组数一半
    for (int i = 0; i < m; i++) {
        int a = group[i];
        int b = a + num * 10;
        vector<int> tmp;
        for (int j = 0; j < num; j++)
            tmp.push_back(insert(a, b));
        if (order)
            sort(tmp.begin(), tmp.end());
        for (int j = 0; j < num; j++)
            cout << "A " << tmp[j] << endl;
    }
    // 和上面一样，知识insert变为find
```

### 3. 测例如何生成
#### 随机生成
通过命令行参数输入数据集n的大小，比如
```shell
g++ randin.cpp -o randin
./randin 1000000
```
#### 一定局部性
通过命令行参数输入组数和每组的大小，比如
```shell
g++ randin.cpp -o randin
./randin 1000 100 #1000组，每组100个元素
```
#### 一定局部性+顺序
通过命令行参数输入组数和每组的大小，以及一个1表示有序，比如
```shell
g++ randin.cpp -o randin
./randin 1000 100 1 #1000组，每组100个元素，每组元素有序
```
### 4. 不同数据结构在不同测例下的性能描述及原因分析
#### 随机生成
这种情况下，avl的表现更好
| n       | avl     | splay   |
| ------- | ------- | ------- |
| 10000   | 5 ms    | 6 ms    |
| 100000  | 59 ms   | 76 ms   |
| 1000000 | 1223 ms | 1556 ms |

AVL 树在保持平衡性方面更为稳定，不容易出现极端的不平衡情况。Splay 树在随机生成的测试用例中性能相对较差的原因可能是由于其伸展操作导致了频繁的树重构，而且由于是随机生成，树的结构可能更加复杂，不容易通过伸展操作进行高效的调整。
#### 一定局部性
(m是组数，num是每组的大小)
| m,num     | avl    | splay   |
| --------- | ------ | ------- |
| 100,1000  | 45 ms  | 58 ms   |
| 100,10000 | 837 ms | 1102 ms |
| 1000, 100 | 46 ms  | 60 ms   |
| 1000,1000 | 926 ms | 1246 ms |
| 10000.100 | 942 ms | 1288 ms |

在具有一定局部性的测试用例中，AVL 树依然表现较好，因为 AVL 树在维持平衡性方面更为稳定。局部性的存在可以降低 Splay 树的性能劣势，但由于 AVL 树在一般情况下具有更为一致的性能，其相对优势仍然明显。
#### 一定局部性+顺序
| m,num     | avl    | splay   |
| --------- | ------ | ------- |
| 100,1000  | 40 ms  | 30 ms   |
| 100,10000 | 450 ms | 352 ms  |
| 1000, 100 | 44 ms  | 46 ms   |
| 1000,1000 | 650 ms | 702 ms  |
| 10000.100 | 830 ms | 1014 ms |

Splay 树在局部性更强、数据有序的情况下开始显示出优势，特别是在组数较小的情况下。由于 Splay 树的伸展操作适应局部性和有序性，因此性能相对提高。

然而，当组数变大时，AVL 树仍然保持相对较好的性能。这可能是因为 AVL 树能够在平衡性方面更为稳定，随着组数的增加，Splay 树的频繁伸展操作可能会导致性能相对减弱，而 AVL 树的平衡性能仍然能够维持在较高水平。
