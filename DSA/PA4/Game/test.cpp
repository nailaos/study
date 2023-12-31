#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int n, m;
int MOD = 1e9 + 7;
int* nodes;
int** adj;
int* nums;
int* dis;
int* step;
bool* visit;

struct Node {
    int vertex;
    int distance;
    Node(int v, int d) : vertex(v), distance(d) {}
    // Define the comparison operator for the priority queue
    bool operator>(const Node& other) const {
        return distance > other.distance;
    }
};

priority_queue<Node, vector<Node>, greater<Node>> pq; // Min-heap

void init() {
    scanf("%d %d", &n, &m);

    nodes = new int[n];
    adj = new int* [n];
    nums = new int[n];
    dis = new int[n];
    step = new int[n];
    visit = new bool[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &nodes[i]);
        adj[i] = new int[n];
        nums[i] = 0;
        dis[i] = INT_MAX;
        step[i] = 0;
        visit[i] = false;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        adj[a][nums[a]++] = b;
        adj[b][nums[b]++] = a;
    }

    dis[0] = 0;
    step[0] = 1;
    pq.push(Node(0, 0));
}

void dijkstra() {
    while (!pq.empty()) {
        int x = pq.top().vertex;
        int d = pq.top().distance;
        pq.pop();

        if (visit[x]) continue;
        visit[x] = true;

        for (int i = 0; i < nums[x]; i++) {
            int y = adj[x][i];
            int distance = d + nodes[x];

            if (distance < dis[y]) {
                dis[y] = distance;
                step[y] = step[x];
                pq.push(Node(y, dis[y]));
            } else if (distance == dis[y]) {
                step[y] += step[x];
                if (step[y] >= MOD) step[y] %= MOD;
            }
        }
    }
}

int main() {
    init();
    dijkstra();
    printf("%d\n", dis[n - 1] + nodes[n - 1]);
    printf("%d\n", step[n - 1]);

    // Cleanup
    delete[] nodes;
    delete[] nums;
    delete[] dis;
    delete[] step;
    delete[] visit;

    for (int i = 0; i < n; i++)
        delete[] adj[i];
    delete[] adj;

    return 0;
}
