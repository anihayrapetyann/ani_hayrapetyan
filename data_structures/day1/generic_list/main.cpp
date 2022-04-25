#include <iostream>
#include "./generic_list.h"
#include "./generic_list.cpp"
#include "./queue.hpp"
using namespace std;

int main() {
   
    LinkedList<int> list;
    list.AddAtTheFront(5);
    list.AddAtTheEnd(10);
    list.AddAt(1, 13);
    list.PrintList();
    list.Print(); 

    Queue<int> que;
    que.pushBack(5);
    que.pushBack(6);
    que.pushBack(7);
    que.popFront();
   
    return 0;
}
