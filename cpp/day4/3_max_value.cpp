#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	int i, n;
	float arr [100];
	cout << "Enter size of array (1 to 100): ";
	cin >> n;
	cout << endl;
  	for (i = 0; i < n; i++) {
		arr [i] = rand () % 100;
  	}
	cout << "Elements of array are - ";
	for (i = 0; i < n; i++) {
		cout << arr [i];
		if (i == n - 1) {
			cout << " ";
		}
		else {
			cout << ", ";
		}
	}
	int x = arr [0];
	for (i = 1; i < n; i++) {
		if (x < arr [i]) {
			x = arr [i];
		}
	}
  	cout << endl << "The largest element is  " << x << endl;

	return 0;
}
