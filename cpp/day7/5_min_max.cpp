#include <iostream>

using namespace std;

void minMax (int *ptr, int *number) { 
	int *counterptr = ptr;
	int  *maxptr = ptr;
	int *minptr = ptr;
	for (counterptr = ptr; counterptr < ptr + *number; counterptr++) {   
		if (*counterptr > *maxptr) {
			maxptr = counterptr;
		}
		if (*counterptr < *minptr) {
			minptr = counterptr;
		}
	}
	cout << "max value = " << *maxptr << endl;
	cout << "min value = "<< *minptr << endl;
}

int main() {
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
	minMax (arr, &number);

    return 0;
}
