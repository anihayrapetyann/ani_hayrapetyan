# include <iostream>
# include <fstream>

using namespace std;

int main () {
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

	 cout << "Input the name of the hotel: ";
	cin >> name;
	string check;
	ifstream fin("hotels.txt");

	while (fin >> check) {
		check.pop_back();
		if (name == check) {
			cout << "The hotel is already registered" << endl;
			fin.close();
			return 0;
		}
	}

	cout << "Input the name of the city: ";
	cin >> city;
	cout << "Input the number of single_room rooms: ";
	cin >> single_room;
	cout << "Input the number of double_room rooms: ";
	cin >> double_room;
	cout << "Input the price of single_room rooms: ";
	cin >> price_single_room;
	cout << "Input the price of double_room rooms: ";
	cin >> price_double_room;
	cout << "Input the number of indoor pools: ";
	cin >> indoor_pool;
	cout << "Input the number of spas: ";
	cin >> spa;
	cout << "Input the number of clubs for kids: ";
	cin >> kids_club;
	cout << "Input the number of fitness clubs: ";
	cin >> fitness;
	cout << "Input the number of stars: ";
	cin >> stars;
	cout << "You have successfully registered the hotel\n";

	ofstream add;
	add.open ("./hotels.txt", ios::app);
	add << name << ", " << city << ", " << single_room 
		<< ", " << double_room << ", " << price_single_room 
		<< ", " << price_double_room << ", " << indoor_pool 
		<< ", " << spa << ", " << kids_club << ", " 
		<< fitness << ", " << stars << endl;
        add.close();

	return 0;
}
