#include <iostream>
#include "./generic_list.cpp"
#include "queue.hpp"
using namespace std;

int main() {   
 /*   LinkedList<int> list;
    list.AddAtTheFront(5);
    list.AddAtTheEnd(10);
    list.AddAtTheEnd(15);
    list.RemoveAtTheEnd();
    cout << list.GetSize() << endl;
    cout << list[0] << endl;
   */Queue<int> que;
    que.pushBack(5);
    que.pushBack(6);
    //que.pushBack(7);
   cout << que.popFront();
   cout << que.popFront();
    cout << que.isEmpty();
   
    return 0;
}
