#include <iostream>
using namespace std;

bool isYearLeap (int y) {
	int i = 4;
	return (y % i == 0);
}

int main () {
	int year = 2022;
	int n = 0;
	while (n < 20) {
        	if (isYearLeap (year)) {
 			cout << year <<endl;
			n++;	
		}
		year++;
	}
return 0;
}



