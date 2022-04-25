#include <iostream>
#include "./generic_list.h"
#include "./generic_list.cpp"

using namespace std;

int main() {
    /*Node<int>* head = new Node<int>();
    Node<int>* second = new Node<int>();
    Node<int>* third = new Node<int>();

    head-> Value = 1;
    head-> Next= second;
    second-> Value = 2;
    second-> Next = third;
    third-> Value = 3;
    third-> Next = NULL;

	AddAtTheFront(&head, 13);
	AddAtTheEnd(&head, 30);
	AddAt(second, 6);
	RemoveAt(head, third);
	RemoveAtTheEnd(head);
	RemoveAtTheFront(head);
	Count(head);
	PrintList(head);

	cout << "The number of nodes is " << Count(head) << endl;
	cout << "The searched element is  " <<	GetElement(head, 2)<<endl;
*/
    LinkedList<int> list;
    list.AddAtTheFront(5);
   // cout << list.Count() << endl;
    list.AddAtTheEnd(10);
    list.AddAtTheEnd(15);
    list.AddAt(2, 13);
    //cout << endl << list.GetElement(2) << endl;
    list.PrintList();
    cout << list.Count() << endl;
    return 0;
}
