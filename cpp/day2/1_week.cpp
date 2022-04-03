#include <iostream>

using namespace std;

int main (){
	int week_number;
	cout << "Enter the number of week (1-7) \n";
	cin >> week_number;
	switch (week_number) {
		case 1:
			cout << "Monday \n";
			break;
		case 2: 
			cout << "Tuesday\n";
			break;
		case 3:
			cout << "Wednesday\n";
			break;
		case 4:
			cout << "Thursday\n";
			break;
		case 5: 
			cout << "Friday\n";
			break;
		case 6:
			cout << "Saturday\n";
			break;
		case 7:	
			cout << "Sunday\n";
			break;
		default:
			cout << "The week has only 7 days\n";
			break;
	}	
	return 0;
}
