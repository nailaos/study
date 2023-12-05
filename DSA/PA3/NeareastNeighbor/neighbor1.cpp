#include <cstdio>
#include <iostream>
using namespace std;

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
    if (from > to)
        return;
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
    tree->r = new KDtree;
    tree->l->parent = tree;
    tree->r->parent = tree;
    buildTree(tree->l, from, mid - 1, depth + 1);
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

long long int findNearest(KDtree* tree, int* ques) { return 0; }

int main() {
    int q;
    scanf("%d %d", &d, &n);
    init();
    printTree(tree, 0);
    int* ques = new int[d];
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < d; j++)
            scanf("%d", &ques[j]);
        long long int ans = findNearest(tree, ques);
        printf("%lld\n", ans);
    }
    return 0;
}
