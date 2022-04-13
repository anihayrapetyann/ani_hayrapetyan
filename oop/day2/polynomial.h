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
	Polynomial Add(Polynomial);
	Polynomial Subtract(Polynomial);
	Polynomial Multiply(Polynomial);
	Polynomial MultiplyByNumber(int);
};

#endif

