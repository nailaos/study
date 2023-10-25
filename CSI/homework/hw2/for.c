int foo(int* a, int n, int val) {
	int i;
	for (i = n - 1; i >= 0 && val != a[i]; --i)
		;
	return i;
}
