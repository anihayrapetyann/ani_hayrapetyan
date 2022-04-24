#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class Node {
public:
    int Value;
    Node* Next;
};

void PrintList(Node*);
void AddAtTheFront(Node**, int);
void AddAtTheEnd(Node**, int);
void AddAt(Node*, int);
void RemoveAtTheFront(Node*&);
void RemoveAtTheEnd(Node*);
void RemoveAt(Node*, Node*);
int GetElement(Node* head, int);
int Count(Node*);

#endif