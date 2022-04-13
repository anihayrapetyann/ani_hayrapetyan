#include <iostream>
#include "polynomial.h"

using namespace std;

int main() {
	Polynomial a, b, c;
	a.Set(3, 2); //3x^2
	a.Set(2, 4); //2x^4

	b.Set(5, 2); //5x^2
	b.Set(-3, 5); //-3x^5

	c = a.Subtract(b); // (3x^2 + 2x^4) - (5x^2 - 3x^5)
	c.Print();
	cout << endl;

	c = a.MultiplyByNumber(2);
	c.Print();
	cout << endl;

    return 0;
}

