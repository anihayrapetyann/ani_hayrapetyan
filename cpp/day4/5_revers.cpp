#include <iostream>
#include <stdlib.h>

using namespace std;

int main () {
	int m, size;
	float arr [100];
	cout << "Enter size of array (1 to 100): ";
	cin >> size;
	cout << endl;
	for (int i = 0; i < size; i++) {
		arr [i] = rand () % 100;
	}
	cout << "The elements of array are - ";
	for (int i = 0; i < size; i++) {
		cout << arr [i];
		if (i == size - 1) {
			cout << " ";
		}
		else {
			cout << ", ";
		}
	}
	int j = size - 1;
	for ( int i = 0; i < j; i++, j--) {
		m = arr [i];
		arr [i] = arr [j];
		arr [j] = m;
	}
	cout << "\nThe elements of reversed array are - ";
	for (int i = 0; i < size; i++) {
		cout << arr [i];
		if (i == size - 1) {
			cout << " ";
		}
		else {
			cout << ", ";
		}
	}
	cout << endl;

	return 0;
}
