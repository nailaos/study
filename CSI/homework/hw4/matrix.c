struct matrix_entry {
    char a;
    char b;
    double d;
    short c;
};

struct matrix_entry matrix[5][7];

int return_entry(int i, int j) { return matrix[i][j].c; }
