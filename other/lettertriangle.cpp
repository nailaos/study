#include <iomanip>
#include <iostream>
using namespace std;

void printSymbol(char c, int n) {
    for (int i = 0; i < n; i++)
        cout << c;
    cout << endl;
}

// 干什么   输出以该字母为中心的字符串
void printLetter(char c, int num) {}

int main() {
    printSymbol('=', 11);
    return 0;
}
