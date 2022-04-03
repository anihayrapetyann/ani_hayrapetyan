#include <iostream>
using namespace std;

void print ( string days ) {
	if ( days == "WARNING" ) {
		cout << "The year has 12 months\n";
		return;
	}
	cout << "The total number of days is " << days << endl; 
}

int main() {
    int month_number;
    cout << "Enter the number of month, to know the total number of its days \n";
    cin >> month_number;
    switch ( month_number ) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			print ( "31" );
			break;
		case 2: 
			print ( "28 or 29" );
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			print ("30");
			break;
		default:
			print ( "WARNING" );
            break;
    }

	return 0;
}

