#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

void print_char(char c, int i, int end) {
    if (i > end)
        return;
    cout << (char)(c - abs(i));
    print_char(c, i + 1, end);
}

void print_space(int n) {
    if (!n)
        return;
    cout << " ";
    print_space(n - 1);
}

void print_tower(char c, int n, int spa) {
    if ((n == 1 && spa == -1) || n == -1 && (int)c == 'A' - 1)
        return;
    print_space(spa);
    int start = 'A' - c;
    print_char(c, start, -start);
    cout << endl;
    print_tower(char(c + n), n, spa - n);
}

int main() {
    char c;
    cin >> c;
    int spa = c - 'A';
    print_tower('A', 1, spa);
    print_tower(c - 1, -1, 1);
}
