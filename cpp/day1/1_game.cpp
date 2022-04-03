#include <iostream>

using namespace std;

int main () {
	int input_number;
	int guess_number;
        cout << "Input the number\n";
        cin >> input_number;
        cout << "Guess the number\n";
        cin >> guess_number;
	do {    
		if (guess_number == input_number){
			break;		
		}
		if (guess_number > input_number) {
			cout << "Your number is bigger than mine\n";          
		}               
		else {
			cout << "Your number is smaller than mine\n";
		}            
		cin >> guess_number;
	}   
	while (guess_number != input_number); 	
	if (guess_number == input_number) {
		cout << "excellent!\nYou guessed the number\n";
   	}   	

	return 0;
}
	
	
