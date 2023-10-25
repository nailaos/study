#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int binary_search(const vector<int>& arr, int target) {
	int hi = arr.size() - 1;
	if (target >= arr[hi]) return hi;
	int lo = 0;
	while (lo < hi) {
		int m = (lo + hi) >> 1;
		target < arr[m] ? hi = m : lo = m + 1;
	}
	return lo - 1;
}

int main() {
	int n, p;
	cin >> n >> p;
	vector<int> costs(n, 0);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) {
			costs[i] = a - b;
			p -= b;
		} else {
			costs[i] = b - a;
			p -= a;
		}
	}
	sort(costs.begin(), costs.end());
	vector<int> arr;
	int k = n / 2;
	int ans = 0;
	for (int i = 0; i < (1 << k); i++) {
		int tmp = 0;
		int tmpi = i;
		for (int j = 0; j < k; j++) tmp += costs[j] * ((tmpi >> j) & 1);
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	k = n - n / 2;
	for (int i = 0; i < (1 << k); i++) {
		int tmp = 0;
		int tmpi = i;
		int num = n / 2;
		for (int j = 0; j < k; j++)
			tmp += costs[j + num] * ((tmpi >> j) & 1);
		if (p - tmp < 0) continue;
		ans += binary_search(arr, p - tmp) + 1;
	}
	cout << ans << endl;
	return 0;
}
