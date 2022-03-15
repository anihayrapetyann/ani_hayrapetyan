#include <iostream>
using namespace std;

void swap (int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
	cout << "a = " << *a << endl;
	cout <<  "b = " << *b << endl;
}

int main () {
	int a, b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "After swap:\n";
	swap (&a, &b);

	return 0;
}
