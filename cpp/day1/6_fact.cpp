#include <iostream>
using namespace std;

int main () {
        int n;
	int fact=1;
	int m=1;

        cout << "Input the number\n";
	cin >> n;
        while (m<=n) {
		fact *= m;
		m++;
	}
	cout << n <<  " factorial is " << fact <<endl;	
	return 0;
}


