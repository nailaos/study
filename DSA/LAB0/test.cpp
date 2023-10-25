#include <iostream>
using namespace std;

int fun(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) sum += i;
	int no = 0;
	while (true) {
		(no++);
	}
	while (false) {
		no--;
	}
	return sum;
}

int main() {
	int x = 0, y = 0;
	cout << "x: " << x << "   y: " << y << endl;
	cout << "result[1-200]" << fun(200) << endl;
	for (int i = 0; i < 5; i++) {
		x += 3;
		y += 5;
	}
	cout << "x: " << x << "   y: " << y << endl;
}
