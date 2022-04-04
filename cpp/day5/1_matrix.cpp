#include <iostream>
#include <random>

using namespace std;

int rndNumber() {
	int random = rand () % 10 +1;
	return random;
}

int main() {
	const int SIZE = 5;
	int a[SIZE][SIZE];
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			a[i][j] = rndNumber ();
		}
	}
	cout << "Matrix:\n";
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if ( a[i][j] < 10) {
				cout << a[i][j] << "  ";
			}
			else {
				cout << a[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl;

	int sumTopRight = 0;
	int sumBottomLeft = 0;
	int sumTopLeft = 0;
	int sumBottomRight = 0;
	int sumTop = 0;
	int sumLeft = 0;
	int sumBottom = 0;
	int sumRight = 0;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (i != j ) {
				if (i < j) {
					sumTopRight += a[i][j];
				}
				if (i > j) {
					sumBottomLeft += a[i][j];
				}
			}
		}
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (i + j != SIZE - 1) {
				if (i + j < SIZE -1) {
					sumTopLeft += a[i][j];
				}
				if (i + j >= SIZE) {
					sumBottomRight += a[i][j];
				}
			}
		}
	}
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (i != j && i + j != SIZE - 1) {
				if (i < j && i + j < SIZE - 1) {
					sumTop += a[i][j];
				}
				if (i > j && i + j < SIZE - 1) {
					sumLeft += a[i][j];
				}
				if (i > j && i + j >= SIZE - 1) {
					sumBottom += a[i][j];
				}
				if (i < j && i + j >= SIZE - 1) {
					sumRight += a[i][j];
				}
			}
		}
	}

	cout << "Sum of numbers in the top right triangle: " << sumTopRight << endl;
	cout << "Sum of numbers in the bottom left triangle: " << sumBottomLeft << endl;
	cout << "Sum of number in the top left triangle: " << sumTopLeft << endl;
	cout << "Sum of number in the bottom right triangle: " << sumBottomRight << endl;
	cout << "Sum of number in the top triangle: " << sumTop << endl;
	cout << "Sum of number in the left triangle: " << sumLeft << endl;	
	cout << "Sum of number in the bottom triangle: " << sumBottom << endl;
	cout << "Sum of number in the right triangle: " << sumRight << endl;

	return 0;
}
