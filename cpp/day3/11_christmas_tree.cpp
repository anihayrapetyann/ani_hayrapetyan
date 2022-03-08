#include <iostream>
using namespace std;

void firstTriangle (int height) {
	int i = height;
	while (i > 0) {
                int j = 1;
                while (j <= i) {
                        cout << "*";
                        j++;
                }
                cout << endl;
                i--;
        }
}  

void secondTriangle (int height) {
	int i = 1;
        while (i <= height) {
               int j = 1;
               while (j <= i) {
                        cout << "*";
                        j++;
                }
                cout << endl;
                i++;
        }
}

void thirdTriangle (int height) {
	int  i = 1;
        while (i <= height) {
                int j = height;
                while (j >= 0) {
                        if (j < i) {
                                cout << "*";
                        }
                        else {
                                cout << " ";
                        }
                        j--;
                }
                cout << endl;
                i++;
        }
}

void fourthTriangle (int height) {
	int i = 1;
        while (i <= height) {
                int j = 1;
                while (j <= height - i) {
                        cout <<"  ";
                        j++;
                }
                j = 0;
                while (j != 2 * i - 1) {
                         cout << "* ";
                         ++j;
                }
                cout << endl;
                i++;
                j = 0;
        }

}

int main () {	        
       	int n;
	cout << "Enter the height\n";
	cin >> n;
	const int height = n;

	cout << "This is my first triangle\n";
	int i = height;
	firstTriangle (height);

	cout << endl << "this is my second triangle\n";
	i = 1;
	secondTriangle (height);

	cout << endl << "this is my third triangle\n";
        i = 1;
      	thirdTriangle (height);
 
	cout << endl << "this is my fourth triangle\n";
	i = 1;
	fourthTriangle (height);

	return 0;
}

