#include <iostream>
#include <fstream>

using namespace std;

struct Cars{
	string brand;
	int price;
	int mileage;
	float engine;
	string gear_box;
	string colour;
	
	void show() {
		cout << "==================================" << endl;
		cout << "   Car brand   ||  " << brand << endl;
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
	const int SIZE = 7;
	Cars car[SIZE];
	ifstream fin("cars.txt");
	string file;
	int i = 0;
	int pos_line = 0;
	string words_from_line[6];

	while (fin >> file) {
		words_from_line[i] = file;
		i++;
		if (i == 6) {
			for (int j = 0; j < 5; j++) {
				words_from_line[j].pop_back();
			}
			car[pos_line].brand = words_from_line[0];
			car[pos_line].price = atoi(words_from_line[1].c_str());
			car[pos_line].mileage = atoi(words_from_line[2].c_str());
			car[pos_line].engine = atof(words_from_line[3].c_str());
			car[pos_line].gear_box = words_from_line[4];
			car[pos_line].colour = words_from_line[5];
			i = 0;
			pos_line++;
		}
	}
	fin.close();

	string filter;
	string choosen_filter;
	cout << "Choose the filter (brand / price / miliage / engine / gearbox / colour)\n";
	cin >> filter;
	int min, max;

	if (filter == "price") {
		cout << "min price : ";
		cin >> min;
		cout << "max : ";
        cin >> max; 
    } 
	else { 
		cout << "Input " << filter << " : ";
		cin >> choosen_filter;
	}
	cout << endl;

	for (int i = 0; i < SIZE; i++) {
		if ( choosen_filter == car[i].brand || atof(choosen_filter.c_str()) == car[i].engine 
			|| atoi(choosen_filter.c_str()) == car[i].mileage || choosen_filter == car[i].gear_box
			|| choosen_filter == car[i].colour) {
				car[i].show();
		}
		if (filter == "price" && min <= car[i].price && car[i].price <= max) {
			car[i].show();
		}
	}

	return 0;
}
