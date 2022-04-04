#include <iostream>

using namespace std;

int multiplicator (int a, int b) {
	return a * b;
}

int main() {
	int num;
	int i = 1;
	int multiple = 1;
	cout << "input the number ";
	cin >> num;
	while (i <= 10) {
		multiple = multiplicator (num, i);
		cout << num << " * " << i << " = " << multiple << endl;
		i++;  
	}
	
        return 0;
}


