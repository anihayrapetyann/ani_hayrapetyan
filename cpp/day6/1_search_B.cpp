#include <iostream>

using namespace std;

int main () {
	string some_text;
	cout << "Enter some text.\n"; 
	getline (cin, some_text);	
	int number_of_b = 0;
	int number_of_word = 0;
	for (int i = 0; i < some_text.size(); i++) {
		if (some_text[i] == 'B') {
			number_of_b++;
		}
		if (some_text[i] == ' ' || i == some_text.size() - 1) {
			if (number_of_b == 2) {
				number_of_word++;	
			}
			number_of_b = 0;
		}
	}
	cout << "The number of words containing 2 B in a given text is:  " << number_of_word << endl;

	return 0;
}
