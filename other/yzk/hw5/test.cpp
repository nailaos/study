#include <iostream>
#include <iomanip>
#include <cstring>
#include <Windows.h>
using namespace std;

#define N_POW	112		
#define N_NUM	N_POW+1	

void output(const char prompt[], const int d[], int i) {
    cout << prompt;
    cout << setw(4) << -i << " : 0. ";
    cout << d << endl;
}

void calc_next(int d_cur[], int d_next[], int i) {
    int j;
    int sup = 0;
    for (j = 1; j <= i + 1; j++) {
        d_next[j] = (d_cur[j] + sup * 10) / 2;
        sup = (d_cur[j] + sup * 10) % 2;
    }
}

void calc_num(char pure_decimal[], int out[], int power_table[][N_NUM + 1]) {
    for (int i = 1; i < N_NUM; i++) {
        if (pure_decimal[i] == '1') {
            for (int j = 1; j < N_NUM; j++) {
                out[j] += power_table[i][j];
            }
        }
    }
    for (int i = N_NUM; i >= 1; i--) {
        if (out[i] >= 10) {
            out[i - 1] += out[i] / 10;
            out[i] = out[i] % 10;
        }
    }
}

void output_rod(const bool is_upper) {
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

int main() {
    int power_table[N_POW + 1][N_NUM + 1] = { 0 };
    int i;

    for (i = 1; i <= N_POW; i++) {
        power_table[i][0] = -i;
    }
    power_table[1][1] = 5;

    for (i = 1; i < N_POW; i++)
        calc_next(power_table[i], power_table[i + 1], i);

    output_rod(1);

    for (i = 1; i <= N_POW; i++) {
        cout << "2^" << setw(4) << power_table[i][0] << " : 0.";
        for (int j = 1; j <= i; j++)
            cout << power_table[i][j];
        cout << endl;
    }

    output_rod(0);
    cout << endl;

    char pure_decimal[N_NUM + 1] = { 0 };
    cout << "请输入一个二进制纯小数，小数点开头，小数点后不超过112位(例：.101101)" << endl;
    while (1) {
        cin.getline(pure_decimal, 114);
        if (pure_decimal[0] != '.' || pure_decimal[1] == '\0' || pure_decimal[0] == '\n') {
            cout << "??????.???????????" << endl;
            continue;
        }
        bool valid = 0;
        int temp;
        for (int k = 1; k < N_NUM; k++) {
            if (pure_decimal[k] == 0)
                continue;
            else
                temp = pure_decimal[k] - 48;
            if (temp != 0 && temp != 1)
                valid = 1;
            else
                continue;
        }
        if (valid) {
            cout << "????????0/1????????" << endl;
            continue;
        } else
            break;
    }
    cout << endl;

    output_rod(1);


    int out[N_NUM + 1] = { 0 };
    calc_num(pure_decimal, out, power_table);
    cout << "输入数据 : ";
    int index;
    for (index = N_NUM; index >= 0; index--) {
        if (pure_decimal[index] == 0 || pure_decimal[index] == '0')
            continue;
        else
            break;
    }
    for (int i = 1; i <= index; i++)
        cout << pure_decimal[i];
    cout << endl;


    cout << "计算值 : 0.";
    int len = strlen(pure_decimal);

    for (int i = 1; i <= index; i++)
        cout << out[i];

    cout << endl;

    output_rod(0);

    cout << endl;
    return 0;
}
