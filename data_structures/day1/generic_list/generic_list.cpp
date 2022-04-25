#include <iostream>
#include <cassert>
#include "./generic_list.h"

using namespace std;

template <class T>
LinkedList<T>::LinkedList(){
    head = NULL;
    count = 0;
};

template <class T>
void LinkedList<T>::Clear(){
    while (head->Next != NULL) {
        RemoveAtTheFront();
    }
}

template <class T>
void LinkedList<T>::PrintList() {
    while (head != NULL) {
        cout << head->Value << endl;
        head = head->Next;
    } 
}
template <class T>
void LinkedList<T>::Print() {
        cout << count << endl;      
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
 
template <class T>
void LinkedList<T>::AddAtTheFront(T newValue) {
    head = new Node<T>(newValue, head);
    count++;
}

template <class T>
void LinkedList<T>::AddAtTheEnd(T newValue) {
	if (head == NULL) {
        head = new Node<T>(newValue, head);
		return;
	}
	Node<T>* last = head;
	while (last->Next != NULL) {
		last = last->Next;
	}
    last->Next = new Node<T>(newValue);
    count++;
}

template <class T>
void LinkedList<T>::AddAt(T index, T newValue) { 
    /*if(index == 0) {
		AddAtTheFront(newValue);
	}
    else */{
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
void LinkedList<T>::RemoveAtTheFront() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    else {
        class Node<T> *ptr = head;
        head = head -> Next;
        delete(ptr);
    }
    count--;
}

template <class T>
void LinkedList<T>::RemoveAtTheEnd() {
    RemoveAt(count - 1);
    count--;
}

template <class T>
void LinkedList<T>::RemoveAt(T index) {
    if (index == 0)
        RemoveAtTheFront();
    else {
    Node<T>* prev = this->head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->Next;
        }
    Node<T>toDelete = prev->Next;
    prev->Next = toDelete->Next;
    delete(toDelete);
    count--;
    return;
    }
}

template <class T>
int LinkedList<T>::GetSize() {
     return count;
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
    assert(0);
}
