#ifndef DEQ_H
#define DEQ_H

#include <ostream>
#include "../../day1/generic_list/generic_list.h"

using std::ostream;

template <typename T>
class Deque {
private:
    LinkedList<T> _list;
public:
    Deque() = default;
    ~Deque() = default;
    T PopFront();
    T PopBack();
    T PeekFront();
    T PeekBack();
    T GetCount();
    void PushFront(T);
    void PushBack(T);
    bool IsEmpty();
    template <class Type>
    friend ostream& operator << (ostream &out, const Deque<Type>&);
    T& operator[]( int index); 
};

template<typename T>
T Deque<T>::PopFront() { 
    T return_value = _list.GetElement(0);
    _list.RemoveAtTheFront();
    return return_value;
}

template<typename T>
T Deque<T>::PopBack() { 
    T return_value = _list.GetElement(_list.GetSize() - 1);
    _list.RemoveAtTheEnd();
    return return_value;
}

template<typename T>
T Deque<T>::PeekFront() {
   return _list.GetElement(0);
} 

template<typename T>
T Deque<T>::PeekBack() {
   return _list.GetElement(_list.GetSize() - 1);
} 

template<typename T>
void Deque<T>::PushBack(T value) {
    _list.AddAtTheEnd(value);
}

template<typename T>
void Deque<T>::PushFront(T value) {
    _list.AddAtTheFront(value);
}

template<typename T>
bool Deque<T>::IsEmpty(){
    return _list.GetSize() == 0;
}

template<typename T>
T Deque<T>::GetCount() {
   return _list.GetSize();
}

template<class T>
ostream& operator << (ostream &out, const Deque<T>& list) {
    Node<T>* temp;
    temp = list.head;
    while(temp != NULL) {
        out << temp->Value << " ";
        temp = temp->Next;
    }
    out << endl;
    return out;
}

template <class T>
T& Deque<T>::operator[]( int index) {
    return _list.operator[](index);
}

#endif 
