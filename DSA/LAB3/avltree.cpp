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

int main() {
    AVLTree avltree;

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
    //avltree.printTree();
    return 0;
}
