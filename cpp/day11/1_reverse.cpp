#include <iostream>

using namespace std;

int main () {
	int n;
	cout << "enter the number\n";
	cin >> n;
	string arr = to_string (n);
	cout << "Enter the numbers of the digits  you want to swap\n";
	int swap, number1, number2;
	cin >> number1 >> number2;
	int findex, lindex;
	if (number1 - 1 < 0 || number2 - 1 < 0 || number1 > arr.size() || number2 > arr.size()) {
		cout << "invalid input\n";

	}
	else {
		for (int i = 0; i < n; i++) {
			if (i  == number1 - 1) {
				findex = i;
				arr[findex] = arr[i];

			}
			if (i  == number2 - 1) {
				lindex = i ;
				arr[lindex ] = arr[i];
			}
		}	
		swap = arr[findex];
		arr[findex] = arr[lindex];
		arr[lindex] = swap;
		cout << "The swaped number is: ";
		cout << arr;
		cout << endl;
	}

	return 0;
}
