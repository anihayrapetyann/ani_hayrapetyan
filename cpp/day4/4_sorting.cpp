#include <iostream> 
#include <stdlib.h>
using namespace std;

double rndNumber (int a, int b) {
        int random = rand () % (10 * b - 10 * a + 1) + 10 * a;
        return random / 10.0;
}

int main () {
	int i, j, m, n;
	float arr [100];
	cout << "Enter size of array. ";
	cin >> n;
	cout << endl;
	for (i = 0; i < n; i++) {
		arr [i] = rndNumber (-100, 100);
	}
	cout << "Elements of array are - ";
	for (i = 0; i < n; i++) {
		cout << arr [i];
		if (i == n - 1) {
			cout << " ";
		}
		else {
			cout << ", ";
		}
	}
	for (i = 0; i < n; i++) {		
		for ( j = i + 1; j < n; j++) {
			if (arr [i] > arr [j]) {
				m = arr [i];
				arr [i] = arr [j];
				arr [j] = m;
			}
		}
	}
	cout << "\nThe elements of sorting array are - ";
	for (i = 0; i < n; i++) {
		cout << arr [i];
		if (i == n - 1) {
			cout << " ";
		}
		else {
			cout << ", ";
		}
	}
	cout << endl;

	return 0;
}

