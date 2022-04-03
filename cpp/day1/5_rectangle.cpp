#include <iostream>

using namespace std;

int main() {
	int length;
	int width;
	int perimeter;
	int area;
	cout << "Input length of rectangle\n";
	cin >> length;
	cout << "Input the width of rectangle\n";
	cin >> width;
    perimeter = (length + width) * 2;
	cout << "The perimeter of rectangle is " << perimeter <<endl;
	area = length * width;
	cout << "the area of rectangle is " << area <<endl;
	
	return 0;
}


