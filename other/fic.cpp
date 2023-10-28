#include <iomanip>
#include <iostream>
using namespace std;

int num = 0;

int f(int n) {
    num++;
    if (n == 1 || n == 2)
        return 1;
    return f(n - 1) + f(n - 2);
}

int main() {
    for (int i = 1; i < 47; i++) {
        int tmp = f(i);
        cout << setw(2) << setfill('0') << i << ":  " << num << endl;
        num = 0;
    }
    return 0;
}
