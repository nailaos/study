#include <iostream>
using namespace std;

unsigned long long SEED = 31;
unsigned long long MOD = 1000000000000002493;
unsigned long long seeds[800001] = { 0 };

string str;

void printHash() {
    int len = str.length();
    unsigned long long val2 = 0;
    for (int i = 0; i < len; i++) {
        unsigned long long c = str[i] - 96;
        val2 = (val2 + c * seeds[i]) % MOD;
    }
    unsigned long long val1 = 0;
    for (int i = 0; i < len; i++) {
        unsigned long long c = str[i] - 96;
        val1 = (val1 + c * seeds[len - i - 1]) % MOD;
    }
    cout << "val1: " << val1 << endl;
    cout << "val2: " << val2 << endl;
}

int main() {
    seeds[0] = 1;
    int* a = nullptr;
    int* b = nullptr;
    swap(a, b);
    for (int i = 1; i <= 1000; i++) {
        seeds[i] = SEED * seeds[i - 1] % MOD;
    }
    while (true) {
        cin >> str;
        if (str == "q")
            break;
        printHash();
    }
}