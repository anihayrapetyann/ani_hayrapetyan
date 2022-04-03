#include <iostream>

using namespace std;

int main() {
	int number;
	int i = 1;
	int multiple = 1;
	cout << "input the number ";
	cin >> number;
        while (i <= 10) {
		multiple = number * i;
        	cout << number << " * " << i << " = " << multiple <<endl;
		i++;  
	}

        return 0;
}


