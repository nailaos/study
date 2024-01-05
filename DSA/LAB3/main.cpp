#include <iostream>
#include <cstdio>
using namespace std;

enum Color {
    Red,
    Black
};

struct Node {
    int val;
    int height;
    int size;
    Color color;
    Node* left;
    Node* right;
    Node* parent;
};

class AvlTree {
private:
    Node* root;

    Node* search(int value) {
        Node* cur = root;
        while (cur) {
            if (cur->val < value)
                cur = cur->right;
            else if (cur->val > value)
                cur = cur->left;
            else break;
        }
        return cur;
    }

public:
    void insert(int value) {

    }

    void remove(int value) {

    }

    int find(int value) {

    }
};

class SplayTree {
private:
    Node* root;
};

class RBTree {
private:
    Node* root;
};