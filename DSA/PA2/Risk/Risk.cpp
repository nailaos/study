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

void quickSort(int *arr, int l, int r) {
    if (l >= r)
        return;
    int a = l, b = r, tmp = arr[(l + r) / 2];
    while (a <= b) {
        while (arr[b] > tmp)
            b--;
        while (arr[a] < tmp)
            a++;
        if (a <= b) {
            swap(arr[a], arr[b]);
            a++;
            b--;
        }
    }
    if (l < b)
        quickSort(arr, l, b);
    if (a < r)
        quickSort(arr, a, r);
}

inline int binarySearch0(int *num, int lo, int hi, int target) {
    int result = lo;
    if (target < num[lo])
        return lo;
    while (lo <= hi) {
        int m = (hi + lo) >> 1;
        if (num[m] <= target) {
            result = m + 1;
            lo = m + 1;
        } else {
            hi = m - 1;
        }
    }
    return result;
}

inline int binarySearch1(int *num, int lo, int hi, int target) {
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

inline int binarySearch2(int *num, int lo, int hi, int target) {
    int result = hi + 1;
    if (num[hi] > target)
        return result;
    while (lo <= hi) {
        int m = (hi + lo) >> 1;
        if (num[m] <= target) {
            result = m;
            hi = m - 1;
        } else {
            lo = m + 1;
        }
    }
    return result;
}

int main() {
    setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
    setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
    int n;
    scanf("%d", &n);
    int *days = new int[n];
    int *ans = new int[n];
    int *num = new int[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &days[i]);
    /* for (int i = 0; i < n; i++) { */
    /*     if (i && i % 15 == 0) */
    /*         cout << endl; */
    /*     cout << days[i] << " "; */
    /* } */
    /* cout << endl; */
    ans[0] = 0;
    num[0] = 0;
    int len = 0;
    int last = 0;
    unsigned int tmp;
    scanf("%d", &tmp);
    for (int i = 1; i < n; i++) {
        scanf("%d", &tmp);
        /* cout << "=================" << endl; */
        /* cout << "       " << i << endl; */
        /* cout << "last: " << last << "    len: " << len << endl; */
        /* cout << "days: "; */
        /* for (int i = 0; i <= len; i++) */
        /*     cout << days[i] << " "; */
        /* cout << endl << "num: "; */
        /* for (int i = 0; i <= len; i++) */
        /*     cout << num[i] << " "; */
        /* cout << endl << "m:       " << tmp; */
        /* cout << endl << "current: " << days[i - 1] << endl; */
        /* cout << "=================" << endl; */
        if (tmp <= 1000000 && i - (int)tmp > 0) {
            last = binarySearch0(num, last, len, i - (int)tmp);
        }
        if (days[i - 1] >= days[last]) {
            last = len = 0;
        } else {
            len = binarySearch2(days, last, len, days[i - 1]);
        }
        days[len] = days[i - 1];
        num[len] = i;
        ans[i] = days[last];
        /* cout << "ans[" << i + 1 << "]: " << ans[i] << endl; */
    }
    /* for (int i = 0; i < n; i++) */
    /*     cout << ans[i] << " "; */
    /* cout << endl; */
    quickSort(ans, 0, n - 1);
    /* for (int i = 0; i < n; i++) */
    /*     cout << ans[i] << " "; */
    /* cout << endl; */
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        unsigned int a, b;
        scanf("%d %d", &a, &b);
        if (a >= 2000000)
            cout << n << " " << 0 << endl;
        else if (b >= 2000000) {
            int x = binarySearch1(ans, 0, n - 1, a);
            cout << x << " " << n - x << endl;
        } else {
            int x = binarySearch1(ans, 0, n - 1, a);
            int y = binarySearch1(ans, 0, n - 1, b) - x;
            cout << x << " " << y << endl;
        }
    }
    return 0;
}
