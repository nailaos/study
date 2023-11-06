#include <cassert>
#include <cmath>
#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    assert(1 <= n && n <= 1000000);
    for (int i = 0; i < n; i++) {
        int day;
        scanf("%d", &day);
        assert(day <= 2000000);
    }
    unsigned int last;
    scanf("%u", &last);
    for (int i = 1; i < n; i++) {
        unsigned int m;
        scanf("%u", &m);
        assert(m >= 1 && m <= last + 1);
        last = m;
    }
    int t;
    scanf("%d", &t);
    assert(t <= 100000);
    for (int i = 0; i < t; i++) {
        unsigned int p, q;
        scanf("%u %u", &p, &q);
        assert(p >= 0 && p < q);
    }
}
