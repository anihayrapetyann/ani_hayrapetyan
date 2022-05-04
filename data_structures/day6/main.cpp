#include "BSTree.hpp"

using namespace std;

int main() {
    Tree *instance = new Tree();

    instance->insert(12);
    instance->insert(1);
    instance->insert(15);
    instance->insert(2);
    instance->insert(20);
    instance->insert(25);
    instance->insert(3);

    instance->PrintByAscendingOrder();
    instance->removeNode(instance->_root, 20);
    instance->PrintByAscendingOrder();

    cout << endl;
    return 0;
}