#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <windows.h>
using namespace std;

int A[10];
int B[10];
int C[10];
int a, b, c;
int step = 1;
bool show;
static int delay;

static HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

void cct_cls();
void cct_gotoxy(const int X, const int Y);

int pillarsTop(char x) {
    switch (x) {
        case 'A':
            return A[a - 1];
        case 'B':
            return B[b - 1];
        case 'C':
            return C[c - 1];
        default:
            return -1;
    }
}

void printStep(char x, char z) {
    cout << "enter printStep" << endl;
    cct_gotoxy(0, 30);
    cout << "第" << setw(4) << step << " 步(" << setw(2) << pillarsTop(x) << "): " << x
        << "-->" << z << " ";
}

void printPillars() {
    int r = 10;
    int l = 22;
    cct_gotoxy(r, l);
    cout << "  A         B         C  ";
    r--;
    cct_gotoxy(r, l);
    cout << "=====================";
    int i = 0, j = 0, k = 0;
    while (i < a || j < b || k < c) {

    }
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

void movePillars(char x, char z) {
    int cols[3] = { 10, 20, 30 };
    int rows[3] = { a,b,c };
    int xr = rows[x - 'A'];
    int xl = cols[x - 'A'];
    int zr = rows[z - 'A'];
    int zl = cols[z - 'A'];
    int tmp = minusPillars(x);
    cct_gotoxy(xr, xl);
    Sleep(delay);
    cout << ' ';
    Sleep(delay);
    addPillars(z, tmp);
    cct_gotoxy(zr, zl);
    cout << tmp;
    Sleep(delay);
    cct_cls();
}

void move(int n, char x, char y, char z) {
    if (n == 1) {
        printStep(x, z);
        movePillars(x, z);
    } else {
        move(n - 1, x, z, y);
        printStep(x, z);
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
    // cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
    // cin >> delay;
    // delay = 100;
    // cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
    // cin >> show;
    init(x, n);
    move(n, x, y, z);
}

void cct_cls() {
    COORD coord = { 0, 0 };
    CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
    DWORD num;

    /* 取当前缓冲区信息 */
    GetConsoleScreenBufferInfo(hout, &binfo);
    /* 填充字符 */
    FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
    /* 填充属性 */
    FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

    /* 光标回到(0,0) */
    SetConsoleCursorPosition(hout, coord);
    return;
}

void cct_gotoxy(const int X, const int Y) {
    COORD coord;
    coord.X = X;
    coord.Y = Y;
    SetConsoleCursorPosition(hout, coord);
}