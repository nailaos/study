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
    cin >> n;
    int *days = new int[n];
    int *ans = new int[n];
    for (int i = 0; i < n; i++)
        cin >> days[i];
    ans[0] = 0;
    long long int tmp;
    cin >> tmp;
    for (int i = 1; i < n; i++) {
        cin >> tmp;
        long long int target = i - tmp;
        if (target < 0)
            target = 0;
        if (days[i - 1] > days[i - 2]) {
            for (int j = i - 2; j >= target; j--) {
                if (days[j] >= days[j + 1])
                    break;
                days[j] = days[j + 1];
            }
        }
        ans[i] = days[target];
    }
    mergeSort(ans, 0, n);
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        unsigned int a, b;
        cin >> a >> b;
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
