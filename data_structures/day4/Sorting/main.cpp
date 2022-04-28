#include <iostream>
#include <time.h>
#include "my_generator.hpp"
#include "swap.hpp"
#include "sorting.hpp"
#include "print.hpp"

using namespace std;

int main() {       
    const int size = 20;
    int arr1[size];
    int arr2[size];
    int arr3[size];
    int arr4[size];

    for(int i = 0; i < size;i++){
        arr1[i] =  MyGenerator();
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
    }

    clock_t start1 = clock();
    int *ptr1 = arr1;
    ptr1 = BubbleSort(arr1, size); 
    clock_t end1 = clock();
    double elapsed1 = double(end1- start1)/CLOCKS_PER_SEC;
    cout <<"           Bubble sorting             " << endl;
    cout << "======================================" << endl;
    cout <<"      Size         |     Runtime     " << endl;
    cout << "       " << size << "          |    " 
         << elapsed1 * 1000000 << " seconds\n\n" << endl;
  //  Print(ptr1, size);

    clock_t start2 = clock();
    int *ptr2 = arr2;
    ptr2 = InsertionSort(arr2, size);
    clock_t end2 = clock();
    double elapsed2 = double(end2- start2)/CLOCKS_PER_SEC;
    cout <<"           Insertion sorting             " << endl;
    cout << "======================================" << endl;
    cout <<"      Size         |     Runtime     " << endl;
    cout << "       " << size << "          |    " 
         << elapsed2 * 1000000 << " seconds\n\n" << endl;
  //  Print(ptr2, size);

    
    clock_t start3 = clock();
    int* ptr3 = MergeSort(arr3, size);
    clock_t end3 = clock();
    double elapsed3 = double(end3- start3)/CLOCKS_PER_SEC;
    cout <<"           Merge sorting             " << endl;
    cout << "======================================" << endl;
    cout <<"      Size         |     Runtime     " << endl;
    cout << "       " << size << "          |    " 
         << elapsed3 * 1000000 << " seconds\n\n" << endl;
    //Print(ptr3, size);

    clock_t start4 = clock();
    QuickSort(arr4, 0, size - 1);
    clock_t end4 = clock();
    double elapsed4 = double(end4 - start4)/CLOCKS_PER_SEC;
    cout <<"           Quick sorting             " << endl;
    cout << "======================================" << endl;
    cout <<"      Size         |     Runtime     " << endl;
    cout << "       " << size << "          |    " 
         << elapsed4 * 1000000 << " seconds\n\n" << endl;
    //Print(arr4, size);

    return 0;
}
