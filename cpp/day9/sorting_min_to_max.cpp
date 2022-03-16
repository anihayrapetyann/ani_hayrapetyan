#include <iostream>
#include <random>
#include <ctime>
#include "../my_lib/my_sorting.h"
using namespace std;

mt19937 gen (time(0));

int myGenerator (int a = 1, int b = 20) {
	int rand = gen () % (b - a + 1) + a;
	return rand;
}

/*void sort_min_max (int** matrix, int height, int width) {
	for (int* ptr = *matrix; ptr < *matrix + width; ptr++) {
		for (int** fpptr = matrix; fpptr < matrix + height - 1; fpptr++) {
			for (int** spptr = fpptr + 1; spptr < matrix + height; spptr++) {
				int a = *(*fpptr + (ptr - *matrix));
				int b = *(*spptr + (ptr - *matrix));
				if (a > b) { 
					*(*fpptr + (ptr - *matrix)) = b;
					*(*spptr + (ptr - *matrix)) = a;
				}
			}
		}
	}
}
*/
int main() {
	int n, m;
	cout << "Enter the hight of array\n";
	cin >> n;  
	cout << "Enter the width of array\n";
	cin >> m;
	const int N = n;
	const int M = m; 
	int** PTR = new int*[N];

	for (int** ptr = PTR; ptr < PTR + N; ptr++) {
		*ptr = new int[M];
	for (int* pptr = *ptr; pptr < *ptr + M; pptr++) {
		*pptr = myGenerator ();
		if (*pptr < 10) {
		cout << *pptr << "  ";
		}
		else {
		cout << *pptr << " ";
		}
	}
	cout << endl;
	}
	sort_min_max (PTR, N, M);
	cout << endl;

	for (int** ptr = PTR; ptr < PTR + N; ptr++) {
		for (int* pptr = *ptr; pptr < *ptr + M; pptr++) {
			if (*pptr < 10) {
				cout << *pptr << "  ";
			}
			else {
				cout << *pptr << " ";
			}
		}
	cout << endl;
	}

	return 0;
}

