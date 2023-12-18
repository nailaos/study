/*
********************************
生成数据使用的参数
./generate 150000 150000 > 02.in
./generate 250000 250000 > 03.in
./generate 350000 350000 > 04.in
********************************
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

#define LEN 500000

struct Mapping {
    int type;  // 0: insert, 1: query, 2: end
    string key;
    int value[3];
};

void generateTestData(int insertCount, int queryCount) {
    vector<Mapping> testData(500000);

    for (int i = 0; i < 500000; i++)
        cin >> testData[i].value[0] >> testData[i].key >> testData[i].value[1] >> testData[i].value[2];

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < insertCount; ++i) {
        int x = rand() % LEN;
        int y = rand() % 3;
        cout << "0 " << testData[x].key << " " << testData[x].value[y] << endl;
    }

    for (int i = 0; i < queryCount; ++i) {
        int x = rand() % LEN;
        cout << "1 " << testData[x].key << endl;
    }

    cout << 2 << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <insertCount> <queryCount>" << endl;
        return EXIT_FAILURE;
    }

    int insertCount = atoi(argv[1]);
    int queryCount = atoi(argv[2]);

    generateTestData(insertCount, queryCount);

    return 0;
}
