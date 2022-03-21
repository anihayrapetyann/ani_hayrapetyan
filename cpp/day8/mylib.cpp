#include "mylib.h"

int myAtoi (char* str) {
	int res = 0;
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] >= 48 && str[i] <= 57) {
			res = res * 10 + str[i] - '0';
		}
		else {
			res = 0;
		}
	}
	if (str[0] == '-') {
		res -= res * 2;
	} 
	return res;	
}

