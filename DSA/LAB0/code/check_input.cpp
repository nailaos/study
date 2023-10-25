#include<cstdio>
#include<cassert>
#include<cmath>
int matrix[2000][2000];
int main() {
    int n, m, q;
    scanf("%d%d", &n, &m);
    assert(1 <= n && n <= 2000);
    assert(1 <= m && m <= 2000);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &matrix[i][j]);
            assert(abs(matrix[i][j] <= 100000));
        }
    }
    scanf("%d", &q);
    assert(q <= 100000);
    int sum = 0;
    for (int i = 1; i <= q; ++i) {
        int x, y, a, b;
        scanf("%d %d %d %d", &x, &y, &a, &b);
        assert(1 <= x && x <= n);
        assert(1 <= y && y <= m);
        assert(1 <= a && a <= n - x + 1);
        assert(1 <= b && b <= m - y + 1);
    }
    return 0;
}