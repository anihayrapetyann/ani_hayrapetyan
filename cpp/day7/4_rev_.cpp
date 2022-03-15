#include <iostream>
using namespace std;

void reverse (int *ptr, int *number) {
	int *p = ptr;
	int *firstPtr = ptr;
        int *lastPtr = ptr + *number - 1;
        while (p < ptr + *number - 1 ) {
                int tmp;
                if (firstPtr < lastPtr) {
                        tmp = *lastPtr;
                        *lastPtr = *firstPtr;
                        *firstPtr = tmp;
                        firstPtr++;
                        lastPtr--;
                }
                *(p++);
	} 
	p = ptr;
	cout << "The elements of reversed array are: ";
	while (p < ptr + *number) {
		cout << *(p++) << " ";
	}
}

int main () {
	int number;
        cout << "Enter the number of elements\n";
        cin >>number;
        int *arr = new int[number];
        int *p = arr;
        cout << "Enter the elements of array\n";
        while (p < arr + number) {
                cin >> *p++;
        }
        p = arr;
        cout << "The elements of array: ";
        while (p < arr + number) {
                cout <<  *p++ << " ";
        }
        cout << endl;
	reverse (arr, &number);
	cout << endl;

return 0;
}




