#include <iostream>
#include <cstdio>
using namespace std;

class SplayTree {
private:
    struct Node {
        int value;
        Node* left;
        Node* right;
        Node* parent;

        Node(int val) : value(val), parent(nullptr) {
            left = right = nullptr;
        }

        Node(int val, Node* _left, Node* _right) : value(val), parent(nullptr) {
            left = _left;
            right = _right;
        }

        bool isLeftChild() {
            return this->parent && this->parent->left == this;
        }
    };
    Node* root;

    void attachAsLC(Node* lc, Node* p) {
        p->left = lc;
        if (lc)
            lc->parent = p;
    }

    void attachAsRC(Node* p, Node* rc) {
        p->right = rc;
        if (rc)
            rc->parent = p;
    }

    Node* splay(Node* node) {
        if (!node)
            return node;
        Node* p;
        Node* g;
        while ((p = node->parent) && (g = p->parent)) {
            Node* gg = g->parent;
            if (node->isLeftChild()) {
                if (p->isLeftChild()) {
                    attachAsLC(p->right, g); attachAsLC(node->right, p);
                    attachAsRC(p, g); attachAsRC(node, p);
                } else {
                    attachAsLC(node->right, p); attachAsRC(g, node->left);
                    attachAsLC(g, node); attachAsRC(node, p);
                }
            } else {
                if (!p->isLeftChild()) {
                    attachAsRC(g, p->left); attachAsRC(p, node->left);
                    attachAsLC(g, p); attachAsLC(p, node);
                } else {
                    attachAsRC(p, node->left); attachAsLC(node->right, g);
                    attachAsRC(node, g); attachAsLC(p, node);
                }
            }
            if (!gg)
                node->parent = NULL;
            else
                (g == gg->left) ? attachAsLC(node, gg) : attachAsRC(gg, node);
        }
        if (p = node->parent) {
            if (node->isLeftChild()) {
                attachAsLC(node->right, p); attachAsRC(node, p);
            } else {
                attachAsRC(p, node->left); attachAsLC(p, node);
            }
        }
        node->parent = nullptr;
        return node;
    }

    Node* search(int tar) {
        if (tar == root->value)
            return root;
        Node* p = root;
        Node* cur = root;
        while (true) {
            cur = (tar < p->value) ? p->left : p->right;
            if (!cur || tar == cur->value)
                break;
            p = cur;
        }
        root = splay(cur ? cur : p);
        return root;
    }

    void printTree(Node* node) {
        if (node) {
            printTree(node->left);
            std::cout << node->value << " ";
            printTree(node->right);
        }
    }

public:
    SplayTree() : root(nullptr) {}

    void insert(int val) {
        if (!root) {
            root = new Node(val);
            return;
        }
        Node* node = search(val);
        if (node->value < val) {
            node->parent = root = new Node(val, node, node->right);
            if (node->right) {
                node->right->parent = root;
                node->right = nullptr;
            }
        } else {
            node->parent = root = new Node(val, node->left, node);
            if (node->left) {
                node->left->parent = root;
                node->left = nullptr;
            }
        }
    }

    void remove(int val) {
        search(val);
        Node* L = root->left;
        Node* R = root->right;
        delete root;
        if (!R) {
            if (L) L->parent = nullptr;
            root = L;
        } else {
            R->parent = nullptr;
            root = R;
            if (L) {
                search(val);
                L->parent = root;
                root->left = L;
            }
        }
    }

    int find(int tar) {
        int res = -1;
        Node* cur = root;
        Node* node = cur;
        while (cur) {
            if (cur->value <= tar) {
                if (cur->value > res) {
                    res = cur->value;
                    node = cur;
                }
                cur = cur->right;
            } else
                cur = cur->left;
        }
        root = splay(node);
        return res;
    }

    void printTree() {
        printTree(root);
        cout << endl;
    }
};

int main() {
    SplayTree avltree;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char type;
        int num;
        scanf(" %c %d ", &type, &num);
        if (type == 'A')
            avltree.insert(num);
        else if (type == 'B')
            avltree.remove(num);
        else {
            int ans = avltree.find(num);
            printf("%d\n", ans);
        }
    }
    //avltree.printTree();
    return 0;
}