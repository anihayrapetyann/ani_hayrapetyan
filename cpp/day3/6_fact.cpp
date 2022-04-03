#include <iostream>
using namespace std;

void factorial (int n) {
	int fact = 1;
	int m = 1;
	while (m <= n) {
		fact *= m;
		m++;
    }
    cout << n <<  " factorial is " << fact <<endl;
}

int main() {
    int n;
    cout << "Input the number\n";
	cin >> n;
    factorial (n);	
	
	return 0;
}


