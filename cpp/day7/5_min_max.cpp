#include <iostream>

using namespace std;

int main() {
	int size = 6;
	int nums[size];
	int *counterptr;
	int *maxptr, *minptr;
	maxptr = &nums[0];
	minptr = &nums[0];
	cout << "Enter the array values" << endl;
	for (counterptr = nums; counterptr < nums + size; counterptr++) {
		cin >> *counterptr;
		if (*counterptr > *maxptr) {
			maxptr = counterptr;
		}
		if (*counterptr < *minptr) {
			minptr = counterptr;
		}
	}
	cout << "max value = " << *maxptr << endl;
	cout << "min value = "<< *minptr << endl;
    
    return 0;
}
