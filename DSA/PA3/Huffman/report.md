### Huffman

1.  ##### 解题思路

    - 先统计字符串中每个字母出现的次数，并且据此生成基础节点
      ```c++
      for (int i = 0; i < 26; i++) {
          if (num[i]) {
              nodes[len] = new Node('a' + i, num[i]);
              len++;
          }
      }
      ```
    - 生成Huffman树，每次对节点序列进行排序，然后让最小的两个节点生成一个新的节点，删除那两个节点，并且把新节点加入到节点序列中，直到节点序列长度变为1
      ```c++
      while (len > 1) {
          quickSort(nodes, 0, len - 1);
          Node* tmp = new Node(nodes[0], nodes[1]);
          for (int i = 0; i < len - 2; i++)
              nodes[i] = nodes[i + 2];
          nodes[len - 2] = tmp;
          len--;
      }
      hafTree = nodes[0];
      ```
    - 依据生成的Huffman树得到每个字母的编码，思路就是从树根开始遍历，用一个字符串记录每次进入左孩子还是右孩子，遇到叶子节点，就把那个字符串赋给对应的字母

      ```c++
      void solveTree(Node\* node, string last) {
          if (!node)
              return;
          if (node->left == nullptr && node->right == nullptr)
              ans[node->c - 'a'] = last;
          solveTree(node->left, last + "0");
          solveTree(node->right, last + "1");
      }
      ```

    - 得到文本编码长度，就是每个字母的编码长度乘字母出现的次数

      ```c++
      int textlen = 0;
      for (int i = 0; i < 26; i++)
          textlen += ans[i].length() * num[i];
      ```

2.  ##### 遇到的问题
    - 构造函数中忘了把左右孩子的值定位nullptr
3.  ##### 时间复杂度: $O(n)$
    - 统计各个字母的出现次数: $O(n)$
    - 生成树和遍历树都可以认为是在常数时间内就可以完成
4.  ##### 空间复杂度: $O(n)$
    - 主要是需要存储字符串，树的大小可认为是常数大小
