#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

struct Range {
    int start;
    int end;
};

struct SegmentTree {
    long long int val;
    Range range;
    int lazy;
    int len;
};

int n, m;
Range *ranges;
SegmentTree *seg;
bool *h;
int len = 0;

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
        ranges[len].start = a;
        ranges[len].end = b;
        h[len] = (c == 'H');
        len++;
    }
    numMin--;
    n = numMax - numMin;
    for (int i = 0; i < len; i++) {
        ranges[i].start -= numMin;
        ranges[i].end -= numMin;
    }
    seg = new SegmentTree[4 * n];
}

void buildTree(int from, int to, int p) {
    if (from == to) {
        seg[p].range.start = from;
        seg[p].range.end = to;
        seg[p].len = 1;
        return;
    }
    seg[p].range.start = from;
    seg[p].range.end = to;
    seg[p].len = to - from + 1;
    int mid = (from + to) / 2;
    buildTree(from, mid, 2 * p);
    buildTree(mid + 1, to, 2 * p + 1);
}

void printTree() {
    for (int i = 1; i <= 2 * n; i++) {
        if (seg[i].range.start == 0)
            break;
        cout << setw(2) << i << " Range: [" << seg[i].range.start << ","
             << seg[i].range.end << "]  Value: " << seg[i].val
             << " Lazy: " << seg[i].lazy << " Len: " << seg[i].len << endl;
    }
}

void dealLazy(int p, int l, int r) {
    seg[l].val += seg[p].lazy * seg[l].len;
    seg[r].val += seg[p].lazy * seg[r].len;
    seg[l].lazy += seg[p].lazy;
    seg[r].lazy += seg[p].lazy;
    seg[p].lazy = 0;
}

void updateTree(int from, int to, int p) {
    if (from <= seg[p].range.start && seg[p].range.end <= to) {
        seg[p].val += seg[p].len;
        seg[p].lazy++;
        return;
    }
    int mid = (seg[p].range.start + seg[p].range.end) / 2;
    int l = 2 * p;
    int r = 2 * p + 1;
    if (seg[p].lazy && seg[p].len > 1)
        dealLazy(p, l, r);
    if (from <= mid)
        updateTree(from, to, l);
    if (mid < to)
        updateTree(from, to, r);
    seg[p].val = seg[l].val + seg[r].val;
}

long long int rangeSearch(int from, int to, int p) {
    if (from <= seg[p].range.start && seg[p].range.end <= to)
        return seg[p].val;
    int mid = (seg[p].range.start + seg[p].range.end) / 2;
    int l = 2 * p;
    int r = 2 * p + 1;
    if (seg[p].lazy && seg[p].len > 1)
        dealLazy(p, l, r);
    long long sum = 0;
    if (from <= mid)
        sum += rangeSearch(from, to, l);
    if (mid < to)
        sum += rangeSearch(from, to, r);
    return sum;
}

int main() {
    init();
    buildTree(1, n, 1);
    for (int i = 0; i < len; i++) {
        int from = ranges[i].start;
        int to = ranges[i].end;
        if (h[i]) {
            updateTree(from, to, 1);
            // printTree();
        } else {
            long long int ans = rangeSearch(from, to, 1);
            printf("%lld\n", ans);
            // printTree();
        }
    }
    delete[] ranges;
    delete[] seg;
    delete[] h;
}
