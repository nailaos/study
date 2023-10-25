long plus(long x, long y);

void sumstore(long x, long y, long *dest) {
	long t = plus(x, y);
	*dest = t;
}

void swap(int *a, int *b) {
	int x = *a;
	int y = *b;
	*a = y;
	*b = x;
}

void swap1(short *a, short *b) {
	short x = *a;
	short y = *b;
	*a = y;
	*b = x;
}

void swap2(long *a, long *b) {
	long x = *a;
	long y = *b;
	*a = y;
	*b = x;
}
