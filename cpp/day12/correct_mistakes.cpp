#include <iostream>
#include <fstream>

using namespace std;

int main() {
	string sentence = " ";
	getline (cin, sentence);
	string sentence_word [sentence.size()];
	int x = 0;

	for (int i = 0; sentence[i] != '\0'; i++ ) {
		if('A' <= sentence[i] && sentence[i] <= 'Z') {
			sentence[i] = sentence[i] + ('a' - 'A');
		}
		if (sentence[i] == ' ') {
			x++;
			continue;
		}
		sentence_word[x] += sentence[i];
	}

	string word = "";	
	int j = 0;
	ifstream f_dictionary("dictionary.txt");

	while (f_dictionary >> word) {
		for (int i = 0; i < sentence.size(); i++) {
			if (sentence_word[i].size() == word.size()) {
				for (int k = 0; k < sentence_word[i].size(); k++) {
					if (sentence_word[i][k] == word[k]) {
						j++;		
						if (j == (sentence_word[i].size() - 1)) {
							sentence_word[i] = word;
						}
					}
				}
			}		
		}
		j = 0;
	}

	f_dictionary.close();
	ofstream fcin("correct.txt");

	for (int i = 0; i < sentence.size(); i++) {	
		fcin << sentence_word[i] << " ";  
		cout << sentence_word[i] << " ";
	}

	cout << endl;
	fcin.close();
	
	return 0;
}
