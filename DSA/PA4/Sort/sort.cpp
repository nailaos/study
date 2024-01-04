#include "sort.h"
#include <cstdio>

int arr[1000001];
int num[4] = { 0 };
int order[4] = { 0,1,2,3 };

inline void swap(int& a, int& b) {
    int t = a;
    a = b, b = t;
}

inline int Min(int a, int b) {
    if (a > b)
        return b;
    return a;
}

void com(int n, int* a) {
    int max, min;
    compare(arr[num[order[0]]], arr[num[order[1]]], arr[num[order[2]]], &max, &min);
    if (max != min) {
        int tmp[3] = { 0 };
        for (int i = 0; i < 3; i++) {
            if (arr[num[order[i]]] == min) {
                tmp[0] = order[i];
            } else if (arr[num[order[i]]] == max) {
                tmp[2] = order[i];
            } else {
                tmp[1] = order[i];
            }
        }
        for (int i = 0; i < 3; i++)
            order[i] = tmp[i];
    }
    if (n > 3)
        swap(order[2], order[3]);
}

bool compare(int x, int y, int* a) {
    int max, min;
    compare(arr[x], arr[y], arr[y], &max, &min);
    return max == arr[y];
}

void merge(int lo, int x, int y, int z, int hi, int* a) {
    for (int i = 0; i < hi - lo; i++)
        arr[i] = a[i + lo];
    int end[4] = { x - lo, y - lo, z - lo, hi - lo };
    num[0] = 0;
    num[1] = x - lo;
    num[2] = y - lo;
    num[3] = z - lo;
    int n = 0;
    if (x > lo) {
        order[n] = 0;
        n++;
    }
    if (y > x) {
        order[n] = 1;
        n++;
    }
    if (z > y) {
        order[n] = 2;
        n++;
    }
    if (hi > z) {
        order[n] = 3;
        n++;
    }

    int start = lo;
    if (n == 4)
        com(n, a);
    while (n > 2) {
        com(n, a);
        a[start] = arr[num[order[0]]];
        start++;
        num[order[0]]++;
        if (num[order[0]] == end[order[0]]) {
            n--;
            order[0] = order[n];
        }
    }
    while (num[order[0]] < end[order[0]] && num[order[1]] < end[order[1]]) {
        if (compare(num[order[0]], num[order[1]], a)) {
            a[start] = arr[num[order[0]]];
            start++;
            num[order[0]]++;
        } else {
            a[start] = arr[num[order[1]]];
            start++;
            num[order[1]]++;
        }
    }
    if (num[order[0]] == end[order[0]])
        order[0] = order[1];
    int t = num[order[0]];
    while (start < hi) {
        a[start] = arr[t];
        start++;
        t++;
    }
}

void merge_sort(int lo, int hi, int* a) {
    if (hi - lo < 2)
        return;
    int mid = (hi + lo) / 2;
    int midl = (lo + mid) / 2;
    int midr = (mid + hi) / 2;
    merge_sort(lo, midl, a);
    merge_sort(midl, mid, a);
    merge_sort(mid, midr, a);
    merge_sort(midr, hi, a);

    merge(lo, midl, mid, midr, hi, a);
}

void sort(int n, int limit, int* a) {
    return merge_sort(0, n, a);
}