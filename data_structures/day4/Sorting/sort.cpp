#include <iostream>
#include <time.h>
#include <random>

using namespace std;

mt19937 gen (time(0)); 

int MyGenerator() {
    int rand = gen() % 5000;
    return rand;
}

int main() {       
    const int size = 20000;
    int arr1[size];
    int arr2[size];

    for(int i = 0; i < size;i++){
        arr1[i] =  MyGenerator();
        arr2[i] = arr1[i];
    }
   
    clock_t start1 = clock();

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
        if(!checkSwap){
            break;
        }
    }
    
    clock_t end1 = clock();
    double elapsed1 = double(end1- start1)/CLOCKS_PER_SEC;

    cout << "Bubble Sorting" << "\n" << "Size = " << size << "\n";
    cout <<  "Run Time = " << elapsed1 * 1000;
    cout << endl << endl;

    /*
    for(int l = 0; l < size ; l++){
        cout << arr1[l] << " ";
    }
    cout << endl;
    */

    clock_t start2 = clock();
   
    for (int i = 1; i < size; i++ ) {
        for (int j = i; j  > 0; j--) {
            if (arr2[j] < arr2[j - 1]) {
                int temp = arr2[j];
                arr2[j] = arr2[j - 1];
                arr2[j - 1] = temp;
            }
            else {
                break;
            }
        }
    }

    clock_t end2 = clock();
    double elapsed2 = double(end2- start2)/CLOCKS_PER_SEC;
    cout << "Insertion Sorting" << "\n" << "Size = " << size << "\n";
    cout <<  "Run Time = " << elapsed2 * 1000;
    cout << endl;
    
    for (int  i = 0; i < size; i++) {
        cout << arr2[i] << " ";
    }
    
    return 0;
}