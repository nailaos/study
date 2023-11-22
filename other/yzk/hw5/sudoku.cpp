#include <iostream>
using namespace std;

bool isValidSudoku(int num[9][9]) {
    for (int i = 0; i < 9; ++i) {
        bool used[10] = {false};
        for (int j = 0; j < 9; ++j) {
            int current = num[i][j];
            if (used[current])
                return false;
            used[current] = true;
        }
    }

    for (int j = 0; j < 9; ++j) {
        bool used[10] = {false};
        for (int i = 0; i < 9; ++i) {
            int current = num[i][j];
            if (used[current])
                return false;
            used[current] = true;
        }
    }

    for (int block = 0; block < 9; ++block) {
        bool used[10] = {false};
        int startRow = (block / 3) * 3;
        int startCol = (block % 3) * 3;
        for (int i = startRow; i < startRow + 3; ++i) {
            for (int j = startCol; j < startCol + 3; ++j) {
                int current = num[i][j];
                if (used[current])
                    return false;
                used[current] = true;
            }
        }
    }

    return true;
}

void init(int num[9][9]) {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            // TODO: 输入逻辑
            cin >> num[i][j];
        }
}

int main() {
    int num[9][9] = {0};
    init(num);
    if (isValidSudoku(num))
        cout << "是数独的解" << endl;
    else
        cout << "不是数独的解" << endl;
}
