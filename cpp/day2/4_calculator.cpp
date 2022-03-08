#include <iostream>
using namespace std;

int main () {
        double firstnumber;
	double secondnumber;
	char oper;
        cout << "Enter the  first number \n";
	cin >> firstnumber;
	cout << "Enter the operator (add, subtract, multiply and divide)\n";
	cin >> oper;
	cout << "Enter the second number\n";
        cin >> secondnumber;
        switch ( oper ) {
                case '+':
                        cout << firstnumber << '+' << secondnumber << '=' <<firstnumber + secondnumber << endl;
			break;
		case '-':
                        cout << firstnumber << '-' << secondnumber << '=' <<firstnumber - secondnumber << endl;
                        break;
		case '*':
                        cout << firstnumber << '*' << secondnumber << '=' <<firstnumber * secondnumber << endl;
                        break;
		case '/':
			if ( secondnumber == 0 ) { 
				cout << "Division is impossible.\n";
				break;
			}
                        cout << firstnumber << '/' << secondnumber << '=' <<firstnumber / secondnumber << endl;
                        break;
                default:
                        cout << "Please, try again";
                        break;
        }
        return 0;
}

