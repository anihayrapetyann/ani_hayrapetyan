#include <iostream>
#include <random>
#include <ctime>

using namespace std;

mt19937 gen(time(0));

int rndNumber () {
        int random = gen () % 10 + 1;
        return random;
}

int main() {
	const int SIZE = 5;
	int matrix_1[SIZE][SIZE];
	int matrix_2[SIZE][SIZE];
	int matrix_3[SIZE][SIZE];

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			matrix_1[i][j] = rndNumber ();
			matrix_2[i][j] = rndNumber ();
		}
	}

	cout << "Matrix1:" << endl;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if(matrix_1[i][j] < 10){
				cout << matrix_1[i][j] << "   ";
			}
			else {
				cout << matrix_1[i][j] << "  ";
			}
		}
		cout << endl; 
	}

	cout << "\nMatrix2:" << endl;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (matrix_2[i][j] < 10) {
				cout << matrix_2[i][j] << "   ";
			}
			else {
				cout << matrix_2[i][j] << "  ";
			}
                }
		cout << endl;
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			matrix_3[i][j] = matrix_1[i][j] + matrix_2[i][j];
		}
	}

	cout << "\nSum of matrix 1 and matrix 2:" << endl;
	for (int i = 0; i < SIZE ; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (matrix_3[i][j] < 10) {
				cout << matrix_3[i][j] << "   ";
			}
			else {
				cout << matrix_3[i][j] << "  ";
			}
		}
		cout << endl;
        }
	cout << endl;

	return 0;
}
