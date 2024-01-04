# Game
### 1. 算法实现的思路
- 邻接表创建，先把所有边存下来，并且同时统计每个点的邻接元素的个数，根据个数动态开数组，数组的第1位表示当前元素个数，这样就可以知道新来的点放在哪里
    ```c++
    for (int i = 0; i < m; i++) {
        int a = side[i][0]; // 存储的边
        int b = side[i][1];
        adj[a - 1][0]++; // 元素个数信息
        adj[b - 1][0]++;
        adj[a - 1][adj[a - 1][0]] = b - 1; // b-1后面代码好写
        adj[b - 1][adj[b - 1][0]] = a - 1;
    }
    ```
- 查找最短路径和路径条数，先将第一个点的距离置为0，其余点为int_max，用一个step数组去记录最短路径条数，出发点为1，其余为0，用一个数组去存储距离被更新过的点，同时用一个visited数组记录访问信息，当数组非空时，先将数组中距离最小的点取出来并删除，若已被访问，continue，遍历它的邻接表，若到目标点的距离被更新，则将目标点插入到数组中，并且将它的step信息传给目标点，若距离刚好相等，说明最短路径条数需要新增一些
    ```c++
    dis[0] = 0;
    step[0] = 1;
    for (int i = 1; i < n; i++)
        dis[i] = INT32_MAX;
    while (N) {
        int x = myPop();
        if (visit[x])
            continue;
        if (x == n - 1)
            break;
        visit[x] = true;
        for (int i = 1; i <= adj[x][0]; i++) {
            int y = adj[x][i];
            int distance = dis[x] + nodes[x];
            if (distance < dis[y]) {
                dis[y] = distance;
                step[y] = step[x];
                myPush(y);
            } else if (distance == dis[y]) {
                step[y] += step[x];
                if (step[y] >= MOD)
                    step[y] %= MOD;
            }
        }
    }
    ```
### 2. 遇到的问题
- 本来想用二叉堆去优化，但是不知道为什么写的有问题，实在检查不出错误，后面直接换成了朴素实现，每次遍历寻找最小值
### 3. 时间复杂度: $O(n^2)$
### 4. 空间复杂度: $O(n)$