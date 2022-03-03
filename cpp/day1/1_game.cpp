#include <iostream>
using namespace std;

int main () {
	int n;
	int m;
        cout << "Input the number\n";
        cin >> n;
        cout << "Guess the number\n";
        cin >> m;
	do {    
		if (m==n){
			break;		
		}
		if (m>n) {
			cout << "Your number is bigger than mine\n";          
		}               
		else {
			cout << "Your number is smaller than mine\n";
		}            
		cin >> m;
	}   
	while (m!=n); 	
	if (m==n) {
		cout << "excellent!\n You guessed the number\n";
   	}   	

	return 0;
}
	
	
