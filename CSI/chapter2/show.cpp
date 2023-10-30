#include <stdio.h>

#include <iomanip>
#include <iostream>
using namespace std;

void show_bytes(unsigned char *start, size_t len) {
    int i;
    for (i = len - 1; i >= 0; i--)
        printf("%.2x  ", start[i]);
    printf("\n");
}

void show_binary(unsigned char *start, size_t len) {
    for (int i = len - 1; i >= 0; i--) {
        for (int j = 7; j >= 0; j--) {
            int tmp = (start[i] >> j) & 1;
            cout << tmp;
        }
        cout << " ";
    }
    cout << endl;
}

template <typename T> void show(T x) {
    show_bytes((unsigned char *)&x, sizeof(T));
    show_binary((unsigned char *)&x, sizeof(T));
}

void differences_char_uchar() {
    char a = 'a';
    unsigned char b = 'x';
    cout << "differences between char and unsigned char" << endl;
    cout << (int)a << "\n" << (int)b << endl;
    show(a);
    show(b);
}

int main() {
    float a = 63.875;
    float b = 0.875;
    double x = 9999999999.99;
    double x1 = 999999999999;
    long long int y = 999999999999;
    long long int z = 10000000000;
    cout << a << endl;
    show(a);
    cout << b << endl;
    show(b);
    cout << fixed << setprecision(2) << x << endl;
    show(x);
    cout << x1 << endl;
    show(x1);
    cout << y << endl;
    show(y);
    cout << z << endl;
    show(z);
    differences_char_uchar();
    return 0;
}
