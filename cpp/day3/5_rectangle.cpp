#include <iostream>

using namespace std;

int perimeter (int a, int b) {
	return (a + b) * 2;
}

int area (int a, int b) {
	return a * b;
}

int main () {
	int length;
	int width;
	int p;
	int a;
	cout << "Input length of rectangle\n";
	cin >> length;
	cout << "Input the width of rectangle\n";
	cin >> width;
    p = perimeter (length, width);
	cout << "The perimeter of rectangle is " << p << endl;
	a = area (length, width);
	cout << "the area of rectangle is " << a << endl;

	return 0;
}


