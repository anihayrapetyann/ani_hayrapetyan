#ifndef GENERIC_LIST_H
#define GENERIC_LIST_H

template <class T>
class Node {
public:
    T Value;
    Node<T>* Next;
    Node(T value, Node<T>* Next = NULL){
        this->Value = value;;
        this ->Next = Next;
    }
};

template <class T>
class LinkedList {
private:
    Node<T>* head;
public:
    LinkedList();
    //~LinkedList();
    void clear();
    void PrintList();
    void AddAtTheFront(T);
    void AddAtTheEnd(T);
    void AddAt(T, T);
    void RemoveAtTheFront();
    void RemoveAtTheEnd();
    void RemoveAt(T);
    int GetElement(T);
    int Count();
};

#endif