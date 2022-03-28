#include <iostream>
#include <string>

using namespace std;

int main() {
	int start;
	string cities [91] = {"Yerevan", "Stepanakert", "Goris", "Armavir", "Martuni", "Moscow", "London", "Rome", "Paris", "Budapest", "Vienna", "Barcelona", "Stockholm", "Novosibirsk", "Copenhagen", "Samara", "Kazan", "Donetsk", "Volgograd", "Odessa", "Perm", "Naples", "Turin", "Liverpool", "Riga", "Amsterdam", "Zagreb", "Krasnodar", "Krasnodar", "Krasnodar", "Essen", "Genoa", "Oslo", "Duesseldorf", "Goeteborg", "Goeteborg", "Lipetsk", "Hannover", "Astrakhan", "Skopje", "Leeds", "Cardiff", "Wandsbek", "Tallinn", "Florence", "Alicante", "Galati", "Bari", "Nis", "Altona", "Yakutsk", "Northampton", "Novi Sad", "Padova", "Cork", "Hamm", "Amadora", "Ipswich", "Oxford", "Albacete", "Neukoelln", "Warrington", "Zenica", "Rubtsovsk", "New York", "Los Angeles", "Phoenix", "Houston", "Banff", "Edmonton", "Jasper", "Delta", "Hope", "Nanaimo", "Penticton", "Quesnel", "Trail", "West Vancouver", "Churchill", "Thompson", "Gander", "Inuvik", "Pictou", "North Bay", "Ottawa", "Laval", "Magog", "Magog", "Flin Flon", "Saskatoon", "Uranium City"};
	cout << "If you want to start the game first, press 1.\nIf you want the computer to start the game first, press 0 \n";
	cin >> start;
	int i = 0;

    if (start == 1) {
		char check_letter;
		string name_of_city;
		cout << "write a name of city\n";
		int k = 0;
		for (i = 0; i < 91; i++) {
			cin >> name_of_city;
			if ((name_of_city[0] != check_letter) && (k > 0)) {
				cout << "Game over\n";
				return 0;
			}
			if ('a' <= name_of_city[name_of_city.size() -1] && name_of_city[name_of_city.size() -1] <= 'z') {
				name_of_city[name_of_city.size() -1] = name_of_city[name_of_city.size() -1] - ('a' - 'A');
			}
			int j = 0;
			int check = 0;
			while (j < 91 ) {
				if (name_of_city[name_of_city.size() - 1] != cities[j][0]) {
					check++;
				}
				if (check == 91) {
					cout << "You won!\n";
					return 0;
				}
				if (name_of_city[name_of_city.size() - 1] == cities[j][0]) {
					cout << cities[j] << endl;
					check_letter = cities[j].back();
					cities[j] = "1";
					k++;
					break;
   				}
				j++;
			}
		}
	}
 
	if (start == 0) {
		char check_letter;
		string name_of_city;
		int j = 0;
		cout << cities[0];
		check_letter = cities[0].back();
		cities[0] = "1";	
		for (i = 0; i < 91; i++) {
			cin >> name_of_city;
			if (name_of_city[0] != check_letter) {
				cout << "Game over\n";
				return 0;
            }
			if ('a' <= name_of_city[name_of_city.size() -1] && name_of_city[name_of_city.size() -1] <= 'z') {
				name_of_city[name_of_city.size() -1] = name_of_city[name_of_city.size() -1] - ('a' - 'A');
			}
			int j = 0;
			int check = 0;
			while (j < 91 ) {
				if (name_of_city[name_of_city.size() - 1] != cities[j][0]) {
					check++;
                }   
                if (check == 91) {
                    cout << "You won!\n";
                    return 0;
				}
                if (name_of_city[name_of_city.size() - 1] == cities[j][0]) {
                    cout << cities[j] << endl;
					check_letter = cities[j].back();
                    cities[j] = "1";
                    break;
                 }
				j++;
            }
        }
	}
	
	return 0;
}
