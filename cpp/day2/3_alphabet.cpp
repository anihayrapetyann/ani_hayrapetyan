#include <iostream>

using namespace std;

int main() {
	char letter;
	cout << "Input the letter \n";
	cin >> letter;
	if (('a' <= letter && letter <= 'z') || ('A' <= letter && letter <= 'Z')) {
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
				cout << "The letter is vowel \n";
				break;
			default:
				cout << "The letter is consonant\n";
				break;
		}
	}
	else {
		cout << "The character is not an alphabet\n";	
	}

	return 0;
}

