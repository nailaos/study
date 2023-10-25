#include <iostream>
using namespace std;

int main() {
	int x = -2147483648;
	while (x != 214748364) {
		if ((x|-x)>>31!=-1) {
			cout << "false" << endl;
			cout<<x<<endl;
			cout<<((x|-x)>>31)<<endl;
			return 0;
		}
		x++;
	}
	cout << "true" << endl << x << endl;
	return 0;
}
