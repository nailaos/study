#include <iostream>
#include <cstdio>
using namespace std;

int music[1500001];
int len = 0;
int harmony[1500001];
int extraH[1500001];
int ques[1000001];

int testNum = 0;
int mergeNum = 0;

void quickSort(int* arr, int l, int r) {
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

void calculateHarmony(int x) {
    if (x < 2)
        return;
    int last = harmony[x - 1];
    int extraL = extraH[x - 1];
    if (last == x / 2) {
        last = extraH[last];
    }
    int h = 0;
    while (true) {
        testNum++;
        if (music[last] == music[x - 1]) {
            h = last + 1;
            break;
        }
        if (last == 0)
            break;
        last = extraH[last];
    }
    harmony[x] = h;
    h = 0;
    while (true) {
        testNum++;
        if (music[extraL] == music[x - 1]) {
            h = extraL + 1;
            break;
        }
        if (extraL == 0)
            break;
        extraL = extraH[extraL];
    }
    extraH[x] = h;
}

int mergeHarmony(int x, int y) {
    if (x < 0)
        return y;
    while (x != y) {
        mergeNum++;
        if (x > y) {
            if (x >= 2 * y)
                x = harmony[x];
            else
                x = extraH[x];
        } else {
            if (y >= 2 * x)
                y = harmony[y];
            else
                y = extraH[y];
        }
    }
    return x;
}

void test() {
    for (int i = 1; i <= len; i++)
        cout << harmony[i] << ' ';
    cout << endl;
    for (int i = 1; i <= len; i++)
        cout << extraH[i] << ' ';
    cout << endl;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &music[i]);
        calculateHarmony(i + 1);
    }
    len = n;
    //cout << testNum << " / " << len << endl;
    for (int i = 0; i < m; i++) {
        int type, num;
        scanf("%d %d", &type, &num);
        if (type == 1) {
            for (int j = 0; j < num; j++) {
                scanf("%d", &music[len]);
                len++;
                calculateHarmony(len);
            }
        } else {
            int ans = -1;
            for (int j = 0; j < num; j++) {
                scanf("%d", &ques[j]);
            }
            quickSort(ques, 0, num - 1);
            if (harmony[ques[0]] == 0) {
                printf("0\n");
                continue;
            }
            for (int j = num - 1; j >= 0; j--) {
                ans = mergeHarmony(ans, harmony[ques[j]]);
                if (ans == 0)
                    break;
            }
            printf("%d\n", ans);
        }
    }
    //cout << mergeNum << " / " << len << endl;
    return 0;
}