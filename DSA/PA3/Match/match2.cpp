#include <algorithm>
#include <cstdio>
const int N = 100005;

int n, m, l, r, a[N];

int rt, tot, fa[N], ch[N][2], val[N], sz[N], lazy[N];

struct Splay {
    void maintain(int x) { sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1; }

    bool get(int x) { return x == ch[fa[x]][1]; }

    void clear(int x) {
        ch[x][0] = ch[x][1] = fa[x] = val[x] = sz[x] = lazy[x] = 0;
    }

    void rotate(int x) {
        int y = fa[x], z = fa[y], chk = get(x);
        ch[y][chk] = ch[x][chk ^ 1];
        if (ch[x][chk ^ 1]) fa[ch[x][chk ^ 1]] = y;
        ch[x][chk ^ 1] = y;
        fa[y] = x;
        fa[x] = z;
        if (z) ch[z][y == ch[z][1]] = x;
        maintain(y);
        maintain(x);
    }

    void splay(int x, int goal = 0) {
        if (goal == 0) rt = x;
        while (fa[x] != goal) {
            int f = fa[x], g = fa[fa[x]];
            if (g != goal) {
                if (get(f) == get(x))
                    rotate(x);
                else
                    rotate(f);
            }
            rotate(x);
        }
    }

    void tagrev(int x) {
        std::swap(ch[x][0], ch[x][1]);
        lazy[x] ^= 1;
    }

    void pushdown(int x) {
        if (lazy[x]) {
            tagrev(ch[x][0]);
            tagrev(ch[x][1]);
            lazy[x] = 0;
        }
    }

    int build(int l, int r, int f) {
        if (l > r) return 0;
        int mid = (l + r) / 2, cur = ++tot;
        val[cur] = a[mid], fa[cur] = f;
        ch[cur][0] = build(l, mid - 1, cur);
        ch[cur][1] = build(mid + 1, r, cur);
        maintain(cur);
        return cur;
    }

    int kth(int k) {
        int cur = rt;
        while (1) {
            pushdown(cur);
            if (ch[cur][0] && k <= sz[ch[cur][0]]) {
                cur = ch[cur][0];
            } else {
                k -= 1 + sz[ch[cur][0]];
                if (k <= 0) {
                    splay(cur);
                    return cur;
                }
                cur = ch[cur][1];
            }
        }
    }

    void reverse(int l, int r) {
        int L = kth(l), R = kth(r + 2);
        splay(L), splay(R, L);
        int tmp = ch[ch[L][1]][0];
        tagrev(tmp);
    }

    void print(int x) {
        pushdown(x);
        if (ch[x][0]) print(ch[x][0]);
        if (val[x] >= 1 && val[x] <= n) printf("%d ", val[x]);
        if (ch[x][1]) print(ch[x][1]);
    }
} tree;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n + 1; i++) a[i] = i;
    rt = tree.build(0, n + 1, 0);
    while (m--) {
        scanf("%d%d", &l, &r);
        tree.reverse(l, r);
    }
    tree.print(rt);
    return 0;
}