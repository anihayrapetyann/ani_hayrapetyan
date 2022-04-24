#ifndef GENERIC_LIST_H
#define GENERIC_LIST_H

template <class T>
class Node {
public:
    T Value;
    Node<T>* Next;
};

template <class T>
void PrintList(Node<T>*);

template <class T>
void AddAtTheFront(Node<T>**, T);

template <class T>
void AddAtTheEnd(Node<T>**, T);

template <class T>
void AddAt(Node<T>*, T);

template <class T>
void RemoveAtTheFront(Node<T>*&);

template <class T>
void RemoveAtTheEnd(Node<T>*);

template <class T>
void RemoveAt(Node<T>*, Node<T>*);

template <class T>
int GetElement(Node<T>* head, T);

template <class T>
int Count(Node<T>*);

#endif