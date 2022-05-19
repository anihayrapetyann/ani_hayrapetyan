#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include <iostream>

using namespace std;

class HashNode {
public:
	int value;
	string key;
  HashNode(){
    value = -1;
    key = "";
  }
	HashNode(string _key, int _value) {
		value = _value;
		key = _key;
	}
};

class HashTable {
	HashNode** table;
	int capacity;
	int size;
	HashNode* null;

public:
	HashTable();
	int hashFunction(string _key);
    void resize();
    void insert(string _key, int _value);
  	int remove(string _key);
	int search(string _key);
	int sizeOfHashTable();
	bool isEmpty();
	void print();
};

HashTable::HashTable() { 
    capacity = 20;
    size = 0;
    table = new HashNode*[capacity];
    for (int i = 0; i < capacity; i++)
        table[i] = NULL;
    null = new HashNode();
}
	
int HashTable::hashFunction(string _key) {
    unsigned index = 23;
    for (int i = 0; i < _key.size(); i++) {
      index = (index * 'A') ^ (_key[i] * 'B');
    }
    return index % capacity; 
}

void HashTable::resize() {
    capacity *= 2;
    HashNode** temp = new HashNode*[capacity];
    for (int i = 0; i < capacity; i++) {
        temp[i] = NULL;
    }
    for (int i = 0; i < capacity / 2; i++) {
        temp[i] = table[i];
    }
    table = temp;
}

void HashTable::insert(string _key, int _value) {
    HashNode*	 temp = new HashNode (_key, _value);
    int hashIndex = hashFunction(_key);
    while (table[hashIndex] != NULL && table[hashIndex]->key != _key && table[hashIndex]->value != -1) {
        hashIndex++;
        if (hashIndex > capacity - 1)
            resize();
    }
    if (table[hashIndex] == NULL || table[hashIndex]->value == -1)
        size++;
        table[hashIndex] = temp;
    }

int HashTable::remove(string _key) {
    int hashIndex = hashFunction(_key);
    while (table[hashIndex] != NULL) {
        if (table[hashIndex]->key == _key) {
            HashNode* temp = table[hashIndex];
            table[hashIndex] = null;
            size--;
            return temp->value;
        }
        hashIndex++;
    }
    return -1;
}

int HashTable::search(string _key) {
    int hashIndex = hashFunction(_key);
    int counter = 0;
    while (table[hashIndex] != NULL) { 
        if (table[hashIndex]->key == _key)
            return table[hashIndex]->value;
        hashIndex++;
    }
    return -1;
}

int HashTable::sizeOfHashTable() {
    return size;
}

bool HashTable::isEmpty() {
    return size == 0;
}

void HashTable::print() {
    for (int i = 0; i < capacity; i++) {
        if (table[i] != NULL && table[i]->value != -1)
            cout << "key = " << table[i]->key
                << " value = " << table[i]->value << endl;
    }
}

#endif // __HASHTABLE_H__