#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int start;
	cout << "for hy-en press 1\nfor en-hy press 0\n";
	cin >> start;
	cout << "enter the text\n";
	string sentence = " ";
	cin.ignore();
	getline (cin, sentence);
	string sentence_word [sentence.size()];
	int x = 0;

	for (int i = 0; sentence[i] != '\0'; i++ ) {
		if ('A' <= sentence[i] && sentence[i] <= 'Z') {
			sentence[i] = sentence[i] + ('a' - 'A');
		}
		if (sentence[i] == ' ') {
			x++;
			continue;
		}
		sentence_word[x] += sentence[i];
	}

	string word = "";	
	if (start == 1) {
		ifstream hy_en("hy-en.txt");
		while (hy_en >> word) {
			for (int i = 0; i < sentence.size(); i++) {
				if (sentence_word[i] == word) {
					hy_en >> word;
					hy_en >> word;
					cout << word << " ";
				}		
			}
		}
		hy_en.close();
	}
	else {
		ifstream en_hy("en-hy.txt");
		while (en_hy >> word) {
		    for (int i = 0; i < sentence.size(); i++) {
			    if (sentence_word[i] == word) {
				    en_hy >> word;
					en_hy >> word;
					cout << word << " ";
				} 
			}
	    }
		en_hy.close();
	}
	cout << endl;

	return 0;
}
