#include "hashtable.hpp"

int main() {
    HashTable* table1 = new HashTable(20);
     string name = "John";
     table1->insert(name, 256);
     table1->Display();
     table1->search(name);
     table1->Delete(name);
     table1->Display();
    
        return 0;
}