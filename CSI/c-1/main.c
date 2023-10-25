int array[4] = {1, 2, 3, 4};
static int barray[4] = {1, 2, 3, 4};
static int intra_sum(int x[4], int y) { return x[y - 1]; }

int main() {
	int val = intra_sum(array, 3) + intra_sum(barray, 3);

	if (val >= 0)
		return val;
	else
		return -1;
}
