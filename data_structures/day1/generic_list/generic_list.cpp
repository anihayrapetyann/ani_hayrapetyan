#include <iostream>
#include <cassert>
#include "./generic_list.h"

using namespace std;

template <class T>
LinkedList<T>::LinkedList(){
    head = NULL;
};

/*template <class T>
LinkedList<T>::~LinkedList(){
     clear();
};
*/
template <class T>
void LinkedList<T>::clear(){
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
void LinkedList<T>::AddAtTheFront(T newValue) {
	Node<T>* newNode = new Node<T>();
	newNode-> Value = newValue;
	newNode->Next = head;
	head = newNode;
}

template <class T>
void LinkedList<T>::AddAtTheEnd(T newValue) {
	Node<T>* newNode = new Node<T>();
	newNode->Value = newValue;
	newNode->Next = NULL;
	if (head == NULL) {
		head = newNode;
		return;
	}
	Node<T>* last = head;
	while (last->Next != NULL) {
		last = last->Next;
	}
	last-> Next = newNode;
}

template <class T>
void LinkedList<T>::AddAt(T index, T newValue) {
	
/*    if (index == 0) 
    {
        AddAtTheFront(newValue);
    }
    else {
        Node<T>* previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->Next;
        }
 
        Node<T>* newNode = new Node<T>(newValue, previous->Next);
        previous->Next = newNode;
    }
}
  */      
    
    if(index == 0) {
		AddAtTheFront(newValue);
	}
    else {
        Node<T>* prev = this->head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->Next;
        }
	    Node<T>* newNode = new Node<T>();
	    newNode->Value = newValue;
	    newNode->Next = prev->Next;
	    prev->Next = newNode;
    }
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
}

template <class T>
void LinkedList<T>::RemoveAtTheEnd(){
    Node<T>* previous = NULL;
    Node<T>* ptr = head;
    while (ptr -> Next != NULL) {
        previous = ptr;
        ptr = ptr -> Next;
    }
    delete ptr;
    previous->Next = NULL;
    return;
}

template <class T>
void LinkedList<T>::RemoveAt(T index) {
    if (index == 0)
        RemoveAtTheFront();
    else{
    Node<T>* prev = this->head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->Next;
        }
        class Node<T> *ptr = prev->Next;
    if(prev->Next == NULL) {
        cout << "\nGiven node is not present in Linked List";
        return;
    }
    prev->Next = prev->Next->Next;
    delete(ptr);
    return;}
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

template <class T>
int LinkedList<T>::Count() {
    Node<T>* current = head;
    int count = 0; 
    while (head != NULL) {
        count++;  
        current = current->Next;
    }
    return count;
}