#include <iostream>

using namespace std;

int main() {
	int number;
	int factorial = 1;
	int i = 1;
    	cout << "Input the number\n";
	cin >> number;
    	while (i <= number) {
		factorial *= i;
		i++;
	}
	cout << number <<  " factorial is " << factorial <<endl;	

	return 0;
}


