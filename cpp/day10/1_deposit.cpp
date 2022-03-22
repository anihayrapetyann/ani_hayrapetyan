#include <iostream>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;

int main (int argc, char* argv[]) {
	assert(argc == 4);
	float deposit      = atof(argv[1]);
	float percentage   = atof(argv[2]) / 1200.0;
	int count_of_month = atoi(argv[3]);
	
	cout << fixed;
	cout << setprecision(2);

	time_t now = time(0);
	char* date_time = ctime(&now);
	string date[5];
	int j = 0;

	for (int i = 0; date_time[i] != '\0'; i++) {
		if (date_time[i] == ' ') {
			j++;
			continue;
		}
		date[j] += date_time[i];
	}

	int day = stoi(date[2]);
	int year = stoi(date[4]);
	int k;
	string months[13] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec", " "};

	for (int i = 0; i < 13; i++) {
		if (months[i] == date[1]) {
			k = i;
		}
	}	

	float sum_delta = 0.0;
	cout << "        Date         |      Prev deposit    |   current deposit  |   Added in this month  | \n";
	float delta;
	float current_deposit;

	for (int i = 1; i <= count_of_month; i++) {
		if(i == 1) {
			 delta = 0;
			 current_deposit = deposit;
		}
		else {
			delta = deposit * percentage;
			sum_delta += delta;
			current_deposit = delta + deposit;
			deposit = current_deposit;
		}
		if (k + 1 < 10) {
		 	cout << "   "  << day << "/ " 
				<< "0" << k+1<< "/" << " " 
				<< year << " " << "     |       "
				<< deposit << "      |      " 
				<< current_deposit << "     |        "
				<< delta << "          |           "
				<< endl;
		}
		if (k + 1 >= 10) {
			cout << "   "  << day 
				<< "/ " << k+1 << "/ " 
				<< year << " " << "     |       " 
				<< deposit << "      |      " 
				<< current_deposit << "     |        " 
				<< delta << "          |           " 
				<< endl;
		}
		k++;
		if (months[k] == " ") {
			year++;
			k = 0;
		}
	}
	cout << "Interest income: " << sum_delta << "amd\n";

	return 0;
}

