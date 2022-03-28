#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

enum PhoneCodes {
	Brazil = 55,
	China  = 86,
	Germany = 49,
	India = 91,
	Iran = 98,
	United_States = 1,
	Russia = 7,
	United_Kingdom = 44,
	Armenia = 374,
	France = 33 
};

struct Country {
	string country_name;
	string capital;
	string domain;
	int population;
	int area;
	long long GDP;

	void show() {
		cout << "Country name : " << country_name << endl;
		cout << "Capital name : " << capital << endl;
		cout << "Domain name  : " << domain << endl;
		cout << "Population   : " << population << endl;
		cout << "Area         : " << area << endl;
		cout << "GDP          : " << GDP << endl; 
	}
};

int main(int argc, char* argv[]) {
	Country country[11];
	PhoneCodes code;
	ifstream fin("country.txt");
	string line;
	int i = 0;
	int pos_line = 0;
	string words_from_line[6];
	while (fin >> line) {
		words_from_line[i] = line;
		i++;
		if (i == 6) {
			for (int j = 0; j < 5; j++) {
				words_from_line[j].pop_back();
			}
			country[pos_line].country_name = words_from_line[0];
			country[pos_line].capital = words_from_line[1];
			country[pos_line].domain = words_from_line[2];
			country[pos_line].population = atoi(words_from_line[3].c_str());
			country[pos_line].area = atoi(words_from_line[4].c_str());
			country[pos_line].GDP = atoll(words_from_line[5].c_str());
			i = 0;
			pos_line++;
		}
	}
	fin.close();

	if (strcmp(argv[1], "search") == 0) {
		string search;
		string choice;
		cout << "Input search mode (countryName / capital / domain)\n";
		cin >> search;
		cout << "Input " << search << ": ";
		cin >> choice;
		for (int i = 0; i < 11; i++) {
			if (country[i].country_name == choice || country[i].capital == choice || country[i].domain == choice) {
				country[i].show();
				if (country[i].country_name == "China")   cout << "Phone Code  " << " : +" << China << endl;
				if (country[i].country_name == "Brazil")  cout << "Phone Code  " << " : +" << Brazil << endl;
				if (country[i].country_name == "Germany") cout << "Phone Code  " << " : +" << Germany << endl;
				if (country[i].country_name == "India")   cout << "Phone Code  " << " : +" << India << endl;
				if (country[i].country_name == "Iran")    cout << "Phone Code  " << " : +" << Iran << endl;
				if (country[i].country_name == "US")      cout << "Phone Code  " << " : +" << United_States << endl;
				if (country[i].country_name == "Russia")  cout << "Phone Code  " << " : +" << Russia << endl;
				if (country[i].country_name == "UK")      cout << "Phone Code  " << " : +" << United_Kingdom << endl;
				if (country[i].country_name == "France")  cout << "Phone Code  " << " : +" << France << endl;
				if (country[i].country_name == "Armenia") cout << "Phone Code  " << " : +" << Armenia << endl;
			}
		}
	} 
	else if (strcmp (argv[1], "compare") == 0) {
		string first_country;
		string second_country;
		cout << "Input first country: ";
		cin >> first_country;
		cout << "Input second country: ";
		cin >> second_country;
		int x, y;
        for (int i = 0; i < 11; i++) {
            if (first_country == country[i].country_name) {
                x = i;
            }
            if (second_country == country[i].country_name) {
                y = i;
            }
        }
		cout << "========================================" << endl;
        cout << "\t\t|" << country[x].country_name << "\t|" << country[y].country_name << endl;
        cout << "========================================" << endl;
        cout << "Capital"
             << "\t\t|" << country[x].capital << "\t|" << country[y].capital << endl;
        cout << "Domain"
             << "\t\t|" << country[x].domain << "\t\t|" << country[y].domain << endl;
        if (country[x].population > country[y].population) {
            cout << "Population"
                 << "\t|" << country[x].population << "\t> " << country[y].population << endl;
        }
        else if (country[x].population < country[y].population) {
            cout << "Population"
                 << "\t|" << country[x].population << "\t< " << country[y].population << endl;
        }
        else {
            cout << "Population"
                 << "\t|" << country[x].population << "\t= " << country[y].population << endl;
        }
        if (country[x].area > country[y].area) {
            cout << "Area"
                 << "\t\t|" << country[x].area << "\t> " << country[y].area << endl;
        }
        else if (country[x].area < country[y].area) {
            cout << "Area"
                 << "\t\t|" << country[x].area << "\t< " << country[y].area << endl;
        }
        else {
            cout << "Area"
                 << "\t\t|" << country[x].area << "\t= " << country[y].area << endl;
        }
        if (country[x].GDP > country[y].GDP) {
            cout << "GDP"
                 << "\t\t|" << country[x].GDP << "\t> " << country[y].GDP << endl;
        }
        else if (country[x].GDP < country[y].GDP) {
            cout << "GDP"
                 << "\t\t|" << country[x].GDP << "\t< " << country[y].GDP << endl;
        }
        else {
            cout << "GDP"
                 << "\t\t|" << country[x].GDP << "\t= " << country[y].GDP << endl;
        }
    
	}
	else {
	    cout << "Invalid command!\n";
	}

	return 0;
}
