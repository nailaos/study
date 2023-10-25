#include <iostream>
using namespace std;

#define INT_MAX 2147483647;
#define LONG_MAX 9223372036854775807;

int main() {
	double x = INT_MAX;
	double y = LONG_MAX;
	cout << x << "\n" << y << endl;
	double n = 1, m = 1;
	do {
		x /= n;
		n += 1;
	} while (x > n);
	cout << n << endl;
	do {
		y /= m;
		m += 1;
	} while (y > m);
	cout << m << endl;
}
