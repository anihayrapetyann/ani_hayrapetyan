#include <iostream>
using namespace std;

int main () {
	int size = 10;
	int array[size];
	int i;
	int *firstPtr = array;
	int *lastPtr = array + size - 1;
	cout << "Enter the elements of array:\n";
	for (int i = 0; i < size; i++) {
		cin >> array[i];
	}
	cout << endl;
	i = 0;
	while (i <= size/2) {
		int tmp;
		if (firstPtr < lastPtr) {
			tmp = *lastPtr;
			*lastPtr = *firstPtr;
			*firstPtr = tmp;
			firstPtr++;
			lastPtr--;
		}
		i++;
	}
	for (  i = 0; i < size; i++) {
		cout << array[i] << endl;
	}

return 0;
}




