#include <iostream>
#include <iomanip>
#include <windows.h>
#include "show.h"
using namespace std;

int A[10];
int B[10];
int C[10];
int a, b, c;
int step = 1;
bool show;
static int delay;

int minusPillars(char x);

void addPillars(char x, int tar);

void printSymbol(int n, char x);

void callPause() {
    cct_gotoxy(50, 32);
    system("pause");
}

void printStep(char x, char z) {
    cct_gotoxy(14, 30);
    int tmp[3] = { A[a - 1],B[b - 1],C[c - 1] };
    cout << "第" << setw(4) << step << " 步(" << setw(2) << setfill('#') << left << tmp[x - 'A'] << "): " << x
        << "-->" << z << " ";
    if (show) {
        cout << "A:";
        for (int i = 0; i < a; i++)
            cout << setw(2) << setfill(' ') << right << A[i];
        printSymbol(2 * (10 - a), ' ');
        cout << "B:";
        for (int i = 0; i < b; i++)
            cout << setw(2) << setfill(' ') << right << B[i];
        printSymbol(2 * (10 - b), ' ');
        cout << "C:";
        for (int i = 0; i < c; i++)
            cout << setw(2) << setfill(' ') << right << C[i];
    }
    if (!delay)
        callPause();
}

void printPillars() {
    int l = 3;
    int r = 22;
    cct_gotoxy(l, r);
    cout << "  A";
    printSymbol(9, ' ');
    cout << "B";
    printSymbol(9, ' ');
    cout << "C";
    r--;
    cct_gotoxy(l, r);
    printSymbol(25, '=');
    int i = 0, j = 0, k = 0;
    while (i < a || j < b || k < c) {
        r--;
        cct_gotoxy(l, r);
        cout << ' ';
        if (i < a) {
            cout << setw(2) << setfill(' ') << right << A[i];
            i++;
        } else
            cout << "  ";
        printSymbol(8, ' ');
        if (j < b) {
            cout << setw(2) << setfill(' ') << right << B[j];
            j++;
        } else
            cout << "  ";
        printSymbol(8, ' ');
        if (k < c) {
            cout << setw(2) << setfill(' ') << right << C[k];
            k++;
        }
    }
    if (!delay)
        callPause();
}

void movePillars(char x, char z) {
    printStep(x, z);
    printPillars();
    int tmp = minusPillars(x);
    int cols[3] = { 4, 14, 24 };
    int rows[3] = { 20 - a,20 - b,20 - c };
    int xr = rows[x - 'A'];
    int xl = cols[x - 'A'];
    int zr = rows[z - 'A'];
    int zl = cols[z - 'A'];
    cct_gotoxy(xl, xr);
    if (delay)
        Sleep(10 * delay);
    cout << "  ";
    addPillars(z, tmp);
    cct_gotoxy(zl, zr);
    if (delay)
        Sleep(10 * delay);
    cout << setw(2) << tmp;
    if (delay)
        Sleep(10 * delay);
    cct_cls();
}

void move(int n, char x, char y, char z) {
    if (n == 1) {
        movePillars(x, z);
        step++;
    } else {
        move(n - 1, x, z, y);
        movePillars(x, z);
        step++;
        move(n - 1, y, x, z);
    }
}

void init(char x, int n) {
    switch (x) {
        case 'A': {
                a = n;
                for (int i = n; i > 0; i--)
                    A[n - i] = i;
                break;
            }
        case 'B': {
                b = n;
                for (int i = n; i > 0; i--)
                    B[n - i] = i;
                break;
            }
        case 'C': {
                c = n;
                for (int i = n; i > 0; i--)
                    C[n - i] = i;
                break;
            }
        default:
            return;
    }
    cct_cls();
}

int main() {
    int n;
    char x, y, z;
    cout << "请输入汉诺塔的层数(1-10):" << endl;
    cin >> n;
    cout << "请输入起始柱(A-C):" << endl;
    cin >> x;
    cout << "请输入目标柱(A-C):" << endl;
    cin >> z;
    y = (char)(3 - (x - 'A') - (z - 'A') + 'A');
    cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
    cin >> delay;
    delay = 100;
    cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
    cin >> show;
    init(x, n);
    move(n, x, y, z);
}

int minusPillars(char x) {
    switch (x) {
        case 'A':
            a--;
            return A[a];
        case 'B':
            b--;
            return B[b];
        case 'C':
            c--;
            return C[c];
        default:
            return -1;
    }
}

void addPillars(char x, int tar) {
    switch (x) {
        case 'A':
            A[a] = tar;
            a++;
            break;
        case 'B':
            B[b] = tar;
            b++;
            break;
        case 'C':
            C[c] = tar;
            c++;
            break;
        default:
            return;
    }
}

void printSymbol(int n, char x) {
    for (int i = 0; i < n; i++)
        cout << x;
}