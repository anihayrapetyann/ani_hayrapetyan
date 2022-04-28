#ifndef SORTING_H
#define SORTING_H

#include "swap.hpp"

int* BubbleSort(int arr1[], int size ) {
for (int  i = 0; i < size; i++){
        bool checkSwap = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr1[j] > arr1[j + 1]) {
                int temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
                checkSwap = true;
            }
        }
        if(!checkSwap) {
            break;
        }
    }
    return arr1;
}
int* InsertionSort(int arr2[], int size) {
 for (int i = 1; i < size; i++ ) {
        for (int j = i; j  > 0; j--) {
            if (arr2[j] < arr2[j - 1]) {
                int temp = arr2[j];
                arr2[j] = arr2[j - 1];
                arr2[j - 1] = temp;
            }
        }
    }
    return arr2;
}

int* Merge(int arr1[], int arr2[], int size1, int size2) {
    int  temp1 = 0;
    int  temp2 = 0;

    int* arr3 = new int [size1 + size2];
    int  k = 0;
    while (temp1 < size1 && temp2 < size2) {
        while (temp1 < size1 && arr1[temp1] < arr2[temp2]) {
            arr3[k] = arr1[temp1];
            temp1++;
            k++;
        }
        while (temp2 < size2 && arr1[temp1] >= arr2[temp2]) {
            arr3[k] = arr2[temp2];
            temp2++;
            k++;
        }
    }
    if (temp1 == size1) {
        for (int i = temp2; i < size2; i++) {
            arr3[k] = arr2[i];
            k++;
        }
    } 
    else {
        for (int i = temp1; i < size1; i++) {
            arr3[k] = arr1[i];
            k++;
        }
    }
    return arr3;
}


int* MergeSort(int* arr, int size) {
    if (size == 1) {
        return arr;
    }
    int m = size / 2;
    int* arr1 = new int[m];
    int* arr2 = new int[size - m];
    for (int i = 0; i < m; i++) {
        arr1[i] = arr[i];
    }
    for (int i = 0; i < size - m; i++) {
        arr2[i] = arr[m + i];
    }
    arr1 = MergeSort(arr1, m);
    arr2 = MergeSort(arr2, size - m);
    return Merge(arr1, arr2, m, size - m);
}

int Partition(int arr[], int start, int end) {
	int pivot = arr[start];
	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}
	int pivotIndex = start + count;
	Swap(arr, pivotIndex, start);
    int i = start, j = end;
	while (i < pivotIndex && j > pivotIndex) {
		while (arr[i] <= pivot) {
			i++;
		}
		while (arr[j] > pivot) {
			j--;
		}
		if (i < pivotIndex && j > pivotIndex) {
			Swap(arr, i, j);
		}
	}
	return pivotIndex;
}

void QuickSort(int arr[], int start, int end) {
	if (start >= end)
		return;
	int p = Partition(arr, start, end);
	QuickSort(arr, start, p - 1);
	QuickSort(arr, p + 1, end);
}

#endif 