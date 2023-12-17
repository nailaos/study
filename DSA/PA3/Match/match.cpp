#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;

unsigned long long SEED = 31;
unsigned long long MOD = 1000000000000002493;
unsigned long long seeds[800001] = { 0 };
int num = 0;

struct Node {
    unsigned long long val1;
    unsigned long long val2;
    int size;
    int c;
    bool lazy;
    Node* l;
    Node* r;
    Node* parent;

    Node() : val1(0), val2(0), size(1), c(0) {
        lazy = false;
        l = nullptr;
        r = nullptr;
        parent = nullptr;
    }

    Node(char _c) : size(1) {
        c = _c - 96;
        val1 = c;
        val2 = c;
        lazy = false;
        l = nullptr;
        r = nullptr;
        parent = nullptr;
    }

    Node(char _c, Node* p) : size(1) {
        c = _c - 96;
        val1 = c;
        val2 = c;
        lazy = false;
        l = nullptr;
        r = nullptr;
        parent = p;
    }

    bool isLeftChild() {
        if (parent && parent->l == this)
            return true;
        return false;
    }

    void update() {
        size = 1;
        if (r)
            size += r->size;
        if (l)
            size += l->size;
        val1 = 0;
        val2 = 0;
        int lenr = 0;
        int lenl = 0;
        if (r) {
            if (r->lazy)
                r->down();
            lenr = r->size;
            val1 = (val1 + r->val1) % MOD;
            val2 = (val2 + r->val2 * seeds[size - r->size]) % MOD;
        }
        if (l) {
            if (l->lazy)
                l->down();
            lenl = l->size;
            val1 = (val1 + l->val1 * seeds[size - l->size]) % MOD;
            val2 = (val2 + l->val2) % MOD;
        }
        val1 = (val1 + (unsigned long long)c * seeds[lenr]) % MOD;
        val2 = (val2 + (unsigned long long)c * seeds[lenl]) % MOD;
    }

    void down() {
        this->lazy = false;
        swap(this->val1, this->val2);
        Node* tmp = l;
        l = r;
        r = tmp;
        if (this->l)
            this->l->lazy ^= true;
        if (this->r)
            this->r->lazy ^= true;
    }
};

Node* SplayTree;
int n, m;

void printStr(Node* tree);
void printTree();

void rotate(Node* node) {
    if (node->parent->parent && node->parent->parent->lazy)
        node->parent->parent->down();
    Node* p = node->parent;
    if (p->lazy)
        p->down();
    if (node->lazy)
        node->down();
    int num = 0;
    if (p->parent) {
        if (p->isLeftChild())
            num = 1;
        else
            num = 2;
    }
    if (node->isLeftChild()) {
        node->parent = p->parent;
        p->l = node->r;
        if (node->r)
            node->r->parent = p;
        node->r = p;
        p->parent = node;
    } else {
        node->parent = p->parent;
        p->r = node->l;
        if (node->l)
            node->l->parent = p;
        node->l = p;
        p->parent = node;
    }
    if (num) {
        if (num == 1)
            node->parent->l = node;
        else
            node->parent->r = node;
    }
    p->update();
    node->update();
}

void zigZig(Node* node) {
    rotate(node->parent);
    rotate(node);
}

void splay(Node* node) {
    if (!node)
        return;
    while (node->parent) {
        if (node->parent->parent && !(node->isLeftChild() ^ node->parent->isLeftChild()))
            zigZig(node);
        else
            rotate(node);
    }
    SplayTree = node;
}

void mysplay(Node* node) {
    if (node == SplayTree)
        return;
    while (node->parent != SplayTree) {
        if (node->parent->parent->parent && !(node->isLeftChild() ^ node->parent->isLeftChild()))
            zigZig(node);
        else
            rotate(node);
    }
}

void buildTree(Node* node, int from, int to, string& str) {
    if (from == to) {
        if (from == -1) {
            node->val1 = node->val2 = node->c = 0;
            node->size = 1;
            return;
        }
        if (from == n) {
            node->val1 = node->val2 = node->c = -1;
            node->size = 1;
            return;
        }
        node->c = str[from] - 96;
        node->val1 = node->c;
        node->val2 = node->c;
        node->size = 1;
        return;
    }
    int mid = (from + to) / 2;
    node->c = str[mid] - 96;
    node->val1 = node->c;
    node->val2 = node->c;
    node->size = 1;
    if (from < mid) {
        node->l = new Node;
        node->l->parent = node;
        buildTree(node->l, from, mid - 1, str);
    }
    if (mid < to) {
        node->r = new Node;
        node->r->parent = node;
        buildTree(node->r, mid + 1, to, str);
    }
    node->update();
}

