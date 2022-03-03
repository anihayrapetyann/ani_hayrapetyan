#include <iostream>
using namespace std;
int main () {
        int num;
        int m=1;
        int multiple=1;
        cout << "input the number ";
        cin >> num;
        while (m<=10) {
		multiple=num * m;
        	cout << num << "*" << m << "=" << multiple <<endl;
       		m++;  
	}
        return 0;
}


