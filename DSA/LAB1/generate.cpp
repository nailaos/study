#include<iostream>
using namespace std;

int main() {
    for (int i = 0; i < 3072; i++)
        cout << (char)('A' + i % 26);
    cout << endl;
    cout << 3072 << endl;
    for (int i = 0; i < 3072; i++)
        cout << 0 << ' ' << (char)('A' + i % 26) << endl;
    return 0;
}