#include <iostream>

using namespace std;

int main() {
	int current_year = 2022;
    int i = 4;
	int j = 0;
	cout << "The next 20 leap years are:\n";
	while (j < 20) {
        if (current_year % i == 0) {
			cout << current_year << endl;
			j++;	
		}
	current_year++;
	}

	return 0;
}



