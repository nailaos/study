#include <iostream>
#include <stdio.h>
using namespace std;

void merge(int *num, int lo, int mi, int hi) {
    int i = 0;
    int *A = num + lo;
    int j = 0, lb = mi - lo;
    int *B = new int[lb];
    for (int k = 0; k < lb; k++)
        B[k] = A[k];
    int m = 0, lc = hi - mi;
    int *C = num + mi;
    while (j < lb && m < lc)
        A[i++] = (B[j] <= C[m]) ? B[j++] : C[m++];
    while (j < lb)
        A[i++] = B[j++];
    delete[] B;
}

void mergeSort(int *num, int lo, int hi) {
    if (hi - lo < 2)
        return;
    int mi = (hi + lo) >> 1;
    mergeSort(num, lo, mi);
    mergeSort(num, mi, hi);
    merge(num, lo, mi, hi);
}

int binarySearch(int *num, int lo, int hi, int target) {
    int result = -1;
    while (lo <= hi) {
        int m = (hi + lo) >> 1;
        if (num[m] < target) {
            result = m;
            lo = m + 1;
        } else {
            hi = m - 1;
        }
    }
    return result + 1;
}

int main() {
    int n;
    scanf("%d", &n);
    int *days = new int[n];
    int *ans = new int[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &days[i]);
    ans[0] = 0;
    unsigned int tmp;
    int last = 0;
    scanf("%d", &tmp);
    for (int i = 1; i < n; i++) {
        scanf("%d", &tmp);
        if (days[i - 1] >= ans[i - 1]) {
            ans[i] = days[i - 1];
            last = i - 1;
            continue;
        }
        if (tmp <= 1000000)
            last = max(last, i - (int)tmp);
        for (int j = i - 2; j >= last; j--) {
            if (days[j] < days[j + 1])
                days[j] = days[j + 1];
            else
                break;
        }
        ans[i] = days[last];
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
    mergeSort(ans, 0, n);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        unsigned int a, b;
        scanf("%d %d", &a, &b);
        if (a >= 2000000)
            cout << n << " " << 0 << endl;
        else if (b >= 2000000) {
            int x = binarySearch(ans, 0, n - 1, a);
            cout << x << " " << n - x << endl;
        } else {
            int x = binarySearch(ans, 0, n - 1, a);
            int y = binarySearch(ans, 0, n - 1, b) - x;
            cout << x << " " << y << endl;
        }
    }
    return 0;
}
