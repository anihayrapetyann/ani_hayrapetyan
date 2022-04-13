#include <iostream>

using namespace std;

class Polynomial {
private:
	int _coef[100]; 
	int _deg;       

public:
	Polynomial() {
		for (int i = 0; i < 100; i++) {
			_coef[i] = 0;
		}
	}
	void set (int a , int b) {
		_coef[b] = a;
		_deg = degree();
	}

	int degree() {
		int d = 0;
		for (int i = 0; i < 100; i++)
			if (_coef[i] != 0) d = i;
			return d;
		}

	void print() {
		for (int i = 99; i >= 0; i--) {
			if (_coef[i] != 0) {
				cout << _coef[i] << "x^" << i << " ";
			}
		}
	}
	Polynomial Add (Polynomial b) {
		Polynomial a = *this; 
		Polynomial c;

		for (int i = 0; i <= a._deg; i++) c._coef[i] += a._coef[i];
		for (int i = 0; i <= b._deg; i++) c._coef[i] += b._coef[i];
		c._deg = c.degree();
		return c;
	}
	
	Polynomial Subtract (Polynomial b) {
		Polynomial a = *this; 
		Polynomial c;

		for (int i = 0; i <= a._deg; i++) c._coef[i] += a._coef[i];
		for (int i = 0; i <= b._deg; i++) c._coef[i] -= b._coef[i];
			c._deg = c.degree();
			return c;
		}

	Polynomial Multiply (Polynomial b) {
		Polynomial a = *this;
		Polynomial c;

		for (int i = 0; i <= a._deg; i++)
			for (int j = 0; j <= b._deg; j++)
				c._coef[i+j] += (a._coef[i] * b._coef[j]);
				c._deg = c.degree();
				 return c;
		}

	Polynomial MultiplyByNumber (int number) {
		Polynomial a = *this;
		Polynomial c;
		for (int i = 0; i <= a._deg; i++) 
			c._coef[i] = number * a._coef[i];
			c._deg = c.degree();
		return c;
	}
};
int main() {
	Polynomial a, b, c;
	a.set (3, 2); //3x^2
	a.set ( 2, 4 ); //2x^4

	b.set ( 5, 2 ); //5x^2
	b.set ( -3, 5 ); //-3x^5
	
	c = a.Subtract ( b ); // (3x^2 + 2x^4) - (5x^2 - 3x^5)
	c.print();
	cout << endl;

	c = a.MultiplyByNumber(2);
	c.print();
	cout << endl;

	return 0;
}
