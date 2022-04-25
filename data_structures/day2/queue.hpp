#ifndef _QUE_H_
#define _QUE_H_

#include "./generic_list.h"

template <typename T>
class Queue {
private:
    LinkedList<T> _list;
public:
    T popFront();
    bool isEmpty();
    void pushBack(T);
    T peek();
    Queue();
//    ~Queue();
};

template<typename T>
T Queue<T>::popFront()
{ 
    T return_value = _list[1];
    _list.RemoveAtTheFront();
    return return_value;
}

template<typename T>
T  Queue<T>::peek()
{
   return _list[0];
} 

template<typename T>
bool Queue<T>::isEmpty(){
    return _list.GetSize() == 0;
}

template<typename T>
void Queue<T>::pushBack(T value)
{
    _list.AddAtTheEnd(value);
}

template<typename T>
Queue<T>::Queue() = default;

/*template<typename T>
Queue<T>::~Queue()
{   
}
*/
#endif // __QUE_H__