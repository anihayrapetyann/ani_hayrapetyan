#include <iostream>
using namespace std;
 
void binary (int n) {
	int binaryNumber [32];
	int i = 0;
	while (n > 0) {
		binaryNumber [i] = n % 2;
		n = n / 2;
		i++;
	}
	for (int j = i - 1; j >= 0; j--) {
		cout << binaryNumber [j];
	}
}

int main () {
	int n;	
	cout << "Enter the number\n";
	cin >> n;
   	binary (n);
	cout << endl;

	return 0;
}
