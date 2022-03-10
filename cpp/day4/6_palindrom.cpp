#include <iostream>
using namespace std;

char lowerToUpper (char letter) {
	if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')) { 
		if (letter >= 'a' && letter <= 'z') {
			letter = ('A' + letter - 'a');
		}	
	}
	return letter;
}

bool isPalindrome (string word) {
	int size = 0;
	int i;
	for (i = 0; word [i] != '\0'; i++) {
		size++;
	}       
	for (i = 0; i < size / 2; i++) {
                if (lowerToUpper (word [i]) != lowerToUpper (word [size - i -1])) {
			cout << "The word is not palindrome \n";
			return false;
		}
	}
	cout << "The word is palindrome \n";
	return true;
}

int main () {
	string word;
	cout << "Enter some word \n";
	cin >> word;
	isPalindrome (word);

	return 0;
}
