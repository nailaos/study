#include <cstdio>
#include <iostream>
using namespace std;

struct Range {
    int start;
    int end;
};

int n;
long long int* seg;
Range* myRanges;
int* lazy;

void quickSort(int* num, int from, int to) {
    if (from >= to)
        return;
    int a = from, b = to, tmp = num[(from + to) / 2];
    while (a <= b) {
        while (num[b] > tmp)
            b--;
        while (num[a] < tmp)
            a++;
        if (a <= b) {
            swap(num[a], num[b]);
            a++;
            b--;
        }
    }
    if (from < b)
        quickSort(num, from, b);
    if (a < to)
        quickSort(num, a, to);
}

int binarySearch(Range* num, int target, int from, int to) {
    int result = 0;
    while (from <= to) {
        int mid = (from + to) >> 1;
        if (num[mid].start <= target) {
            result = mid;
            from = mid + 1;
        } else {
            to = mid - 1;
        }
    }
    return result;
}

int removeCommon(int* num, int len) {
    int slow = 0;
    int extra = 0;
    for (int i = 1; i < len; i++)
        if (num[i] != num[slow]) {
            slow++;
            num[slow] = num[i];
            if (num[slow] != num[slow - 1] + 1)
                extra++;
        }
    n = slow + 1;
    return extra;
}

void init(Range* ranges, bool* h, int m) {
    int* lens = new int[2 * m];
    for (int i = 0; i < m; i++) {
        char c;
        scanf(" %c %d %d", &c, &ranges[i].start, &ranges[i].end);
        lens[2 * i] = ranges[i].start;
        lens[2 * i + 1] = ranges[i].end;
        h[i] = (c == 'H');
    }
    quickSort(lens, 0, 2 * m - 1);
    int extra = removeCommon(lens, 2 * m);
    myRanges = new Range[n + extra + 1];
    int x = 1;
    for (int i = 0; i < n; i++) {
        myRanges[x].start = lens[i];
        myRanges[x].end = lens[i];
        x++;
        if (i < n - 1 && lens[i] != lens[i + 1] - 1) {
            myRanges[x].start = lens[i] + 1;
            myRanges[x].end = lens[i + 1] - 1;
            x++;
        }
    }
    n += extra;
    for (int i = 0; i < m; i++) {
        ranges[i].start = binarySearch(myRanges, ranges[i].start, 1, n);
        ranges[i].end = binarySearch(myRanges, ranges[i].end, 1, n);
    }
    seg = new long long int[4 * n];
    lazy = new int[4 * n];
    delete[] lens;
}

void dealLazy(int x, int start, int end) {
    int l = 2 * x;
    int r = 2 * x + 1;
    int mid = (start + end) / 2;
    seg[l] += (long long)lazy[x] * (long long)(myRanges[mid].end - myRanges[start].start + 1);
    seg[r] += (long long)lazy[x] * (long long)(myRanges[end].end - myRanges[mid + 1].start + 1);
    lazy[l] += lazy[x];
    lazy[r] += lazy[x];
    lazy[x] = 0;
}

void updateTree(int from, int to, int start, int end, int x) {
    if (from <= start && end <= to) {
        seg[x] += (long long)(myRanges[end].end - myRanges[start].start + 1);
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
    int m;
    scanf("%d %d", &n, &m);
    Range* ranges = new Range[m];
    bool* h = new bool[m];
    init(ranges, h, m);
    for (int i = 0; i < m; i++) {
        int from = ranges[i].start;
        int to = ranges[i].end;
        if (h[i]) {
            updateTree(from, to, 1, n, 1);
        } else {
            long long int ans = searchTree(from, to, 1, n, 1);
            printf("%lld\n", ans);
        }
    }
    delete[] ranges;
    delete[] seg;
    delete[] myRanges;
    delete[] lazy;
    delete[] h;
}
