#include <iostream>
#include <ctime>
using namespace std;

int N = 1000000;
#define M 1;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int n = N;
    int m = 1;
    cout << n << ' ' << m << endl;
    for (int i = 0; i < n; i++) {
        int tmp = rand() % M;
        cout << tmp << ' ';
    }
    cout << endl;
    for (int i = 0; i < m; i++) {
        cout << 2 << ' ' << 1000000 << ' ';
        for (int i = 0; i < 1000000; i++) {
            int tmp = N / 2 + rand() % (N / 2);
            cout << tmp << ' ';
        }
    }
    cout << endl;
    return 0;
}