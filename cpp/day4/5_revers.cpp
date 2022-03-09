#include <iostream>
#include <stdlib.h>
using namespace std;

int main () {
	int i, j, m, n;
	float arr [100];
	cout << "Enter size of array (1 to 100): ";
	cin >> n;
	cout << endl;
	for (i = 0; i < n; i++) {
		arr [i] = rand () % 100;
	}
	cout << "The elements of array are - ";
	for (i = 0; i < n; i++) {
		cout << arr [i];
		if (i == n - 1) {
			cout << " ";
		}
		else {
			cout << ", ";
		}
	}
	j = n - 1;
	for ( i = 0; i < j; i++, j--) {
		m = arr [i];
		arr [i] = arr [j];
		arr [j] = m;
	}
	cout << "\nThe elements of reversed array are - ";
	for (i = 0; i < n; i++) {
		cout << arr [i];
		if (i == n - 1) {
			cout << " ";
		}
		else {
			cout << ", ";
		}
	}
	cout << endl;

	return 0;
}
