#include <iostream>

using namespace std;

void print (int n, int m) {
	do {
		if (m == n) {
			break;
        	}
        	if (m > n) {
			cout << "Your number is bigger than mine\n";
        	}
        	else {
			cout << "Your number is smaller than mine\n";
	        }
	        cin >> m;
	}
	while ( m != n );
	if ( m == n ) {
		cout << "excellent!\n You guessed the number\n";
	}
}

int main() {
	int input_number;
	int guess_number;
	cout << "Input the number\n";
	cin >> input_number;
	cout << "Guess the number\n";
	cin >> guess_number;
	print (input_number, guess_number);   	

	return 0;
}
	
	
