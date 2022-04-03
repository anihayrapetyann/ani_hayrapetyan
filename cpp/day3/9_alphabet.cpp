#include <iostream>

using namespace std;

void print (char letter) {
	switch (letter) {
		case 'a':
		case 'e':
		case 'i':
		case 'u':
		case 'o':
		case 'A':
		case 'E':
		case 'I':
		case 'U':
		case 'O':
			cout << "the letter is vowel\n";
			break;
		default:
			cout << "The letter is consonant\n";
			break;
	}
}

int main() {
    char letter;
    cout << "Input the letter \n";
    cin >> letter;
	if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')) {
		print (letter);        
	}
	else {
		cout << "The " << letter << " is not an alphabet\n";
	}
 
	return 0;
}

