#include <iostream>

using namespace std;

void print (string weekday) {
	cout << weekday << endl;
}

int main () {
	int order;
	cout << "Enter the number of week (1-7) \n";
	cin >> order;
	switch (order) {
		case 1:
			print ("Monday");
			break;
		case 2: 
			print ("Tuesday");
			break;
		case 3:
			print ("Wednesday");
			break;
		case 4:
			print ("Thursday");
			break;
		case 5: 
			print ("Friday");
			break;
		case 6:
			print ("Saturday");
			break;
		case 7:	
			print ("Sunday");
			break;
		default:
			cout << "The week has only 7 days\n";
			break;
	}	
	return 0;
}
