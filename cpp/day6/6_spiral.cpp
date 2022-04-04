#include <iostream>

using namespace std;

int main () {
	const int SIZE = 8;
	int array[SIZE][SIZE];
	int number = 1; 
	int length = SIZE;
	int k = 0;
	
	while (number <= SIZE * SIZE) {	
		for (int i = k; i < length; i++) {
			array[k][i] = number;
			number++;
		}
		for (int i = k + 1; i < length; i++) {
			array[i][length - 1] = number;
			number++;
		}
		for (int i = length - 2; i >= k; i--) {
			array[length - 1][i] = number;
			number++;
		}
		for (int i = length - 2; i > k; i--) {
			array[i][k] = number;
			number++;
		}
		k++; length -= 1;
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (array[i][j] < 10) { 
				cout << array[i][j] << "  ";
			}
			else {
				cout << array [i][j] << " ";
			}
		}
		cout << endl;
	}

	return 0; 
}
