#include <iostream>
using namespace std;

int main () {
        int monthnumber;
        cout << "Enter the number of month, to know the total number of its days \n";
        cin >> monthnumber;
        switch (monthnumber) {
                case 1:
                case 3:
                case 5:
                case 7:
		case 8:
		case 10:
		case 12:
                        cout << "Total number of days = 31 \n";
                        break;
		case 2:
                        cout << "Total number of days = 28 \n(for leap years total number of days = 29) \n ";
                        break;
		case 4:
		case 6:
		case 9:	
		case 11:
			cout << "Total number of days = 30 \n";
                        break;
                default:
                        cout << "The year has 12 months \n";
                        break;
        }
        return 0;
}

