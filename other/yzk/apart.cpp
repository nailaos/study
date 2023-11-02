#include <iostream>
using namespace std;

void printNum(int n) {
    if (!n)
        return;
    printNum(n / 10);
    cout << (char)('0' + n % 10) << " ";
}

void dealNum(int n) {
    if (!n)
        cout << "0 ";
    else if (n > 0)
        printNum(n);
    else {
        cout << "- ";
        printNum(n / -10);
        cout << (char)('0' - n % 10) << " ";
    }
}

int main() {
    int n;
    cin >> n;
    dealNum(n);
    cout << endl;
    return 0;
}
