#include <iostream>
#include <iomanip>
#include <windows.h>
#include "show.h"
using namespace std;

int A[11];
int B[11];
int C[10];
int a, b, c;
int step = 1;
bool show;
static int delay;

int minusPillars(char x);

void addPillars(char x, int tar);

void printSymbol(int n, char x);

void callPause();

bool success();

void dealDelay();

void printStep(char x, char z) {
    cout << "从 " << (char)A[10] << " 移动到 " << (char)B[10] << "，" << "共 " << (a + b + c) << " 层，延时设置为 " << delay << "，";
    if (!show)
        cout << "不";
    cout << "显示内部数组值" << endl;
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
    dealDelay();
    cout << "  ";
    addPillars(z, tmp);
    cct_gotoxy(zl, zr);
    cout << setw(2) << tmp;
    dealDelay();

    if (!success())
        cct_cls();
    else
        callPause();
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
    A[10] = x;
    B[10] = z;
    cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
    cin >> delay;
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

void callPause() {
    cct_gotoxy(50, 32);
    system("pause");
}

bool success() {
    int tar = B[10] - 'A';
    int num[3] = { a,b,c };
    if (num[tar] == a + b + c)
        return true;
    return false;
}

void dealDelay() {
    if (delay)
        Sleep(100 * (6 - delay));
    else
        callPause();
}