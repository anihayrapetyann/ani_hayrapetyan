#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct HOTELS{
	string name;
	string city;
	unsigned int single_room;
	unsigned int double_room;
	unsigned int price_single_room;
	unsigned int price_double_room;
	string indoor_pool;
	string spa;
	string kids_club;
	string fitness;
	unsigned int stars;
	
	void show_all() {
		cout << "============================================================" << endl;
		cout << "Hotel name                               ||  " << name << endl;
		cout << "============================================================" << endl;
		cout << "City                                     ||  " << city << endl;
		cout << "============================================================" << endl;	
		cout << "The number of available single rooms     ||  " << single_room << endl;
		cout << "============================================================" << endl;
		cout << "The number of available double rooms     ||  " << double_room << endl;
		cout << "============================================================" << endl;
		cout << "The price of a single room               ||  " << price_single_room  << endl;
		cout << "============================================================" << endl;
		cout << "The price of a double room               ||  " << price_double_room << endl;
		cout << "============================================================" << endl;
		cout << "The number of indoor pools               ||  " << indoor_pool << endl;
		cout << "============================================================" << endl;
		cout << "The number of spa centres                ||  " << spa << endl;
		cout << "============================================================" << endl;
		cout << "The number of kids clubs                 ||  " << kids_club << endl;
		cout << "============================================================" << endl;
		cout << "The number of fitness centres            ||  " << fitness << endl;
		cout << "============================================================" << endl;
		cout << "The number of stars                      ||  " << stars << endl;
		cout << "                                  " << endl;
	}
};

string* strToArray(string str) {
	string* result = new string[8];
	int x = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ') {
			x++;
			continue;
		}
		result[x] += str[i];
	}
	return result;
}

int main() {
	int count;
	string lines;
	ifstream fiin("hotels.txt");
	while (getline(fiin, lines)) {
		count++;
	}
	fiin.close();	

	HOTELS hotel[count];
	ifstream fin("hotels.txt");
	string file;
	int i = 0;
	int pos_line = 0;
	string words_from_line[11];

	while (fin >> file) {
		words_from_line[i] = file;
		i++;
		if (i == 11) {
			for (int j = 0; j < 10; j++) {
				words_from_line[j].pop_back();
			}
			hotel[pos_line].name = words_from_line[0];
			hotel[pos_line].city = words_from_line[1];
			hotel[pos_line].single_room = atoi(words_from_line[2].c_str());
			hotel[pos_line].double_room = atoi(words_from_line[3].c_str());
			hotel[pos_line].price_single_room = atoi(words_from_line[4].c_str());
			hotel[pos_line].price_double_room = atoi( words_from_line[5].c_str());
			hotel[pos_line].indoor_pool =  words_from_line[6];
			hotel[pos_line].spa = words_from_line[7];
			hotel[pos_line].kids_club = words_from_line[8];
			hotel[pos_line].fitness = words_from_line[9];
			hotel[pos_line].stars = atoi(words_from_line[10].c_str());
			i = 0;
			pos_line++;
		}
	}
	
	fin.close();
	string filter;
	string chosen_filter;
	string command;

	while (command != "exit") {
	cout << "Choose a filter (hotel / city / stars): ";
	cin >> filter;
	cout << "Input the " << filter << ": ";
	cin >> chosen_filter;
	cout << endl;
	cin.ignore();
	for (int i = 0; i < pos_line; i++) {
		if (filter == "hotel" && hotel[i].name == chosen_filter 
			|| filter == "city" && hotel[i].city == chosen_filter
			|| filter == "stars" && hotel[i].stars == atoi (chosen_filter.c_str())) {
			hotel[i].show_all();
		}
	}
	if (filter == "hotel") {
		cout << "\nChoose the type of room (singleRoom or doubleRoom): ";
	}
	else {
		cout << "\nChoose the hotel and the type of room (singleRoom or doubleRoom): ";
	}

	string client_choice;
	getline (cin, client_choice);
	string* words_from_string = strToArray(client_choice);
	int j = 0;

		for (int i = 0; i < pos_line; i++) {
			if (words_from_string[j] == hotel[i].name
				&& words_from_string[j + 1] == "doubleRoom" 
				|| words_from_string[j] == "doubleRoom") {
				if (hotel[i].double_room == 0) {
					cout << "\nNo available double rooms in " << hotel[i].name << " hotel\n\n";
					break;
				}
				hotel[i].double_room--;
			}
			else if (words_from_string[j] == hotel[i].name 
					&& words_from_string[j + 1] == "singleRoom" 
					|| words_from_string[j] == "singleRoom") {
						if (hotel[i].single_room == 0) {
							cout << "\nNo available single rooms in " << hotel[i].name << " hotel\n\n";
							break;
						}
						hotel[i].single_room--;
			}
		}
	
		cout << "If you want to book a room type <book>, else type <exit> : ";
		cin >> command;
		cin.ignore();

		if (command == "exit") {
			break;
		}
		if ( command != "book") {
			cout << "invalid command\n";
			break; 
		}
	}

	return 0;
}
