#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	int size;
	float arr [100];
	cout << "Enter size of array (1 to 100): ";
	cin >> size;
	cout << endl;
  	for (int i = 0; i < size; i++) {
		arr [i] = rand () % 100;
  	}
	cout << "Elements of array are - ";
	for (int i = 0; i < size; i++) {
		cout << arr [i];
		if (i == size - 1) {
			cout << " ";
		}
		else {
			cout << ", ";
		}
	}
	int x = arr [0];
	for (int i = 1; i < size; i++) {
		if (x < arr [i]) {
			x = arr [i];
		}
	}
  	cout << endl << "The largest element is  " << x << endl;

	return 0;
}
