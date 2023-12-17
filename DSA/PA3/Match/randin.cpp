#include <iostream>
#include <algorithm>
using namespace std;

#define N 1001
#define M 1001

int main(int argc, char** argv) {
    srand(time(0));
    int n = rand() % N;
    int m = rand() % M;
    cout << n << ' ' << m << endl;
    string str;
    for (int i = 0; i < n; i++)
        str.push_back(static_cast<char>('a' + std::rand() % 26));
    cout << str << endl;
    for (int i = 0; i < m; i++) {
        int kind = rand() % 4 + 1;
        cout << kind << ' ';
        switch (kind) {
            case 1: {
                    int len = str.length() + 1;
                    int pos = rand() % len;
                    char c = (char)('a' + std::rand() % 26);
                    cout << pos << ' ' << c << endl;
                    str.insert(pos, 1, c);
                    break;
                }
            case 2: {
                    int len = str.length();
                    int pos = rand() % len;
                    cout << pos << endl;
                    str.erase(pos, 1);
                    break;
                }
            case 3: {
                    int len = str.length();
                    int x = rand() % len;
                    int y = rand() % len;
                    if (x > y)
                        swap(x, y);
                    cout << x << ' ' << y << endl;
                    reverse(str.begin() + x, str.begin() + y + 1);
                    break;
                }
            case 4: {
                    int len = str.length();
                    int x = rand() % len;
                    int y = rand() % len;
                    if (x > y)
                        swap(x, y);
                    int l = y - x + 1;
                    y = rand() % len;
                    cout << x << ' ' << y << ' ' << l << endl;
                    break;
                }
            default:
                break;
        }
    }
}