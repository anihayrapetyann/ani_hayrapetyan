#include <iostream>

using namespace std;

int summ (int a, int b, int c) {
	return a * 2 + 4 * (b + c);
}

int main() {
	int chicken;
	int cow;
	int pig;
	int sum;
	cout << "chicken - ";
	cin >> chicken;
	cout << "cow - ";
	cin >> cow;
	cout << "pig - ";
	cin >> pig;
	sum = summ (chicken, cow, pig);
	cout << sum << endl;

	return 0;
}

