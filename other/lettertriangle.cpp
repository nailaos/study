#include <cmath>
#include <iostream>
using namespace std;

void print_tower(char c, int n, int spa) {
    if ((n == 1 && spa == -1) || n == -1 && (int)c == 'A' - 1)
        return;
    for (int i = 0; i < spa; i++)
        cout << " ";
    int start = 'A' - c;
    for (int i = start; i <= -start; i++)
        cout << (char)(c - abs(i));
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
