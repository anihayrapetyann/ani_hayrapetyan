#include <iostream>
#include "polynomial.h"

using namespace std;

	Polynomial::Polynomial() {
		for (int i = 0; i < 100; i++) {
			_coef[i] = 0;
		}
	}

	void Polynomial::Set(int a , int b) {
		_coef[b] = a;
		_deg = Degree();
	}

	int Polynomial::Degree() {
		int d = 0;
		for (int i = 0; i < 100; i++)
			if (_coef[i] != 0) d = i;
			return d;
		}

	void Polynomial::Print() {
		for (int i = 99; i >= 0; i--) {
			if (_coef[i] != 0) {
				cout << _coef[i] << "x^" << i << " ";
			}
		}
	}

	Polynomial Polynomial::Add(Polynomial b) {
		Polynomial a = *this; 
		Polynomial c;

		for (int i = 0; i <= a._deg; i++) c._coef[i] += a._coef[i];
		for (int i = 0; i <= b._deg; i++) c._coef[i] += b._coef[i];
		c._deg = c.Degree();
		return c;
	}
	
	Polynomial Polynomial::Subtract(Polynomial b) {
		Polynomial a = *this; 
		Polynomial c;

		for (int i = 0; i <= a._deg; i++) c._coef[i] += a._coef[i];
		for (int i = 0; i <= b._deg; i++) c._coef[i] -= b._coef[i];
			c._deg = c.Degree();
			return c;
		}

	Polynomial Polynomial::Multiply(Polynomial b) {
		Polynomial a = *this;
		Polynomial c;

		for (int i = 0; i <= a._deg; i++)
			for (int j = 0; j <= b._deg; j++)
				c._coef[i+j] += (a._coef[i] * b._coef[j]);
				c._deg = c.Degree();
				 return c;
		}

	Polynomial Polynomial::MultiplyByNumber (int number) {
		Polynomial a = *this;
		Polynomial c;
		for (int i = 0; i <= a._deg; i++) 
			c._coef[i] = number * a._coef[i];
			c._deg = c.Degree();
		return c;
	}
