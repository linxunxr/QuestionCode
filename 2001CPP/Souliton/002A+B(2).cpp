#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;
	while (num > 0) {
		int a, b;
		cin >> a >> b;
		cout << a + b << endl;
		num--;
	}
}