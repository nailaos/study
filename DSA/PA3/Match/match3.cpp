#include <iostream>
#include <cstdio>
using namespace std;

#define N 800001

unsigned long long SEED = 31;
unsigned long long MOD = 1000000000000002493;
unsigned long long seeds[800001] = { 0 };

int n, m, num;
int root;
int father[N], child[N][2], size[N];
bool lazy[N];
unsigned long long value[N][2];
int c[N];

void update(int x) {

}

bool isR(int x) {
    return x == child[father[x]][1];
}

void clear(int x) {
    child[x][0] = child[x][1] = father[x] = 0;
    value[x][0] = value[x][1] = c[x] = 0;
    lazy[x] = false;
}

int buildTree(int from, int to, int fa, string& str) {
    if (from > to)
        return;
    int mid = (from + to) / 2;
    int cur = ++num;
    c[cur] = str[mid] - 96;
    father[cur] = fa;
    child[cur][0] = buildTree(from, mid - 1, cur, str);
    child[cur][1] = buildTree(mid + 1, to, cur, str);
    update(cur);
    return cur;
}

void rotate(int x) {
    int p = father[x], g = father[p];
    int chkind = isR(x);
    child[p][chkind] = child[x][1 - chkind];
    if (child[x][1 - chkind])
        father[child[x][1 - chkind]] = p;
    child[x][1 - chkind] = p;
    father[p] = x;
    father[x] = g;
    if (g)
        child[g][child[g][isR(p)]] = x;
    update(p);
    update(x);
}

void splay(int x, int goal = 0) {
    if (goal == 0)
        root = x;
    while (father[x] != goal) {
        int p = father[x];
        int g = father[p];
        if (g != goal) {
            if (isR(p) == isR(x))
                rotate(p);
            else
                rotate(x);
        }
        rotate(x);
    }
}

void tagrev(int x) {
    swap(value[x][0], value[x][1]);
    swap(child[x][0], child[x][1]);
    lazy[x] ^= 1;
}

void lazydown(int x) {
    if (lazy[x]) {
        tagrev(child[x][0]);
        tagrev(child[x][1]);
        lazy[x] = 0;
    }
}

int findNode(int x) {

}

void insertNode(int x, char c) {

}

void removeNode(int x) {

}

void reverseNodes(int x, int y) {

}

void isequal(int x, int y, int len) {

}

void solve(int a) {
    int x, y;
    int len;
    char c;
    switch (a) {
        case 1: {
                scanf(" %d %c", &x, &c);
                insertNode(x, c);
                break;
            }
        case 2: {
                scanf(" %d", &x);
                removeNode(x);
                break;
            }
        case 3: {
                scanf(" %d %d", &x, &y);
                reverseNodes(x, y);
                break;
            }
        case 4: {
                scanf(" %d %d %d", &x, &y, &len);
                isequal(x, y, len);
                break;
            }
        default:
            break;
    }
}

void init() {
    scanf("%d %d", &n, &m);
    seeds[0] = 1;
    for (int i = 1; i <= m + n; i++) {
        seeds[i] = (SEED * seeds[i - 1]) % MOD;
    }
    if (n) {
        string str;
        cin >> str;
        buildTree(0, n - 1, 0, str);
    }
}

int main() {
    init();
    for (int i = 0; i < m; i++) {
        int a;
        scanf("%d", &a);
        solve(a);
    }
    printf("\n");
    return 0;
}