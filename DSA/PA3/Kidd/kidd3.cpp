#include <cstdio>
#include <iostream>
#include<iomanip>
using namespace std;

struct Range {
    int start;
    int end;
};

int n;
long long int* seg;
int* lens;
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

int binarySearch(int* num, int target, int from, int to) {
    int result = 0;
    while (from <= to) {
        int mid = (from + to) >> 1;
        if (num[mid] <= target) {
            result = mid + 1;
            from = mid + 1;
        } else {
            to = mid - 1;
        }
    }
    return result;
}

int removeCommon(int* num, int len) {
    int slow = 0;
    for (int i = 1; i < len; i++)
        if (num[i] != num[slow]) {
            slow++;
            num[slow] = num[i];
        }
    slow--;
    return slow;
}

void init(Range* ranges, bool* h, int m) {
    lens = new int[6 * m];
    for (int i = 0; i < m; i++) {
        char c;
        scanf(" %c %d %d", &c, &ranges[i].start, &ranges[i].end);
        lens[6 * i] = ranges[i].start;
        lens[6 * i + 1] = ranges[i].end;
        lens[6 * i + 2] = ranges[i].start + 1;
        lens[6 * i + 3] = ranges[i].end + 1;
        lens[6 * i + 4] = ranges[i].start - 1;
        lens[6 * i + 5] = ranges[i].end - 1;
        h[i] = (c == 'H');
    }
    quickSort(lens, 0, 6 * m - 1);
    n = removeCommon(lens, 6 * m);
    for (int i = 0; i < m; i++) {
        ranges[i].start = binarySearch(lens, ranges[i].start, 0, n - 1);
        ranges[i].end = binarySearch(lens, ranges[i].end, 0, n - 1);
    }
    seg = new long long[4 * n];
    lazy = new int[4 * n];
}

void dealLazy(int x, int start, int end) {
    int l = 2 * x;
    int r = 2 * x + 1;
    int mid = (start + end) / 2;
    seg[l] += lazy[x] * (lens[mid] - lens[start] + 1);
    seg[r] += lazy[x] * (lens[end] - lens[mid + 1] + 1);
    lazy[l] += lazy[x];
    lazy[r] += lazy[x];
    lazy[x] = 0;
}

void printTree(int from, int to, int x) {
    cout << setw(2) << x << " Range: [" << from << ", "
        << to << "]  Value: " << seg[x]
        << " Lazy: " <<
        lazy[x] << " Len: [" << lens[from] << ", " << lens[to] << "] (" << lens[to] - lens[from] + 1 << ")\n";
    if (from != to) {
        int mid = (from + to) / 2;
        printTree(from, mid, 2 * x);
        printTree(mid + 1, to, 2 * x + 1);
    }
}

void updateTree(int from, int to, int start, int end, int x) {
    if (from <= start && end <= to) {
        seg[x] += lens[end] - lens[start] + 1;
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
            printTree(1, n, 1);
        } else {
            long long int ans = searchTree(from, to, 1, n, 1);
            printf("%lld\n", ans);
            printTree(1, n, 1);
        }
    }
    delete[] ranges;
    delete[] seg;
    delete[] lens;
    delete[] lazy;
    delete[] h;
}
