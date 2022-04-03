#include <iostream>

using namespace std;

int main() {
        int chicken;
        int cow;
        int pig;
        int sum;
        cout << "chicken - ";
        cin >> chicken;
        cout << "cow - ";
        cin >> cow;
        cout << "pig - ";
        cin >> pig;
        sum = (chicken * 2) + (cow * 4) + (pig * 4);
        cout << "The total number of legs is: " << sum << endl;

	return 0;
}

