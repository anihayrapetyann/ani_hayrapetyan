#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string  _day_of_week(int day) {
	 switch(day){
        case 1: return "Mon "; break;
        case 2: return "Tue "; break;
        case 3: return "Wed "; break;
        case 4: return "Thu "; break;
        case 5: return "Fri "; break;
        case 6: return "Sat "; break;
        case 7: return "Sun "; break;
    }
	return 0;
}

enum weekDay {
    monday = 1,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday,
    sunday
};

struct _diary {
	string note;
	string date;
	weekDay week_day;
} diary;

int main() {
	int chooseWD; 
	string command;
	while (command != "exit") {
		cout << "Enter the date: ";
		cin >> diary.date;
		string date = diary.date;
		diary.date += ".txt";
		ofstream notes("./notes/" + diary.date, ios::app);
		cout << "choose the weekday\n" << monday
			<< " " << tuesday << " " << wednesday 
			<< " " << thursday << " " << friday << " "
			<< saturday << " " << sunday;
		cin >> chooseWD;
		cout << "Enter the note: ";
		cin.ignore();
		getline (cin, diary.note);
		notes << _day_of_week(chooseWD) << " " << date << endl << "Note: " <<  diary.note << endl;
		cout << "If you want to add the note write <add>, otherwise write <exit>: ";
		cin >> command;
		if (command == "exit") {
			break;
		}	
		notes.close();
	}

	return 0;
}
