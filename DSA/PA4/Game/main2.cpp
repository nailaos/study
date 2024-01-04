#include <iostream>
#include <cstdio>
using namespace std;

int n, m, N = 1;
int MOD = 1e9 + 7;
int nodes[100001];
int side[100001][2];
int nums[100001];
int dis[100001];
int PQ[100001] = { 0 };
int step[100001] = { 0 };
bool visit[100001];
int** adj;

void myPush(int x) {
    PQ[N] = x;
    N++;
}

int myPop() {
    int res = INT32_MAX;
    int locate = 0;
    for (int i = 0; i < N; i++)
        if (dis[PQ[i]] < res) {
            res = dis[PQ[i]];
            locate = i;
        }
    res = PQ[locate];
    N--;
    swap(PQ[locate], PQ[N]);
    return res;
}

void init() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &nodes[i]);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &side[i][0], &side[i][1]);
        nums[side[i][0] - 1]++;
        nums[side[i][1] - 1]++;
    }
    adj = new int* [n];
    for (int i = 0; i < n; i++) {
        adj[i] = new int[nums[i] + 1];
        adj[i][0] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a = side[i][0];
        int b = side[i][1];
        adj[a - 1][0]++;
        adj[b - 1][0]++;
        adj[a - 1][adj[a - 1][0]] = b - 1;
        adj[b - 1][adj[b - 1][0]] = a - 1;
    }
    dis[0] = 0;
    step[0] = 1;
    for (int i = 1; i < n; i++)
        dis[i] = INT32_MAX;
}

int main() {
    init();
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
    printf("%d\n", dis[n - 1] + nodes[n - 1]);
    printf("%d\n", step[n - 1]);
    for (int i = 0; i < n; i++)
        delete[] adj[i];
    delete[] adj;
}