Node* findNode(int x) {
    Node* node = SplayTree;
    Node* res = nullptr;
    while (node) {
        if (node->lazy)
            node->down();
        if (node->l && x < node->l->size) {
            node = node->l;
        } else if (node->r && x >= node->size - node->r->size) {
            x -= (node->size - node->r->size);
            node = node->r;
        } else {
            res = node;
            break;
        }
    }
    return res;
}

Node* preNode(Node* node) {
    while (node->r) {
        node = node->r;
    }
    return node;
}

Node* nxtNode(Node* node) {
    while (node->l) {
        node = node->l;
    }
    return node;
}

void insertNode(int x, char c) {
    Node* node = findNode(x);
    splay(node);
    if (node->r) {
        Node* input = new Node(c, node);
        input->r = node->r;
        node->r->parent = input;
        node->r = input;
        node->r->update();
    } else {
        node->r = new Node(c, node);
    }
    node->update();
}

void removeNode(int x) {
    Node* tar = findNode(x + 1);
    splay(tar);
    SplayTree = tar->l;
    Node* rt = preNode(SplayTree);
    splay(rt);
    SplayTree->r = tar->r;
    tar->r->parent = SplayTree;
    SplayTree->update();
}

void reverseNodes(int x, int y) {
    splay(findNode(x));
    mysplay(findNode(y + 2));
    Node* tmp = SplayTree->r->l;
    if (tmp) {
        swap(tmp->val1, tmp->val2);
        Node* tt = tmp->l;
        tmp->l = tmp->r;
        tmp->r = tt;
        if (tmp->l)
            tmp->l->lazy ^= true;
        if (tmp->r)
            tmp->r->lazy ^= true;
    }
    SplayTree->r->update();
    SplayTree->update();
}

void isequal(int x, int y, int len) {
    splay(findNode(x));
    mysplay(findNode(x + len + 1));
    unsigned long long ans1 = SplayTree->r->l->val1;
    splay(findNode(y));
    mysplay(findNode(y + len + 1));
    unsigned long long ans2 = SplayTree->r->l->val1;
    if (ans1 == ans2)
        printf("T");
    else
        printf("F");
}

void solve(int a) {
    int x, y;
    int len;
    char c;
    switch (a) {
        case 1: {
                scanf(" %d %c", &x, &c);
                insertNode(x, c);
                break;
            }
        case 2: {
                scanf(" %d", &x);
                removeNode(x);
                break;
            }
        case 3: {
                scanf(" %d %d", &x, &y);
                reverseNodes(x, y);
                break;
            }
        case 4: {
                scanf(" %d %d %d", &x, &y, &len);
                isequal(x, y, len);
                break;
            }
        case 5: {
                printStr(SplayTree);
                break;
            }
        default:
            break;
    }
    // cout << "val1: " << SplayTree->val1 << endl;
    // cout << "val2: " << SplayTree->val2 << endl;
    num++;
    cout << num << ": ";
    cout << SplayTree->size << endl;
}

void init() {
    scanf("%d %d", &n, &m);
    seeds[0] = 1;
    for (int i = 1; i <= m + n; i++) {
        seeds[i] = (SEED * seeds[i - 1]) % MOD;
    }
    if (n) {
        SplayTree = new Node;
        string str;
        cin >> str;
        buildTree(SplayTree, -1, n, str);
    } else {
        SplayTree = new Node('`');
        SplayTree->l = new Node('`', SplayTree);
        SplayTree->size = 2;
    }
}

int main() {
    init();
    for (int i = 0; i < m; i++) {
        int a;
        scanf("%d", &a);
        solve(a);
    }
    printf("\n");
    return 0;
}

void printtree(Node* tree) {
    if (!tree)
        return;
    if (tree->c) {
        cout << "size: " << setw(2) << tree->size;
        cout << "  char: " << setw(2) << (char)(tree->c + 96);
        cout << "  lazy: " << tree->lazy << endl;
        cout << "val1: " << tree->val1 << endl;
        cout << "val2: " << tree->val2 << endl;
        cout << "-------------" << endl;
    } else {
        cout << "I'm sntinel!" << endl;
        cout << "-------------" << endl;
    }
    printtree(tree->l);
    printtree(tree->r);
}

void printStr(Node* tree) {
    if (!tree)
        return;
    printStr(tree->l);
    if (tree->c)
        cout << (char)(tree->c + 96);
    else
        cout << '*';
    printStr(tree->r);
}

void printTree() {
    cout << "=============" << endl;
    cout << "The SplayTree" << endl;
    cout << "-------------" << endl;
    printtree(SplayTree);
    printStr(SplayTree);
    cout << endl;
}