#include <cstdio>
#include <iostream>
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
    scanf("%d", &tmp);
    for (int i = 1; i < n; i++) {
        scanf("%d", &tmp);
        int target = 0;
        if (tmp < 1000000 && i - (int)tmp > 0)
            target = i - tmp;
        int currans = 0;
        for (int j = i - 1; j >= target; j--)
            currans = max(currans, days[j]);
        ans[i] = currans;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);
    printf("\n");
    mergeSort(ans, 0, n);
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);
    printf("\n");
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        unsigned int a, b;
        scanf("%d %d", &a, &b);
        if (a >= 2000000)
            printf("%d 0\n", n);
        else if (b >= 2000000) {
            int x = binarySearch(ans, 0, n - 1, a);
            printf("%d %d\n", x, n - x);
        } else {
            int x = binarySearch(ans, 0, n - 1, a);
            int y = binarySearch(ans, 0, n - 1, b) - x;
            printf("%d %d\n", x, y);
        }
    }
    return 0;
}
