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
        c = '#';
        num = a->num + b->num;
        left = a;
        right = b;
    }
};

string ans[27];
Node *hafTree; // 得到生成的树
string strTree;

bool compareTree(const Node *a, const Node *b) { return a->num < b->num; }

void createTree(vector<Node *> &nodes) {
    while (nodes.size() > 1) {
        sort(nodes.begin(), nodes.end(), compareTree); // 排序
        Node *tmp = new Node(nodes[0], nodes[1]); // 最小的两个节点变为新节点
        nodes.erase(nodes.begin(), nodes.begin() + 2); // 弹出两个无用节点
        nodes.push_back(tmp);                          // 加入新节点
    }
    hafTree = nodes[0];
}

void solveTree(Node *node, string last) {
    if (!node)
        return;

    if (node->left == nullptr && node->right == nullptr) {
        if (node->c == ' ')
            ans[26] = last;
        else
            ans[node->c - 'A'] = last;
    }
    solveTree(node->left, last + "0");
    solveTree(node->right, last + "1");
}

string treeToString(Node *node) {
    if (node == nullptr)
        return "$";

    if (node->c != '#')
        return string(1, node->c);

    string leftString = treeToString(node->left);
    string rightString = treeToString(node->right);
    return "(" + leftString + node->c + rightString + ")";
}

void writeTree() {
    ofstream out;
    out.open("HfmTree.txt");
    out << "Haffman Tree" << endl;
    for (int i = 0; i < 25; i++)
        out << "=";
    out << endl;
    out << strTree << endl;
    for (int i = 0; i < 25; i++)
        out << "=";
    out << endl;
    for (int i = 0; i < 27; i++) {
        if (i < 26)
            out << "  " << (char)('A' + i) << "  :  " << ans[i] << endl;
        else
            out << "space:  " << ans[i] << endl;
    }
    out.close();
}

void printTree() {
    cout << "Haffman Tree" << endl;
    for (int i = 0; i < 25; i++)
        cout << "=";
    cout << endl;
    cout << strTree << endl;
    for (int i = 0; i < 25; i++)
        cout << "=";
    cout << endl;
    for (int i = 0; i < 27; i++) {
        if (i < 26)
            cout << "  " << (char)('A' + i) << "  :  " << ans[i] << endl;
        else
            cout << "space:  " << ans[i] << endl;
    }
}

string readFile(string name) {
    ifstream in;
    in.open(name);
    string res;
    getline(in, res);
    in.close();
    return res;
}

void writeFile(string name, string content) {
    ofstream out;
    out.open(name);
    out << content << endl;
    out.close();
}

void showFile(string name) {}

void codeToText() {
    string code = readFile("CodeFile.txt");
    vector<char> text;
    Node *use = hafTree;
    for (int i = 0; i < code.length(); i++) {
        if (code[i] == '0')
            use = use->left;
        else
            use = use->right;
        if (!use->left && !use->right) {
            text.push_back(use->c);
            use = hafTree;
        }
    }
    writeFile("TextFile.txt", string(text.begin(), text.end()));
}

void textToCode() {
    string text = readFile("ToBeTran.txt");
    string code;
    for (char c : text) {
        if (c == ' ')
            code += ans[26];
        else
            code += ans[c - 'A'];
    }
    writeFile("CodeFile.txt", code);
}

int main() {
    int n;
    cin >> n;
    vector<Node *> nodes;
    for (int i = 0; i < n; i++) {
        char a;
        int m;
        cin >> a >> m;
        if (a == '%')
            a = ' ';
        nodes.push_back(new Node(a, m));
    }
    createTree(nodes);
    strTree = treeToString(hafTree);
    solveTree(hafTree, "");
    writeTree();
    printTree();
    textToCode();
    codeToText();
}
