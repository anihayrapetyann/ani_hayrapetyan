#include <iostream>
using namespace std;

void perNumber (int n) {
	int i;
	int x = 0;
	for (i = 1; i < n; i++) {
		if (n % i == 0) {
			x = x + i; 
		}
	}	
	if (n == x) {
		cout << "The number is perfect\n"; 	
	}
	else {
		cout << "The number is not perfect\n";
	}	
}

int main () {
	int number;
	cout << "Enter the number \n";
	cin >> number;
	perNumber (number);
	
	return 0;
}
