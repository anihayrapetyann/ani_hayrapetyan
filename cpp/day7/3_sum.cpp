#include <iostream>
using namespace std;

void sumOfArr (int *ptr, int *len) {
	int sum = 0;
	int *p = ptr;
	while (p < ptr + *len) {
		sum+= *(p++);
	}
	cout << "Sum of array elements is: " << sum << endl;
}

int main () {
	int number;
	cout << "Enter the number of elements\n";
	cin >>number;
	int *arr = new int[number];
	int *p = arr;
	cout << "Enter the elements of array\n";
	while (p < arr + number) {
		cin >> *p++;
	}
	p = arr; 
	cout << "The elements of array: ";
	while (p < arr + number) {
                cout <<  *p++ << " ";
	}
	cout << endl;
	sumOfArr (arr, &number);

	return 0;
}
