#include "vector.hpp"
#include <iostream>

using namespace std;

template<typename T>
MyVector<T>::MyVector() {
    arr = new T[32];
    capacity = 1;
    size = 0;
}

template<typename T>
MyVector<T>::~MyVector() {
    delete [] arr;
    size = 0;
    capacity = 32;
}

template<typename T>
void MyVector<T>::AddAt(T data,int index) {
    if (GetSize() > GetCapacity()) {   
        capacity *= 2;
    }
    T* temp = new T[2 * capacity];
    for (int i = 0; i < capacity; i++) {
        if(i < index) {
            temp[i] = arr[i];
        }
        else if(i > index) {
            temp[i] = arr[i - 1];
        }
    }
    temp[index] = data;
    delete[] arr;
    arr = temp;
    size++;
}

template<typename T>
void MyVector<T>::Add(T data) {
    if (GetSize() <  GetCapacity()) {
        arr[GetSize() + 1] = data;
        size++;
    }
    else {
        AddAt(data,GetSize());
    }
            
 }

template<typename T>
void MyVector<T>::AddFront(T data) {
    AddAt(data,0);
}

template<typename T>
int MyVector<T>::GetCapacity() const{
    return capacity;
}

template<typename T>
int MyVector<T>::GetSize() const {
    return size;
}

template<typename T>
void MyVector<T>::RemoveAt(int index) {
    T* temp = new T[size];
    for(int i = index - 1; i < GetSize(); i++) {
        if(i < size) {
            temp[i] = arr[i+1];
        }
        else if(i > index) {
            temp[i] = arr[i + 1];
        }
    }
    delete[] arr;
    arr = temp;
    size--;
}

template<typename T>
void MyVector<T>::RemoveFront() {
    RemoveAt(0);
}

template<typename T>
void MyVector<T>::RemoveAll() {
   ~MyVector();
}

template<typename T>
T& MyVector<T>::operator[](const int index) const {
    return arr[index];
}

template<class Type>
ostream& operator << (ostream &out, const MyVector<Type>& array) {
    for (int i = 0; i < array.GetSize(); i++) {
        out << array[i] << " ";
    }
    return out;
}

template<typename T>
void MyVector<T>::Print() {
    for (int i = 0; i < size; i++) {
       cout << arr[i] << " ";
    }
    cout << endl;
} 
