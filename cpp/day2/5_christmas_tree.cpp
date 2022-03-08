#include <iostream>
using namespace std;

int main () {	        
       	int n;
	cout << "Enter the height\n";
	cin >> n;
	const int height = n;

	cout << "This is my first triangle\n";
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

	cout << endl << "this is my second triangle\n";
	i = 1;
	while (i <= height) {
               int j = 1;
               while (j <= i) {
                        cout << "*";
                        j++;
                }
        	cout << endl;
       		i++;
        }

	cout << endl << "this is my third triangle\n";
        i = 1;
        while (i <= height) {
                int j = height;
                while (j >= 0) {
                        if (j < i) {
                                cout << "*";
                        }
                        else{
                                cout << " ";
                        }
                        j--;
                }
                cout << endl;
                i++;
        }
 
	cout << endl << "this is my fourth triangle\n";
	i = 1;
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
	return 0;
}

