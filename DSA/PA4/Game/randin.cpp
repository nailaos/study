#include <iostream>
#include <ctime>
#include <vector>
#include <unordered_set>
using namespace std;

struct PairHash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto hash1 = std::hash<T1> {}(p.first);
        auto hash2 = std::hash<T2> {}(p.second);

        // Combining hashes using a simple hash combine technique
        return hash1 ^ hash2;
    }
};

int n = 100000;
int m = 100000;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    cout << n << " " << m << endl;

    // Generate random weights for nodes
    for (int i = 0; i < n; i++)
        cout << rand() % 1001 << ' ';
    cout << endl;

    // Generate random edges
    unordered_set<pair<int, int>, PairHash> edges; // Use the custom hash function
    for (int i = 0; i < m; ) {
        int a = rand() % n + 1;  // Random node 1 to n
        int b = rand() % n + 1;  // Random node 1 to n

        // Ensure a != b (no self-loops) and the edge (a, b) is not a duplicate
        if (a != b && edges.insert({ min(a, b), max(a, b) }).second) {
            cout << a << " " << b << endl;
            i++;
        }
    }

    return 0;
}
