#include <iostream>
using namespace std;

void test(int x, int y, int z) { cout << x << endl; }

int main() {
	double x = 0.1234567899999;
	float y = 123456.123456;
	if ((x + y) - x == y) cout << "true" << endl;
	cout << sizeof(y) << endl;
	cout << sizeof((x + y) - x) << endl;
	int m = 1 << 31;
	cout << m << endl;
	m = -m;
	cout << m << endl;
	int n = -17;
	int t1 = n >> 4;
	int t2 = n / 16;
	cout << t1 << "\n" << t2 << endl;
	test(7, 9, 11);
	return 0;
}
