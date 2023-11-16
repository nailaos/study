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
    long long int ans = a1 * b2 - a2 * b1;
    if (a.line == '2')
        ans = -ans;
    if (ans <= 0)
        return true;
    return false;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    Point* points = new Point[n];
    int startValue = 1e9 + 1;
    int startPosition = 0;
    int endValue = -1e9 - 1;
    int endPosition = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
        if (points[i].x < startValue) {
            startValue = points[i].x;
            startPosition = i;
        }
        if (points[i].x > endValue) {
            endValue = points[i].x;
            endPosition = i;
        }
    }
    int a = startPosition == n - 1 ? 0 : startPosition + 1;
    int b = startPosition == 0 ? n - 1 : startPosition - 1;
    float k1 = (float)(points[a].y - points[startPosition].y) / (float)(points[a].x - points[startPosition].x);
    float k2 = (float)(points[b].y - points[startPosition].y) / (float)(points[b].x - points[startPosition].x);
    char aline = '1', bline = '2';
    if (k1 < k2) {
        aline = '2';
        bline = '1';
    }
    while (a != endPosition) {
        points[a].line = aline;
        a = (a + 1) % n;
    }
    while (b != endPosition) {
        points[b].line = bline;
        b = (b - 1 + n) % n;
    }
    quickSort(points, 0, n - 1);

    Point* sta = new Point[n];
    sta[0] = points[0];
    sta[1] = points[1];
    int sp = 2;
    int lines[2] = { 0 };
    lines[sta[1].line - '1'] = 1;

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
            sp = 1;
            lines[0] = lines[1] = 0;
        } else if (!isReflex(sta[sp - 1], sta[sp - 2], points[i])) {
            while (sp >= 2 && !isReflex(sta[sp - 1], sta[sp - 2], points[i])) {
                dealPrint(sta[sp - 1].x, sta[sp - 1].y, sta[sp - 2].x,
                                   sta[sp - 2].y, x, y);
                sp--;
                lines[sta[sp].line - '1']--;
            }
        }
        sta[sp] = points[i];
        if (i < n - 1)
            lines[c - '1']++;
        sp++;
    }
    delete[] points;
    delete[] sta;
    return 0;
}
