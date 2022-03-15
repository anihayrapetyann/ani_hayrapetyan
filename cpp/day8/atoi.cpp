#include <iostream>
#include "mylib.h"
using namespace std;

int main (int argc, char *argv[]) {
	int sum1, sum2;
	sum1 = 0;
	sum2 = 0;
	for (int i = 1; argv[i] != NULL; ++i) {
		sum1 += myAtoi(argv[i]);
		sum2 += atoi (argv[i]);
	}
	cout << "My atoi: "<< sum1 << endl;
	cout << "Atoi: " << sum2 << endl;
   
    return 0;
}
