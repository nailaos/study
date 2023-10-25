#include <cstdio>
using namespace std;

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void quick_sort(int* arr, int l, int r) {
	if (l >= r) return;
	int a = l, b = r, tmp = arr[(l + r) / 2];
	while (a <= b) {
		while (arr[b] > tmp) b--;
		while (arr[a] < tmp) a++;
		if (a <= b) {
			swap(arr[a], arr[b]);
			a++;
			b--;
		}
	}
	if (l < b) quick_sort(arr, l, b);
	if (a < r) quick_sort(arr, a, r);
}

int binary_search(int* a, int* b, int x, int y, int start, int end) {
	int result = 0;
	while (start <= end) {
		int m = (start + end) / 2;
		long long int c = (long long int)a[m] * (long long int)y +
				  (long long int)b[m] * (long long int)x -
				  (long long int)a[m] * (long long int)b[m];
		if (c >= 0) {
			result = m;
			start = m + 1;
		} else
			end = m - 1;
	}
	return result + 1;
}

int main() {
	int n = 0;
	scanf("%d", &n);
	int* a = new int[n];
	int* b = new int[n];
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	quick_sort(a, 0, n - 1);
	quick_sort(b, 0, n - 1);
	int m = 0;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		long long int c = a[0] * x + b[0] * y - a[0] * b[0];
		int ans = 0;
		if (c >= 0) ans = binary_search(a, b, x, y, 0, n - 1);
		printf("%d\n", ans);
	}
	delete[] a;
	delete[] b;
}
