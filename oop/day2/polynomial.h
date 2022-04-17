#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial {
private:
	int _coef[100];
	int _deg;
public:
	Polynomial(); 
	void Set(int, int); 
	int Degree();
	void Print();
	Polynomial operator+(const Polynomial&) const;
	Polynomial &operator+=(const Polynomial&);
	Polynomial operator-(const Polynomial&) const;
	Polynomial &operator-=(const Polynomial&);
	Polynomial operator*(const Polynomial&) const;
	Polynomial &operator*=(const Polynomial&);
	Polynomial MultiplyByNumber(int);
};

#endif

