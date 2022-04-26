#include <iostream>
#include "../../day1/generic_list/generic_list.cpp"
#include "queue.hpp"
using namespace std;

int main() {   
    Queue<int> que;
    que.pushBack(5);
    que.pushBack(6);
    cout << que.popFront();
    cout << que.popFront();
    cout << que.isEmpty();
   
    return 0;
}
