#include <iostream>
using namespace std;

void factorial (int n) {
	int fact = 1;
	int i = 1;
	while (i <= n) {
		fact *= i;
		i++;
	}
	cout << n <<  " factorial is " << fact <<endl;
}

int main() {
	int number;
	cout << "Input the number\n";
	cin >> number;
	factorial (number);	
	
	return 0;
}


