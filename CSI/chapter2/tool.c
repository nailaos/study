#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
	int i;
	for (i = len - 1; i >= 0; i--) printf("%.2x  ", start[i]);
	printf("\n");
}

void show_int(int x) { show_bytes((byte_pointer)&x, sizeof(int)); }

void show_float(float x) { show_bytes((byte_pointer)&x, sizeof(float)); }

void show_double(double x) { show_bytes((byte_pointer)&x, sizeof(double)); }

void show_void(void *x) { show_bytes((byte_pointer)&x, sizeof(void *)); }

int main() {
	double x = 9999999999.99;
	show_double(x);
	return 0;
}
