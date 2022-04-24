#include <iostream>
#include <cassert>
#include "./generic_list.h"

using namespace std;

template <class T>
void PrintList(Node<T>* n) {
    while (n != NULL) {
        cout << n->Value << endl;
        n = n->Next;
    } 
}

template <class T>
void AddAtTheFront(Node<T>** head, T newValue) {
	Node<T>* newNode = new Node<T>();
	newNode-> Value = newValue;
	newNode->Next = *head;
	*head = newNode;
}

template <class T>
void AddAtTheEnd(Node<T>** head, T newValue) {
	Node<T>* newNode = new Node<T>();
	newNode->Value = newValue;
	newNode->Next = NULL;
	if (*head == NULL) {
		*head = newNode;
		return;
	}
	Node<T>* last = *head;
	while (last->Next != NULL) {
		last = last->Next;
	}
	last-> Next = newNode;
}

template <class T>
void AddAt(Node<T>* prev, T newValue) {
	if(prev == NULL) {
		cout << "error";
		return;
	}
	Node<T>* newNode = new Node<T>();
	newNode->Value = newValue;
	newNode->Next = prev->Next;
	prev->Next = newNode;
}

template <class T>
void RemoveAtTheFront(Node<T>* &head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    else {
        Node<T> *ptr = head;
        head = head -> Next;
        delete(ptr);
    }
}

template <class T>
void RemoveAtTheEnd(Node<T>* head){
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
void RemoveAt(Node<T>* head, Node<T>* n) {
	Node<T> *prev = head;
    while(prev->Next != NULL && prev->Next != n)
        prev = prev->Next;
    if(prev->Next == NULL) {
        cout << "\nGiven node is not present in Linked List";
        return;
    }
    prev->Next = prev->Next->Next;
    delete(n);
    return;
}

template <class T>
int GetElement(Node<T>* head, T index) {
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
int Count(Node<T>* head) {
    Node<T>* current = head;
    int count = 0; 
    while (current != NULL) {
        count++;
        current = current->Next;
    }
    return count;
}