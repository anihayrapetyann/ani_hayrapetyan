#include <iostream>
#include "generic_list.h"

using namespace std;

template <class T>
LinkedList<T>::LinkedList() {
    head = NULL;
    count = 0;
}

template<class T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    while( current != NULL ) {
        Node<T>* Next = current->Next;
        delete current;
        current = Next;
    }
    head = NULL;
};

template <class T>
void LinkedList<T>::AddAt(T index, T newValue) { 
   if (index == 0) {
		head = new Node<T>(newValue, head);
	}
    else {
        Node<T>* prev = this->head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->Next;
        }
	    Node<T>* newNode = new Node<T>(newValue, prev->Next);
	    prev->Next = newNode;
    }
    count++;
}

template <class T>
void LinkedList<T>::AddAtTheFront(T newValue) {
    AddAt(0, newValue);
}

template <class T>
void LinkedList<T>::AddAtTheEnd(T newValue) {
    AddAt(count, newValue);
}

template <class T>
void LinkedList<T>::RemoveAt(T index) {
    if (index == 0){
        Node<T> *ptr = head;
        head = head -> Next;
        delete ptr;
    }
    else {
    Node<T>* prev = this->head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->Next;
        }
    Node<T>* toDelete = prev->Next;
    prev->Next = toDelete->Next;
    delete toDelete;
    }
    count--;
}

template <class T>
void LinkedList<T>::RemoveAtTheFront() {
    RemoveAt(0);
}

template <class T>
void LinkedList<T>::RemoveAtTheEnd() {
    RemoveAt(count - 1);
}


template <class T>
int LinkedList<T>::GetSize() {
     return count;
}

template<class T>
ostream& operator << (ostream &out, const LinkedList<T>& list) {
    Node<T>* temp;
    temp = list.head;
    while(temp != NULL) {
        out << temp->Value << " ";
        temp = temp->Next;
    }
    out << endl;
    return out;
}

template <class T>
int LinkedList<T>::GetElement(T index) {
    Node<T>* current = head;
    int count = 0;
    while (current != NULL) {
        if (count == index)
            return (current->Value);
        count++;
        current = current->Next;
    }
    return 0;
}

template <class T>
T& LinkedList<T>::operator[]( int index) {
    int counter = 0;
    Node<T>* current = this->head;
    while (current != nullptr) {
        if (counter == index){
            return current->Value;
        }
        current = current->Next;
        counter++;
    }
   return current->Value;
}