#include <iostream>
#include <random>
#include <ctime>
 
using namespace std;
 
int rndNumber () {
        int random = rand () % 100 +1;
        return random;
}
 
int main() {  
	const int WIDTH  = 4;
	const int HEIGHT = 6;
	int table_of_numbers[WIDTH][HEIGHT];
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			table_of_numbers[i][j] = rndNumber ();
		}
	}

	cout << "Matrix:" << endl;
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			cout << table_of_numbers[i][j] << "   ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < WIDTH; i++) {
		int minIndex = 0;
		int maxIndex = 0;
		int min = table_of_numbers[i][0];
		int max = table_of_numbers[i][0];
		for (int j = 0; j < HEIGHT; j++) {
			if (min > table_of_numbers[i][j]) {
				min = table_of_numbers[i][j];
				minIndex = j;
			}
			if (max < table_of_numbers[i][j]) {
				max = table_of_numbers[i][j];
				maxIndex = j;					
			}
		}
		table_of_numbers[i][minIndex] = max;
		table_of_numbers[i][maxIndex] = min;
	}

	cout << "Changed matrix: " << endl;	
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			cout << table_of_numbers[i][j] << "   ";
                }
		cout << endl;
	}
	cout << endl;

	return 0;
}
 
