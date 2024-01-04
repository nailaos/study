#include <iostream>
#include <cstdio>
using namespace std;

struct Node {
    int val;
    int npl;
    int size;
    Node* left;
    Node* right;

    Node(int value) : val(value), npl(0), size(1) {
        left = nullptr;
        right = nullptr;
    }
};

int k;
int fa[1000000], nodes[1000000];
Node* heaps[1000000];

int unionFind(int x) {
    if (fa[x] == x)
        return x;
    else {
        fa[x] = unionFind(fa[x]);
        return fa[x];
    }
}

void unionMerge(int x, int y) {
    fa[y] = x;
}

Node* merge(Node* h1, Node* h2) {
    if (!h1) return h2;
    if (!h2) return h1;

    if (h1->val > h2->val)
        swap(h1, h2);

    h1->right = merge(h1->right, h2);
    if (!h1->left || (h1->right && h1->left->npl < h1->right->npl))
        swap(h1->left, h1->right);
    h1->size = 1;
    if (h1->left)
        h1->size += h1->left->size;
    if (h1->right) {
        h1->npl = h1->right->npl + 1;
        h1->size += h1->right->size;
    } else
        h1->npl = 0;
    while (h1->size > k) {
        h1 = merge(h1->left, h1->right);
    }
    return h1;
}

void addEdge(int a, int b) {
    int u1 = unionFind(a - 1);
    int u2 = unionFind(b - 1);
    if (u1 != u2) {
        unionMerge(u1, u2);
        heaps[u1] = merge(heaps[u1], heaps[u2]);
    }
}

int kthFind(Node* root) {
    if (root->size < k)
        return -1;
    return root->val;
}

int main() {
    int n, m, q;
    scanf("%d %d %d %d", &n, &m, &k, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nodes[i]);
        heaps[i] = new Node(nodes[i]);;
        fa[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(a, b);
    }
    for (int i = 0; i < q; i++) {
        int type, u, v;
        scanf("%d %d", &type, &u);
        if (type == 1) {
            scanf("%d", &v);
            addEdge(u, v);
        } else {
            int ans = kthFind(heaps[unionFind(u - 1)]);
            printf("%d\n", ans);
        }
    }
}