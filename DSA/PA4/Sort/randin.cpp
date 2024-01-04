#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 1000000;
    int limit = 10300000;
    vector<int> res(n);
    for (int i = 0; i < n; i++)
        res[i] = i;
    cout << n << " " << limit << endl;
    for (int i = 0; i < n; i++)
        cout << res[i] << ' ';
    cout << endl;
    return 0;
}