#include<iostream>
#include<iomanip>
#include<windows.h>
using namespace std;

#define  N_POW  112
#define  N_NUM  N_POW+1

void printRuler(const bool);

void init(int nums[N_POW][N_NUM]) {
    nums[0][0] = 1;
    nums[0][1] = 5;
    for (int i = 1; i < N_POW; i++) {
        int last = 0;
        for (int j = 1; j <= nums[i - 1][0]; j++) {
            nums[i][j] = (nums[i - 1][j] + last) / 2;
            last = (nums[i - 1][j] % 2) * 10;
        }
        nums[i][0] = nums[i - 1][0];
        if (last) {
            nums[i][0]++;
            nums[i][nums[i][0]] = 5;
        }
    }
    printRuler(1);
    for (int i = 0; i < N_POW; i++) {
        cout << "2^" << setw(4) << (-i - 1) << " : 0.";
        for (int j = 1; j <= nums[i][0]; j++)
            cout << nums[i][j];
        cout << endl;
    }
    printRuler(0);
};

void calculateNum(const int nums[N_POW][N_NUM], const char tarNum[], const int len) {
    int ans[N_NUM] = { 0 };
    for (int i = 0; i < len; i++) {
        if (tarNum[i + 1] == '1') {
            ans[0] = nums[i][0];
            int last = 0;
            for (int j = ans[0]; j > 0; j--) {
                int tmp = ans[j] + nums[i][j] + last;
                last = tmp > 9 ? 1 : 0;
                ans[j] = tmp % 10;
            }
        }
    }
    printRuler(1);
    cout << "输入数据 : ";
    for (int i = 1; i < len; i++)
        cout << tarNum[i];
    cout << endl;
    cout << "计算值 : 0.";
    for (int i = 1; i <= ans[0]; i++)
        cout << ans[i];
    cout << endl;
    printRuler(0);
}

int main() {
    int numTable[N_POW][N_NUM];
    init(numTable);
    char tarNum[N_NUM + 1] = { 0 };
    int len = 1;
    cout << "请输入一个二进制纯小数，小数点开头，小数点后不超过112位(例：.101101)" << endl;
    while (1) {
        cin.getline(tarNum, N_NUM + 1);
        if (tarNum[0] != '.') {
            cout << "不是以.开始，请重输" << endl;
            continue;
        }
        if (tarNum[1] == '\0') {
            cout << "输入数据为空，请重输" << endl;
            continue;
        }
        bool valid = true;
        for (int i = 1; i < N_NUM; i++) {
            if (tarNum[i] == '\0')
                break;
            if (tarNum[i] == '1' || tarNum[i] == '0') {
                len++;
            } else {
                cout << "输入的不是0/1，请重输" << endl;
                valid = false;
                break;
            }
        }
        if (valid)
            break;
        else
            len = 0;
    }
    calculateNum(numTable, tarNum, len);
}

void printRuler(const bool is_upper) {
    if (is_upper) {
        cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "----------- 上标尺  1         2         3         4         5         6         7         8         9         A         B         C" << endl;
        cout << "-----------123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
    } else {
        cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "-----------123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890" << endl;
        cout << "----------- 下标尺  1         2         3         4         5         6         7         8         9         A         B         C" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
}