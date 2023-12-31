#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int music[100001];
int len;
int harmony[1500001];
int extraH[1500001];

void calculateHarmony(int x) {
    int ans = 0;
    for (int i = x / 2; i >= 1; i--) {
        int tmp = i;
        bool succ = true;
        while (tmp > 0) {
            if (music[tmp - 1] == music[tmp + x - i - 1])
                tmp--;
            else {
                succ = false;
                break;
            }
        }
        if (succ) {
            ans = i;
            break;
        }
    }
    harmony[x] = ans;

    ans = 0;
    for (int i = x - 1; i >= 1; i--) {
        int tmp = i;
        bool succ = true;
        while (tmp > 0) {
            if (music[tmp - 1] == music[tmp + x - i - 1])
                tmp--;
            else {
                succ = false;
                break;
            }
        }
        if (succ) {
            ans = i;
            break;
        }
    }
    extraH[x] = ans;
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
            for (int i = 0; i < num; i++) {
                int tmp;
                scanf("%d", &tmp);
            }
            printf("%d\n", ans);
        }
    }
    test();
    return 0;
}