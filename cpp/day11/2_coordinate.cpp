#include <iostream>

using namespace std;

int main () {
	cout << " enter the coordinates\n";
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;
	cin >> x1 >> y1;
	int A[2] = {x1, y1};
	cin >> x2 >> y2;
	int B[2] = {x2, y2};
	cin >> x3 >> y3;
	int C[2] = {x3, y3};
	cin >> x4 >> y4;
	int D[2] = {x4, y4};
		if (A[1] == B[1] && C[0] == D[0] || A[0] == B[0] && C[1] == D[1]) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No\n"; 
		}

	return 0;
}
