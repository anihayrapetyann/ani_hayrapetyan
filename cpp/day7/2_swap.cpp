#include <iostream>
using namespace std;

void swap (int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
	cout << "a = " << *a << "  b =  " << *b << endl;
}

int main () {
	int a;
	int b;
	cout << "Enter the first number\n";
	cin >> a;
	cout << "Enter the second number\n";
	cin >> b;
	cout << "a = " << a << "  b =  " << b << endl;
	swap (&a, &b);

	return 0;
}
