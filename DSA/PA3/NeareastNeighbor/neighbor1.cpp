#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

#define LONG_MAX 9223372036854775807;
int d, n;

struct KDtree {
    int dim;
    int* vect;
    KDtree* l;
    KDtree* r;
    KDtree* parent;

    KDtree() {
        dim = 0;
        vect = new int[d];
        l = nullptr;
        r = nullptr;
        parent = nullptr;
    }

    KDtree* brother() {
        if (this->parent->l == this)
            return this->parent->r;
        else
            return this->parent->l;
    }
};

int** vects;
KDtree* tree;

void quickSort(int from, int to, int dim) {
    if (from >= to)
        return;
    int a = from, b = to, tmp = vects[(from + to) / 2][dim];
    while (a <= b) {
        while (vects[b][dim] > tmp)
            b--;
        while (vects[a][dim] < tmp)
            a++;
        if (a <= b) {
            swap(vects[a], vects[b]);
            a++;
            b--;
        }
    }
    if (from < b)
        quickSort(from, b, dim);
    if (a < to)
        quickSort(a, to, dim);
}

void buildTree(KDtree* tree, int from, int to, int depth) {
    if (from > to) {
        tree->dim = -1;
        return;
    }
    int dim = depth % d;
    if (from == to) {
        tree->dim = dim;
        for (int i = 0; i < d; i++)
            tree->vect[i] = vects[from][i];
        return;
    }
    quickSort(from, to, dim);
    tree->dim = dim;
    int mid = (from + to) / 2;
    for (int i = 0; i < d; i++)
        tree->vect[i] = vects[mid][i];
    tree->l = new KDtree;
    tree->l->parent = tree;
    buildTree(tree->l, from, mid - 1, depth + 1);
    tree->r = new KDtree;
    tree->r->parent = tree;
    buildTree(tree->r, mid + 1, to, depth + 1);
}

void printTree(KDtree* tree, int depth) {
    cout << "depth: " << depth << " dimensions: " << tree->dim << " vector: ";
    for (int i = 0; i < d; i++)
        cout << tree->vect[i] << ' ';
    cout << endl;
    if (tree->l)
        printTree(tree->l, depth + 1);
    if (tree->r)
        printTree(tree->r, depth + 1);
}

void init() {
    vects = new int* [n];
    for (int i = 0; i < n; i++) {
        vects[i] = new int[d];
        for (int j = 0; j < d; j++)
            scanf("%d", &vects[i][j]);
    }
    tree = new KDtree;
    buildTree(tree, 0, n - 1, 0);
}

long long int distance(int* x, int* y) {
    long long res = 0;
    for (int i = 0; i < d; i++)
        res += (long long)(x[i] - y[i]) * (long long)(x[i] - y[i]);
    return res;
}

void findNearest(KDtree* tre, int* ques, long long int& ans) {
    if (!tre || tre->dim < 0)
        return;
    KDtree* curr = tre;
    while (curr->l || curr->r) {
        int dim = curr->dim;
        if (ques[dim] < curr->vect[dim]) {
            curr = curr->l;
        } else {
            curr = curr->r;
        }
    }
    if (curr->dim < 0)
        curr = curr->brother();
    ans = min(ans, distance(ques, curr->vect));
    while (curr != tre) {
        int dim = curr->parent->dim;
        if (sqrt(ans) > (double)(abs(ques[dim] - curr->parent->vect[dim]))) {
            ans = min(ans, distance(ques, curr->parent->vect));
            findNearest(curr->brother(), ques, ans);
        }
        curr = curr->parent;
    }
}

int main() {
    int q;
    scanf("%d %d", &d, &n);
    init();
    //printTree(tree, 0);
    int* ques = new int[d];
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < d; j++)
            scanf("%d", &ques[j]);
        long long int ans = LONG_MAX;
        findNearest(tree, ques, ans);
        printf("%lld\n", ans);
    }
    return 0;
}
