#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    char c;
    int num;
    Node *left;
    Node *right;

    Node(char a, int n) {
        c = a;
        num = n;
        left = nullptr;
        right = nullptr;
    }

    Node(Node *a, Node *b) {
        c = ' ';
        num = a->num + b->num;
        left = a;
        right = b;
    }
};

bool compareTree(const Node *a, const Node *b) { return a->num > b->num; }

Node *createTree(vector<Node *> &nodes) {
    while (nodes.size() > 1) {
        sort(nodes.begin(), nodes.end(), compareTree); // 排序
        Node *tmp = new Node(nodes[0], nodes[1]); // 最小的两个节点变为新节点
        nodes.pop_back();
        nodes.pop_back();     // 弹出两个无用节点
        nodes.push_back(tmp); // 加入新节点
    }
    return nodes[0];
}

int main() {
    int n;
    cin >> n;
    vector<Node *> nodes;
    for (int i = 0; i < n; i++) {
        char a;
        int m;
        cin >> a >> m;
        nodes.push_back(new Node(a, m));
    }
    Node *hafTree = createTree(nodes); // 得到生成的树
}
