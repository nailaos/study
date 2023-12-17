#include "feature.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <cstring>

#define debug(...) fprintf(stderr, __VA_ARGS__)

const int N = 500010;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    assert(1 <= n && n <= 500000);
    assert(1 <= m && m <= 500000);
    int* w = new int[n + 1];
    int* x = new int[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &w[i], &x[i]);
        assert(-1e9 <= w[i] && w[i] <= 1e9);
        assert(-1e3 <= x[i] && x[i] <= 1e3);
    }
    init(n, w, x);
    memset(w, 0, n * sizeof(int));
    memset(x, 0, n * sizeof(int));
    delete[] w;
    delete[] x;

    int cur = 0;
    for (int i = 0; i < m; i++) {
        char s[10];
        scanf("%s", s);
        assert(s[0] == 'W' || s[0] == 'V' || s[0] == 'C');
        if (s[0] == 'W') {
            int i, x;
            scanf("%d%d", &i, &x);
            assert(1 <= i && i <= n);
            assert(-1e9 <= x && x <= 1e9);
            modify_weight(i, x);
        }
        if (s[0] == 'V') {
            int k, x;
            scanf("%d%d", &k, &x);
            assert(1 <= k && k <= n);
            assert(-1e3 <= x && x <= 1e3);
            modify_value(k, x);
        }
        if (s[0] == 'C') {
            int k;
            scanf("%d", &k);
            assert(1 <= k && k <= n);
            long long ans = calculate(k);
            printf("%lld\n", ans);
        }
    }
}