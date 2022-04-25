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
    T count;
public:
    LinkedList();
    //~LinkedList();
    void Clear();
    void PrintList();
    T& operator[]( int index); 
    void AddAtTheFront(T);
    void AddAtTheEnd(T);
    void AddAt(T, T);
    void RemoveAtTheFront();
    void RemoveAtTheEnd();
    void RemoveAt(T);
    int GetElement(T);
    void Print();
    int GetSize();
    //friend ostream& operator << (ostream &out, const LinkedList<Type>& );
};

#endif