#include <iostream>

using namespace std;

int main() {
	double first_number;
	double second_number;
	char oper;
	cout << "Enter the  first number \n";
	cin >> first_number;
	cout << "Enter the operator (add, subtract, multiply and divide)\n";
	cin >> oper;
	cout << "Enter the second number\n";
	cin >> second_number;
	switch (oper) {
		case '+':
			cout << first_number << " + " << second_number << " = " << first_number + second_number << endl;
			break;
		case '-':
			cout << first_number << " - " << second_number << " = " << first_number - second_number << endl;
			break;
		case '*':
			cout << first_number << " * " << second_number << " = " << first_number * second_number << endl;
			break;
		case '/':
			if (second_number == 0) { 
				cout << "Division is impossible.\n";
				break;
			}
			cout << first_number << " / " << second_number << " = " << first_number / second_number << endl;
			break;
		default:
			cout << "Please, try again";
		break;
	}

	return 0;
}

