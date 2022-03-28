#include <iostream>

using namespace std;

int main () {
	long long int seconds;
	cin >> seconds;
	int mod = seconds % 31556926;
	long int year = 1970 + seconds / 31556926;
	cout << mod << endl;
	int months = 1 + mod /2629743;
	mod = mod % 2629743;
	int day;
	day = mod / 86400;
	mod = mod % 86400;
	int hour = mod / 3600;
	mod = mod % 3600;
	int minutes = mod / 60;	

	switch (months) {
		case 1:  cout << "Jan "; break;
		case 2:  cout << "Feb "; break;
		case 3:  cout << "Mar "; break;
		case 4:  cout << "Apr "; break;
		case 5:  cout << "May "; break;
		case 6:  cout << "Jun "; break;
		case 7:  cout << "Jul "; break;
		case 8:  cout << "Aug "; break;
		case 9:  cout << "Sep "; break;
		case 10: cout << "Oct "; break;
		case 11: cout << "Nov "; break;
		case 12: cout << "Dec "; break;			
	}
	cout << day  << " ";
	cout << year << " ";
	cout << hour << ":";
	cout << minutes << endl;

	return 0;
}
