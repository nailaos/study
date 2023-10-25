#include <iostream>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	string a, b;
	cin >> a >> b;
	if (n > m) {
		swap(n, m);
		swap(a, b);
	}
	if (m - n > k) {
		cout << -1 << endl;
		return 0;
	}
	int* dp = new int[2 * k + 1];
	for (int i = 0; i <= 2 * k; i++) dp[i] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = k - min(i, k); j <= k + min(m - 1 - i, k); j++) {
			if (a[i] == b[i - k + j]) dp[j]++;
			int tmp = max(dp[max(0, j - 1)], dp[min(j + 1, 2 * k)]);
			dp[j] = max(tmp, dp[j]);
		}
	}
	int ans = m + n - 2 * dp[k + min(m - n, k)];
	if (ans <= k)
		cout << ans << endl;
	else
		cout << -1 << endl;
	delete[] dp;
	return 0;
}
