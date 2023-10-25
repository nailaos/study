#include<cstdio>

int matrix[2001][2001];
long long int dp[2001][2001];

int main() {
    int n, m, q;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &matrix[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + matrix[i][j];
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int x, y, a, b;
        scanf("%d %d %d %d", &x, &y, &a, &b);
        int X = x + a - 1;
        int Y = y + b - 1;
        long long int ans = dp[X][Y] - dp[X][y - 1] - dp[x - 1][Y] + dp[x - 1][y - 1];
        printf("%lld\n", ans);
    }
    return 0;
}
