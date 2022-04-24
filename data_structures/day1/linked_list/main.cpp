#include <iostream>
#include "./linked_list.h"

using namespace std;

int main() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head-> Value = 10;
    head-> Next= second;
    second-> Value = 20;
    second-> Next = third;
    third-> Value = 30;
    third-> Next = NULL;

	AddAtTheFront(&head, 5);
	AddAtTheEnd(&head, 40);
	AddAt(second, 25);
	RemoveAt(head, third);
	RemoveAtTheEnd(head);
	RemoveAtTheFront(head);
	Count(head);
	PrintList(head);
    
	cout << "The number of nodes is " << Count(head) << endl;
	cout << "The searched element is  " <<	GetElement(head, 2)<<endl;

    return 0;
}
