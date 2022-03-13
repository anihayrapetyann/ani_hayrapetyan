#include <iostream>
#include <ctime>
#include <random>

using namespace std;

mt19937 gen (time (0));

double myGenerator () {
	int rnd_number = gen () % 100;
	return rnd_number;
}

int main () {
	const int SIZE = 10;
	int arr[SIZE];
	int number1, number2, sum;
	int i = 0;
	while (i < SIZE) {
		number1 = myGenerator ();
		number2 = myGenerator ();
		sum = number1 * number1 + number2 * number2;
		if (sum % 5 == 0) {
			arr[i] = sum;
	    		cout << number1 * number1 << " + " << number2 * number2 << " = " << arr[i] << endl;
			i++;
		}
	}

    return 0;
  }
