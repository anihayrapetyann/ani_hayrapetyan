#ifndef __PRINT_H__
#define __PRINT_H__

#include <iostream>

void Print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
    std::cout << std::endl;
}

#endif 