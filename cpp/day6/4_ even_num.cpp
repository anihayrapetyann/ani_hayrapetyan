#include <iostream>
#include <random>
#include <ctime>

using namespace std;

mt19937 gen(time(0));

int rndNumber () {
        int random = gen () % 100 +1;
        return random;
}

int main() {
	const int WIDTH  = 5;
	const int HEIGHT = 6;
	int table_of_numbers[HEIGHT][WIDTH];
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			table_of_numbers[i][j] = rndNumber ();
		}
	}
	cout << "Matrix:" << endl;
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			if (table_of_numbers[i][j] < 10) { 
				 cout << table_of_numbers[i][j] << "   ";
			}
			else {
				 cout << table_of_numbers[i][j] << "  ";
			}
		}
		cout << endl;
	}
	cout << endl;
	int line_num = 0;
	for (int i = 0; i < WIDTH; i++) {
		int count = 0;
		for (int j = 0; j < HEIGHT; j++) {
			if( table_of_numbers[i][j] % 2 == 0){
				count ++;
			} 
                }
		if (count == HEIGHT && line_num == 0) {	
			line_num++;
			cout << i + 1 << endl;
		}
	}
	if (line_num == 0) {
		cout << "No" << endl;
	}

	return 0;
}
