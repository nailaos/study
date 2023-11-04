#include <iostream>
using namespace std;

void printline(int n) {
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    cout << n << " ";
    printline(n - 1);
}

void printnum(int n) {
    if (!n)
        return;
    printnum(n - 1);
    printline(n);
}

int main() {
    int n;
    cin >> n;
    printnum(n);
    return 0;
}
