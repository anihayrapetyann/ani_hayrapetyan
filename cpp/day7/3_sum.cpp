#include <iostream>
using namespace std;

void sumOfArr (int *ptr, int len) {
	int sum = 0;
	int *p = ptr;
	while (p < ptr + len) {
		sum+= *(p++);
	}
	cout << "Sum of array elements is: " << sum << endl;
}

int main () {
	int arr[6];
	int i;
	cout << "Enter the elements of array\n";
	for ( i = 0; i < 6; i++) {
		cin >> arr[i];
	}
	cout << "Array elements are: ";
	for (i = 0; i < 6; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	int *ptr;
	ptr = arr;
	sumOfArr (ptr, 6);

	return 0;
}
