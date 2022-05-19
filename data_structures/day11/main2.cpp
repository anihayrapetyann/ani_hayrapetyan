#include "hashTable.hpp"

int main() {
	HashTable* h = new HashTable;
	h->insert("Robert Brown", 122526);
	h->insert("John Adams", 456678);
	h->insert("Patricia Young", 326589);
	h->insert("Jennifer Barnes", 335544);
	h->print();
	cout << h->remove("John Adams") << endl;
	h->print();
	cout << h->sizeOfHashTable() << endl;
    cout << h->search("Robert Brown");
	
    return 0;
}