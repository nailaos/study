#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;

struct Range {
    int start;
    int end;
};

int n, m;
Range* ranges;
long long int* seg;
short* lazy;
bool* h;

void init() {
    scanf("%d %d", &n, &m);
    ranges = new Range[m];
    h = new bool[m];
    int numMax = 0;
    int numMin = 2147483647;
    for (int i = 0; i < m; i++) {
        char c;
        int a, b;
        scanf(" %c %d %d", &c, &a, &b);
        numMax = max(numMax, b);
        numMin = min(numMin, a);
        ranges[i].start = a;
        ranges[i].end = b;
        h[i] = (c == 'H');
    }
    numMin--;
    n = numMax - numMin;
    for (int i = 0; i < m; i++) {
        ranges[i].start -= numMin;
        ranges[i].end -= numMin;
    }
    seg = new long long[4 * n + 1];
    lazy = new short[4 * n + 1];
}

void dealLazy(int x, int start, int end) {
    int l = 2 * x;
    int r = 2 * x + 1;
    int mid = (start + end) / 2;
    seg[l] += lazy[x] * (mid - start + 1);
    seg[r] += lazy[x] * (end - mid);
    lazy[l] += lazy[x];
    lazy[r] += lazy[x];
    lazy[x] = 0;
}

void printTree(int from, int to, int x) {
    cout << setw(2) << x << " Range: [" << from << ", "
        << to << "]  Value: " << seg[x]
        << " Lazy: " <<
        lazy[x] << " Len: [" << from << ", " << to << "] (" << to - from + 1 << ")\n";
    if (from != to) {
        int mid = (from + to) / 2;
        printTree(from, mid, 2 * x);
        printTree(mid + 1, to, 2 * x + 1);
    }
}

void updateTree(int from, int to, int start, int end, int x) {
    if (from <= start && end <= to) {
        seg[x] += end - start + 1;
        lazy[x]++;
        return;
    }
    int mid = (start + end) / 2;
    if (lazy[x] && start != end)
        dealLazy(x, start, end);
    if (from <= mid)
        updateTree(from, to, start, mid, 2 * x);
    if (mid < to)
        updateTree(from, to, mid + 1, end, 2 * x + 1);
    seg[x] = seg[2 * x] + seg[2 * x + 1];
}

long long int searchTree(int from, int to, int start, int end, int x) {
    if (from <= start && end <= to)
        return seg[x];
    int mid = (start + end) / 2;
    if (lazy[x] && start != end)
        dealLazy(x, start, end);
    long long sum = 0;
    if (from <= mid)
        sum += searchTree(from, to, start, mid, 2 * x);
    if (mid < to)
        sum += searchTree(from, to, mid + 1, end, 2 * x + 1);
    return sum;
}

int main() {
    init();
    for (int i = 0; i < m; i++) {
        int from = ranges[i].start;
        int to = ranges[i].end;
        if (h[i]) {
            updateTree(from, to, 1, n, 1);
            printTree(1, n, 1);
        } else {
            long long int ans = searchTree(from, to, 1, n, 1);
            printf("%lld\n", ans);
            printTree(1, n, 1);
        }
    }
    delete[] ranges;
    delete[] seg;
    delete[] lazy;
    delete[] h;
}
