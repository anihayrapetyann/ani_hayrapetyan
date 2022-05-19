#ifndef __HASHTAB_H__
#define __HASHTAB_H__

#include <iostream>

using namespace std;

class Node {
public:
    string key;
    int value;
    Node* next;
    Node () {
        key = "";
        value = 0;
        next = NULL;
    }
    Node(string _key, int _value) {
        key = _key;
        value = _value;
    }
};

class LinkedList {
public:
    Node* head;
};

class HashTable {
    int bucket;
    LinkedList* table;
public:
    HashTable(int n);
    int hashFunction(string _key);
    unsigned hash( char* s);
    void insert (string _key, int data);
    void Display();
    int search(string _key);
    void Delete(string _key);
};

HashTable::HashTable(int n) {
        bucket = n;
        table = new LinkedList [bucket];
        for (int i = 0; i < bucket; i++) {
            table[i].head = NULL;
        }
    }

void HashTable::insert(string _key, int data) {
    int index = hashFunction(_key);
    Node* node = new Node(_key, data);
    if (table[index].head == NULL) {
         table[index].head = node;
    }
    else {
        node->next = table[index].head;
        table[index].head = node;
    }
}

int HashTable::search(string _key) {
    int index = hashFunction(_key);
    if (table[index].head == NULL) {
        cout << "Your search returned no result " << endl;
    }
    else {
    Node* newNode = table[index].head;
        while (newNode ) {
            if (newNode->key == _key ) {          
                return newNode->value;
            }
                newNode = newNode->next;
        }
    }
    return -1;
}

void HashTable::Delete(string _key) {
    int index = hashFunction(_key);
    Node* temp = table[index].head;
    if (temp->key == _key) {
        table[index].head = table[index].head->next;
    }
    else {
        while (temp->next->key != _key) {
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
        delete temp;
    }
}

void HashTable::Display() {
    for (int i = 0; i < bucket; i++) {
        cout << i<< "---> ";
        Node* temp = table[i].head;
        while (temp != NULL) {
            cout << temp->key << " ";
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int HashTable::hashFunction(string _key) {
     unsigned index = 23;
     for (int i = 0; i < _key.size(); i++) {
        index = (index * 'A') ^ (_key[i] * 'B');
    }
   return index % bucket; 
}
    
#endif // __HASHTAB_H__