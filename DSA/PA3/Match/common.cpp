#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

unsigned long long SEED = 31;
unsigned long long MOD = 1000000000000002493;
unsigned long long seeds[800001] = { 0 };
int num;

int n, m;
string str;

void printHash() {
    int len = str.length();
    unsigned long long val2 = 0;
    for (int i = 0; i < len; i++) {
        unsigned long long c = str[i] - 96;
        val2 = (val2 + c * seeds[i + 1]) % MOD;
    }
    unsigned long long val1 = 0;
    for (int i = 0; i < len; i++) {
        unsigned long long c = str[i] - 96;
        val1 = (val1 + c * seeds[len - i]) % MOD;
    }
    // cout << "val1: " << val1 << endl;
    // cout << "val2: " << val2 << endl;
}

void insertNode(int x, char c) {
    str.insert(x, 1, c);
}

void removeNode(int x) {
    str.erase(x, 1);
}

void reverseNodes(int x, int y) {
    reverse(str.begin() + x, str.begin() + y + 1);
}

void isequal(int x, int y, int len) {
    if (str.substr(x, len) == str.substr(y, len))
        cout << "T";
    else
        cout << "F";
}

void solve(int a) {
    int x, y;
    int len;
    char c;
    switch (a) {
        case 1: {
                cin >> x >> c;
                insertNode(x, c);
                break;
            }
        case 2: {
                cin >> x;
                removeNode(x);
                break;
            }
        case 3: {
                cin >> x >> y;
                reverseNodes(x, y);
                break;
            }
        case 4: {
                cin >> x >> y >> len;
                isequal(x, y, len);
                break;
            }
        default:
            break;
    }
    //cout << '*' << str << '*' << endl;
    printHash();
    num++;
    cout << num << ": ";
    cout << str.length() << endl;
}

void init() {
    cin >> n >> m;
    if (n)
        cin >> str;
    seeds[0] = 1;
    for (int i = 1; i <= m + n; i++) {
        seeds[i] = SEED * seeds[i - 1] % MOD;
    }
}

int main() {
    init();
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        solve(a);
    }
    cout << endl;
    return 0;
}