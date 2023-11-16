### Triangulation

- ##### 算法实现的思路
    - 用结构体表示点，加一个辅助变量记录点所处的曲线
    ```c++
    struct Point {
        int x;
        int y;
        char line;
    };
    ```
    - 处理输入，得到两个单调多边形曲线
        - 先找出开始位置和结束位置
        ```c++
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &points[i].x, &points[i].y);
            if (points[i].x < startValue) {//开始位置肯定是x坐标最小的那个
                startValue = points[i].x;
                startPosition = i;
            }
            if (points[i].x > endValue) {//结束位置肯定是x坐标最大的那个
                endValue = points[i].x;
                endPosition = i;
            }
        }
        ```
        - 依据斜率判断两条曲线的上下位置，然后写入曲线信息
        ```c++
        int a = startPosition == n - 1 ? 0 : startPosition + 1;
        int b = startPosition == 0 ? n - 1 : startPosition - 1;
        float k1 = (float)(points[a].y - points[startPosition].y) / (float)(points[a].x - points[startPosition].x);
        float k2 = (float)(points[b].y - points[startPosition].y) / (float)(points[b].x - points[startPosition].x);
        ...
        while (a != endPosition) {
            points[a].line = aline;
            a = (a + 1) % n;
        }
        while (b != endPosition) {
            points[b].line = bline;
            b = (b - 1 + n) % n;
        }
        ```
        - 排序
    - 用数组加指针模拟栈的行为，按照提供的思路解题

- ##### 遇到的问题
    - 忽略了处理输入，没有考虑输入的起点不是最左边的点以及方向不一定是顺时针

- ##### 时间复杂度: $O(nlog(n))$
    - 处理输入: $O(n)$
    - 排序: $O(nlog(n))$
    - 剖分三角形: $O(n)$

- ##### 空间复杂度: $O(n)$
    - 两个数组: $O(2n)$

