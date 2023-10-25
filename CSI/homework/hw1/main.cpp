#include<iostream>
using namespace std;

bool checkAddOF(int si1, int si2, int* sum) {
    unsigned usum = (unsigned)si1 + si2;
    const unsigned int MY_INT_MIN = 1 << 31;
    cout << usum << endl;
    if ((usum ^ si1) & MY_INT_MIN)
        return true;
    *sum = si1 + si2;
    return false;
}

int main() {
    int a, b, s = 0;
    cin >> a >> b;
    bool c = checkAddOF(a, b, &s);
    cout << "overflow: " << c << endl;
    cout << "sum: " << s << endl;
    return 0;
}
