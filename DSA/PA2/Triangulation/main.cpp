#include <cstdio>
#include<iostream>
using namespace std;

struct Point {
    int x;
    int y;
    char line;

    Point() {
        x = 0;
        y = 0;
        line = ' ';
    }
};

void dealPrint(int a1, int a2, int b1, int b2, int c1, int c2) {
    if (a1 < b1) {
        swap(a1, b1);
        swap(a2, b2);
    }
    if (b1 < c1) {
        swap(b1, c1);
        swap(b2, c2);
    }
    if (a1 < b1) {
        swap(a1, b1);
        swap(a2, b2);
    }
    printf("%d %d %d %d %d %d\n", a1, a2, b1, b2, c1, c2);
}

void quickSort(Point* points, int l, int r) {
    if (l >= r)
        return;
    int a = l, b = r, tmp = points[(l + r) / 2].x;
    while (a <= b) {
        while (points[b].x > tmp)
            b--;
        while (points[a].x < tmp)
            a++;
        if (a <= b) {
            swap(points[a], points[b]);
            a++;
            b--;
        }
    }
    if (l < b)
        quickSort(points, l, b);
    if (a < r)
        quickSort(points, a, r);
}

bool isReflex(const Point& a, const Point& b, const Point& c) {
    long long int a1 = b.x - a.x;
    long long int b1 = b.y - a.y;
    long long int a2 = c.x - a.x;
    long long int b2 = c.y - a.y;
    long long int ans = a2 * b1 - a1 * b2;
    if (a.line == '1')
        ans = -ans;
    if (ans <= 0)
        return true;
    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    Point* points = new Point[n];
    scanf("%d %d", &points[0].x, &points[0].y);
    points[0].line = '3';
    int last = points[0].x;
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
        points[i].line = points[i].x > last ? '1' : '2';
        last = points[i].x;
    }
    quickSort(points, 0, n - 1);
    points[n - 1].line = '3';

    Point* sta = new Point[n];
    sta[0] = points[0];
    sta[1] = points[1];
    int sp = 2;
    int lines[2] = { 0 };
    lines[sta[1].line - '1'] = 2;

    for (int i = 2; i < n; i++) {
        int x = points[i].x;
        int y = points[i].y;
        char c = points[i].line;
        if ((!lines[0] && c == '1') || (!lines[1] && c == '2')) {
            for (int j = sp - 2; j >= 0; j--) {
                dealPrint(sta[j].x, sta[j].y, sta[j + 1].x,
                                   sta[j + 1].y, x, y);
            }
            sta[0] = sta[sp - 1];
            sta[1] = points[i];
            sp = 2;
            lines[0] = lines[1] = 1;
            continue;
        }
        if (isReflex(sta[sp - 1], sta[sp - 2], points[i])) {
            sta[sp] = points[i];
            sp++;
            lines[c - '1']++;
            continue;
        }
        while (sp >= 2 && !isReflex(sta[sp - 1], sta[sp - 2], points[i])) {
            dealPrint(sta[sp - 1].x, sta[sp - 1].y, sta[sp - 2].x,
                               sta[sp - 2].y, x, y);
            sp--;
            lines[sta[sp].line - '1']--;
        }
        sta[sp] = points[i];
        lines[c - '1']++;
        sp++;
    }
    printf("%d\n", sp);
    return 0;
}
