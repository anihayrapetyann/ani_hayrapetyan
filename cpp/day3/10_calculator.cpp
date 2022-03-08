#include <iostream>
using namespace std;

float sum (float a, float b) {
	return a + b;
}
float subtract (float a, float b) {
	return a - b;
}
float multiple (float a, float b) {
        return a * b;
}
float devide (float a, float b) {
	if (b == 0) {
		cout << "The number cannot be devided by zero" << endl;
		return 0;
	}		       
	return a / b;
}

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
        switch (oper) {
                case '+': {
			float result = sum (firstnumber, secondnumber);                       
			cout << firstnumber << '+' << secondnumber << '=' <<result << endl;
			break;
		}
		case '-': {
                        float result = subtract (firstnumber, secondnumber);
			cout << firstnumber << '-' << secondnumber << '=' <<result << endl;
                        break;
		}
		case '*': {
			float result = multiple (firstnumber, secondnumber);
                        cout << firstnumber << '*' << secondnumber << '=' << multiple << endl;
                        break;
		}
		case '/': {
			if (secondnumber == 0) {
				cout << "Division is impossible\n";
				break;
			}
			float result = devide (firstnumber, secondnumber);
                        cout << firstnumber << '/' << secondnumber << '=' <<result << endl;
                        break;
                }
                default:
                        cout << "Please, try again";
                        break;
        }
        return 0;
}

