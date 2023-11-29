#include <cstdio>
#include <iostream>
using namespace std;

struct Range {
    int start;
    int end;
};

int n, m;
Range *H;
Range *Q;
long long int *seg;
bool *lazy;
int lenH = 0;
int lenQ = 0;

void init() {
    scanf("%d %d", &n, &m);
    H = new Range[m];
    Q = new Range[m];
    int numMax = 0;
    int numMin = 2147483647;
    for (int i = 0; i < m; i++) {
        char c;
        int a, b;
        scanf("%c %d %d", &c, &a, &b);
        numMax = max(numMax, b);
        numMin = min(numMin, a);
        if (c == 'H') {
            H[lenH].start = a;
            H[lenH].end = b;
            lenH++;
        } else {
            Q[lenQ].start = a;
            Q[lenQ].end = b;
            lenQ++;
        }
    }
    n = numMax - numMin + 1;
    seg = new long long[n];
    lazy = new bool[n];
}

void hand() {}

void solve() {}

int main() {
    init();
    hand();
    solve();
}
