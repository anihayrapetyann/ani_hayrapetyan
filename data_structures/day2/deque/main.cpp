#include <iostream>
#include "../../day1/generic_list/generic_list.cpp"
#include "deq.hpp"
using namespace std;

int main() {   
    Deque <int> deq;
    deq.PushBack(5);
    deq.PushBack(6);
    deq.PushFront(2);
    cout << deq[0] << endl;
   
    return 0;
}
