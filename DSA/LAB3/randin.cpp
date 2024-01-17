#include <iostream>
#include <unordered_set>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool visit[100000007];
bool order = false;
int M = 1e8 + 7;

int insert(int a, int b) {
    int tmp;
    do {
        tmp = a + rand() % b;
    } while (visit[tmp]);

    visit[tmp] = true;
    return tmp;
}

int remove(int a, int b) {
    int tmp;
    do {
        tmp = a + rand() % b;
    } while (!visit[tmp]);

    visit[tmp] = false;
    return tmp;
}

int find(int a, int b) {
    int tmp = a + rand() % b;
    return tmp;
}

void generate(int n) {
    cout << n << endl;
    for (int i = 0; i < n / 2; i++) {
        int x = insert(0, M);
        cout << "A " << x << endl;
    }
    for (int i = 0; i < n / 2; i++) {
        int kind = rand() % 3;
        if (kind == 0) {
            int x = insert(0, M);
            cout << "A " << x << endl;
        } else if (kind == 1) {
            int x = remove(0, M);
            cout << "B " << x << endl;
        } else {
            int x = find(0, M);
            cout << "C " << x << endl;
        }
    }
}

void generate(int m, int num, const vector<int>& group) {
    cout << 2 * m * num << endl;
    for (int i = 0; i < m; i++) {
        int a = group[i];
        int b = a + num * 10;
        vector<int> tmp;
        for (int j = 0; j < num; j++)
            tmp.push_back(insert(a, b));
        if (order)
            sort(tmp.begin(), tmp.end());
        for (int j = 0; j < num; j++)
            cout << "A " << tmp[j] << endl;
    }
    for (int i = 0; i < m; i++) {
        int a = group[i];
        int b = a + num * 10;
        vector<int> tmp;
        for (int j = 0; j < num; j++)
            tmp.push_back(find(a, b));
        if (order)
            sort(tmp.begin(), tmp.end());
        for (int j = 0; j < num; j++)
            cout << "C " << tmp[j] << endl;
    }
}

int main(int argc, char* argv[]) {
    srand(static_cast<unsigned int>(time(0)));
    int n = 1000000;
    int m = 10000;
    int num = 100;
    if (argc == 2) {
        n = atoi(argv[1]);
        generate(n);
        return 0;
    }
    if (argc >= 3) {
        m = atoi(argv[1]) / 2;
        num = atoi(argv[2]);
        vector<int> g;
        for (int i = 0; i < m; i++)
            g.push_back(num * i * 10);
        random_shuffle(g.begin(), g.end());
        if (argc >= 4 && atoi(argv[3]) == 1)
            order = true;
        generate(m, num, g);
        return 0;
    }
    // generate(n);
    m /= 2;
    vector<int> g;
    for (int i = 0; i < m; i++)
        g.push_back(num * i * 10);
    random_shuffle(g.begin(), g.end());
    order = true;
    generate(m, num, g);
    return 0;
}
