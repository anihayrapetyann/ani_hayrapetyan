#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Cars{
	string brand;
	string model;
	int price;
	int mileage;
	int engine;
	string gear_box;
	string colour;
	
	void show() {
		cout << "==================================" << endl;
		cout << "   Car brand   ||  " << brand << endl;
		cout << "==================================" << endl;
		cout << "     Model     ||  " << model << endl;
		cout << "==================================" << endl;	
		cout << "   Price ($)   ||  " << price << endl;
		cout << "==================================" << endl;
		cout << "  Mileage (mi) ||  " << mileage << endl;
		cout << "==================================" << endl;
		cout << "   Engine (l)  ||  " << engine  << endl;
		cout << "==================================" << endl;
		cout << "    Gear box   ||  " << gear_box << endl;
		cout << "==================================" << endl;
		cout << "     Colour    ||  " << colour << endl;
		cout << "==================================" << endl;
		cout << "                                  " << endl;
	}
};

int main() {
	const int SIZE = 9;
	Cars car[SIZE];
	ifstream fin("cars.txt");
	string file;
	int i = 0;
	int pos_line = 0;
	string words_from_line[7];

	while (fin >> file) {
		words_from_line[i] = file;
		i++;
		if (i == 7) {
			for (int j = 0; j < 6; j++) {
				words_from_line[j].pop_back();
			}
			car[pos_line].brand = words_from_line[0];
			car[pos_line].model = words_from_line[1];
			car[pos_line].price = atoi(words_from_line[2].c_str());
			car[pos_line].mileage = atoi(words_from_line[3].c_str());
			car[pos_line].engine = atof(words_from_line[4].c_str());
			car[pos_line].gear_box = words_from_line[5];
			car[pos_line].colour = words_from_line[6];
			i = 0;
			pos_line++;
		}
	}
	fin.close();

	int n;
	int j = 0;
	string filter;
	string choosen_filter;
	cout << "How many filters do you want to choose? (1 - 7)\n";
	cin >> n;
	if (n > 7 || n < 1) {
		cout << "Invalid input\n";
		return 0;
	}
	cout << "Choose the filter (brand / model / price / miliage / engine / gearbox / colour)\n";
	cin.ignore();
	getline (cin, filter);
	string words_from_string[n];
	cout << "Input " << filter << " : ";
	getline (cin, choosen_filter);
		
	for (int i = 0; choosen_filter[i] != '\0'; i++) {
		if (choosen_filter[i] == ' ') {
			j++;
			continue;
		}
			words_from_string[j] += choosen_filter[i];
	}
	cout << endl;

	int	k = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < n; j++) {
			if ( words_from_string[j] == car[i].brand 
				|| words_from_string[j] == car[i].model
				|| atoi(words_from_string[j].c_str()) == car[i].price
				|| atoi(words_from_string[j].c_str()) == car[i].engine 
				|| atoi(words_from_string[j].c_str()) == car[i].mileage 
				|| words_from_string[j] == car[i].gear_box
				|| words_from_string[j] == car[i].colour) {
				k++;				
			}
			if (k == n) {
				car[i].show();
			}	
		}
		k = 0;
	}

	return 0;
}
