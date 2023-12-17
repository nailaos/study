#include <iostream>
using namespace std;

struct Node {
    char c;
    int num;
    Node* left;
    Node* right;

    Node() {
        c = '#';
        num = 0;
        left = right = nullptr;
    }

    Node(char _c, int _num) {
        c = _c;
        num = _num;
        left = right = nullptr;
    }

    Node(Node* a, Node* b) {
        c = '#';
        num = a->num + b->num;
        left = a;
        right = b;
    }
};

string ans[26];
int num[26];
Node* hafTree;
Node* nodes[100];
int len;

void quickSort(Node* nodes[], int from, int to) {
    if (from >= to)
        return;
    int a = from, b = to, tmp = nodes[(from + to) / 2]->num;
    while (a <= b) {
        while (nodes[b]->num > tmp)
            b--;
        while (nodes[a]->num < tmp)
            a++;
        if (a <= b) {
            swap(nodes[a], nodes[b]);
            a++;
            b--;
        }
    }
    if (from < b)
        quickSort(nodes, from, b);
    if (a < to)
        quickSort(nodes, a, to);
}

void buildTree() {
    for (int i = 0; i < 26; i++) {
        if (num[i]) {
            nodes[len] = new Node('a' + i, num[i]);
            len++;
        }
    }
    while (len > 1) {
        quickSort(nodes, 0, len - 1);
        Node* tmp = new Node(nodes[0], nodes[1]);
        for (int i = 0; i < len - 2; i++)
            nodes[i] = nodes[i + 2];
        nodes[len - 2] = tmp;
        len--;
    }
    hafTree = nodes[0];
}

void solveTree(Node* node, string last) {
    if (!node)
        return;
    if (node->left == nullptr && node->right == nullptr)
        ans[node->c - 'a'] = last;
    solveTree(node->left, last + "0");
    solveTree(node->right, last + "1");
}

int main() {
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
        num[str[i] - 'a']++;
    buildTree();
    solveTree(hafTree, "");
    int textlen = 0;
    for (int i = 0; i < 26; i++)
        textlen += ans[i].length() * num[i];
    cout << textlen << endl;
    for (int i = 0; i < 26; i++)
        if (ans[i] != "")
            cout << (char)('a' + i) << ' ' << ans[i] << endl;
}
