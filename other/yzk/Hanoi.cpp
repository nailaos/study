#include <iomanip>
#include <iostream>
using namespace std;

int pillars[3][10] = { 0 };
int nums[3] = { 0 };
int step = 1;

int movePillars(int src, int tar) {
    nums[src]--;
    int tmp = pillars[src][nums[src]];
    pillars[tar][nums[tar]] = tmp;
    nums[tar]++;
    return tmp;
}

void printPillars() {
    for (int i = 0; i < 3; i++) {
        cout << (char)(i + 'A') << ":";
        for (int j = 0; j < nums[i]; j++)
            cout << setw(2) << pillars[i][j];
        for (int j = 0; j < 10 - nums[i]; j++)
            cout << "  ";
        cout << ' ';
    }
    cout << endl;
}

void move(int n, char A, char B, char C) {
    if (n == 1) {
        int tmp = movePillars(A - 'A', C - 'A');
        cout << "第" << setw(4) << step << " 步(" << setw(2) << tmp << "): " << A
            << "-->" << C << " ";
        printPillars();
        step++;
    } else {
        move(n - 1, A, C, B);
        int tmp = movePillars(A - 'A', C - 'A');
        cout << "第" << setw(4) << step << " 步(" << setw(2) << tmp << "): " << A
            << "-->" << C << " ";
        printPillars();
        step++;
        move(n - 1, B, A, C);
    }
}

void init() {
    cout << "起始:                ";
    printPillars();
}

int main() {
    int n;
    char A, B, C;
    cout << "请输入汉诺塔的层数(1-10):" << endl;
    cin >> n;
    cout << "请输入起始柱(A-C):" << endl;
    cin >> A;
    cout << "请输入目标柱(A-C):" << endl;
    cin >> C;
    nums[A - 'A'] = n;
    for (int i = n; i > 0; i--) {
        pillars[A - 'A'][n - i] = i;
    }
    B = (char)(3 - (A - 'A') - (C - 'A') + 'A');
    init();
    move(n, A, B, C);
    return 0;
}
