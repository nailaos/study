#define N 16
typedef long fix_matrix[N][N];
void fix_set_diag_opt(fix_matrix A, int val) {
    long *start = &A[0][0];
    long i;
    long *bend = &A[0][0] + N * (N + 1);
    do {
        *start = val;
        start += N + 1;
    } while (start != bend);
}

void fix_set_diag(fix_matrix A, int val) {
    long i;
    for (i = 0; i < N; i++)
        A[i][i] = val;
}
