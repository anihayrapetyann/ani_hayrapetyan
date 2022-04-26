#ifndef QUE_H
#define QUE_H

#include "../../day1/generic_list/generic_list.h"

template <typename T>
class Queue {
private:
    LinkedList<T> _list;
public:
    Queue() = default;
    ~Queue() = default;
    T popFront();
    T peek();
    void pushBack(T);
    bool isEmpty();
  
};

template<typename T>
T Queue<T>::popFront()
{ 
    T return_value = _list.GetElement(0);
    _list.RemoveAtTheFront();
    return return_value;
}

template<typename T>
T  Queue<T>::peek() {
   return _list.GetElement(0);
} 

template<typename T>
void Queue<T>::pushBack(T value) {
    _list.AddAtTheEnd(value);
}

template<typename T>
bool Queue<T>::isEmpty(){
    return _list.GetSize() == 0;
}

#endif 
