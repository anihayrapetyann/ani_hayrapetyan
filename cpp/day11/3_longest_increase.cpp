#include <iostream>
#include <random>
#include <ctime>

using namespace std;

mt19937 gen (time(0));

int myGenerator () {
	int rnd = gen() % 200 -50;
	return rnd;
}

int main  () {
	int n = 35;
	int arr[n];
	cout << "The array elements are: ";
	for (int i = 0; i < n; i++) {
		arr[i] = myGenerator();
		if (i < n-1) {
		cout << arr[i] << ", ";
		}
		else {
			cout << arr[i] << ".";
		}
	}
	cout << endl;
	int length = 1;
	int max = 1;
	int maxindex = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] > arr[i-1]) {
			length++;
		}
		else {  
			if (max < length) {
			max = length;
			maxindex = i - max;
			}
		length = 1;
		}
	}
	if (max < length) {
		max = length;
		maxindex = n - max;
	}
	cout << "The elements of longest increasing are: ";
	for (int i = maxindex; i < max + maxindex; i++) {
		if (i < max + maxindex - 1) {
			 cout << arr[i] << ", ";
		}
		else {
			cout << arr[i] << ".";
		}
	}
	cout << endl;

	return 0;
}
