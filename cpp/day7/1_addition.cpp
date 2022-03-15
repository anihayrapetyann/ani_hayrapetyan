#include <iostream>
using namespace std;

void sum1 (int *a, int *b, int *sum) {
	*sum = *a + *b;
	cout << "sum 1 = " << *sum << endl;
}

void sum2 (int &a, int &b, int &sum) {
	sum = a + b;
	cout << "sum 2 = " << sum << endl;
}

void sum3 (int a, int b, int &sum) {
	sum = a + b;
	cout << "sum 3 = " << sum << endl;
}
void sum4 (int &a, int *b, int &sum) {
	sum = a + *b;
	cout << "sum 4 = " << sum << endl;
}
void sum5 (int *a, int *b, int &sum) {
	sum = *a + *b;
	cout << "sum 5 = " << sum << endl;
}

int main () {
	int a;
	int b;
	cout << "Enter the first number\n";
	cin >> a;
	cout << "Enter the second number\n";
	cin >> b;
	int sum;
	sum1 (&a, &b, &sum);
	sum2 (a, b, sum);
	sum3 (a, b, sum);
	sum4 (a, &b, sum);
	sum5 (&a, &b, sum);

	return 0;
}
