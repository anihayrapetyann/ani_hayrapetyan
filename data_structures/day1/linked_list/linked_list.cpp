#include <iostream>
#include <cassert>
#include "./linked_list.h"

using namespace std;

void PrintList(Node* n) {
    while (n != NULL) {
        cout << n->Value << endl;
        n = n->Next;
    } 
}

void AddAtTheFront(Node** head, int newValue) {
	Node* newNode = new Node();
	newNode-> Value = newValue;
	newNode->Next = *head;
	*head = newNode;
}

void AddAtTheEnd(Node** head, int newValue) {
	Node* newNode = new Node();
	newNode->Value = newValue;
	newNode->Next = NULL;
	if (*head == NULL) {
		*head = newNode;
		return;
	}
	Node* last = *head;
	while (last->Next != NULL) {
		last = last->Next;
	}
	last-> Next = newNode;
}

void AddAt(Node* prev, int newValue) {
	if(prev == NULL) {
		cout << "error";
		return;
	}
	Node* newNode = new Node();
	newNode->Value = newValue;
	newNode->Next = prev->Next;
	prev->Next = newNode;
}

void RemoveAtTheFront(Node*&head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    else
    {
        Node* ptr = head;
        head = head -> Next;
        delete(ptr);
    }
}

void RemoveAtTheEnd(Node*head){
    Node* previous = NULL;
    Node* ptr = head;
    while (ptr -> Next != NULL) {
            previous = ptr;
            ptr = ptr -> Next;
    }
    delete ptr;
    previous -> Next = NULL;
    return;
}

void RemoveAt(Node* head, Node* n) {
	Node *prev = head;
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

int GetElement(Node* head, int index) {
    Node* current = head;
    int count = 0;
    while (current != NULL) {
        if (count == index)
            return (current->Value);
        count++;
        current = current->Next;
    } 
    assert(0);
}

int Count(Node* head) {
    Node* current = head;
    int count = 0; 
    while (current != NULL) {
        count++;
        current = current->Next;
    }
    return count;
}