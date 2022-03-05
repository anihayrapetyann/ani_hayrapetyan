#include <iostream>
using namespace std;

int main () {
        int monthnumber;
        cout << "Enter the number of month, to know the total number of its days \n";
        cin >> monthnumber;
        switch (monthnumber) {
                case 1:
                        cout << "Total number of days = 31 \n";
                        break;
                case 2:
                        cout << "Total number of days = 28 \n(for leap years total number of days = 29) \n ";
                        break;
                case 3:
                        cout << "Total number of days = 31 \n";
                        break;
                case 4:
                        cout << "Total number of days = 30 \n";
                        break;
                case 5:
                        cout << "Total number of days = 31 \n";
                        break;
                case 6:
                        cout << "Total number of days = 30 \n";
                        break;
                case 7:
                        cout << "Total number of days = 31 \n";
                        break;
		case 8:
                        cout << "Total number of days = 31 \n";
                        break;
		case 9:
                        cout << "Total number of days = 30 \n";
                        break;
		case 10:
                        cout << "Total number of days = 31 \n";
                        break;
		case 11:
                        cout << "Total number of days = 30 \n";
                        break;
		case 12:
                        cout << "Total number of days = 31 \n";
                        break;

                default:
                        cout << "The year has 12 months \n";
                        break;
        }
        return 0;
}

