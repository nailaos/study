#include <iostream>
#include <cstdio>
using namespace std;

class AVLTree {
private:
    struct Node {
        int value;
        Node* left;
        Node* right;
        int height;

        Node(int val) : value(val), height(1) {
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root;

    int Height(Node* node) {
        return (node) ? node->height : 0;
    }

    void updateHeight(Node* node) {
        node->height = max(Height(node->left), Height(node->right)) + 1;
    }

    int getBalance(Node* node) {
        return (node) ? Height(node->left) - Height(node->right) : 0;
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* z = x->right;

        x->right = y;
        y->left = z;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* z = y->left;

        y->left = x;
        x->right = z;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Node* rebalance(Node* node) {
        int b = getBalance(node);
        if (b > 1) {
            if (getBalance(node->left) >= 0)
                return rotateRight(node);
            else {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }

        if (b < -1) {
            if (getBalance(node->right) <= 0)
                return rotateLeft(node);
            else {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

    Node* insert(Node* node, int val) {
        if (!node)
            return new Node(val);

        if (val < node->value)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);

        updateHeight(node);
        return rebalance(node);
    }

    Node* removeAt(Node* node, int val) {
        if (node->left && node->right) {
            Node* temp = node->right;
            while (temp->left)
                temp = temp->left;

            node->value = temp->value;
            node->right = remove(node->right, temp->value);
        } else {
            Node* temp = (node->left) ? node->left : node->right;
            if (temp)
                *node = *temp;
            else {
                temp = node;
                node = nullptr;
            }

            delete temp;
        }

        return node;
    }

    Node* remove(Node* node, int val) {
        if (!node)
            return node;

        if (val < node->value)
            node->left = remove(node->left, val);
        else if (val > node->value)
            node->right = remove(node->right, val);
        else
            node = removeAt(node, val);

        if (!node)
            return node;

        updateHeight(node);
        return rebalance(node);
    }

    void printTree(Node* node) {
        if (node) {
            printTree(node->left);
            std::cout << node->value << " ";
            printTree(node->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int val) {
        root = insert(root, val);
    }

    void remove(int val) {
        root = remove(root, val);
    }

    int find(int tar) {
        int res = -1;
        Node* cur = root;
        while (cur) {
            if (cur->value <= tar) {
                res = max(res, cur->value);
                cur = cur->right;
                if (res == tar)
                    break;
            } else
                cur = cur->left;
        }
        return res;
    }

    void printTree() {
        printTree(root);
        cout << endl;
    }
};

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
                    if (res == tar)
                        break;
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
    //AVLTree avltree;
    SplayTree avltree;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char type;
        int num;
        scanf(" %c %d", &type, &num);
        if (type == 'A')
            avltree.insert(num);
        else if (type == 'B')
            avltree.remove(num);
        else {
            int ans = avltree.find(num);
            printf("%d\n", ans);
        }
    }
    return 0;
}