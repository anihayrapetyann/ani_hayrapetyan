#ifndef __ADJLIST_H__
#define __ADJLIST_H__

#include <iostream>

using namespace std;

class Node {
public:
    int _data;
    Node *_next;
    Node(int data) {
        _data = data;
    }
};

class LinkedList {
public:
    Node *_head;
    Node *_tail;
};

class Graph {
public:
    int _verticesNumber;
    LinkedList *_array;

    Graph(int verticenum);
    void addNode();
    void removeNode(); 
    void addEdge(int value, int v);
    void RemoveEdge(int index, int node);
    bool isEdgeExist(int node1, int node2);
    bool hasNeighbours (int node);
    void findNeighbours (int node);
    void Display();
}; 
Graph::Graph(int verticenum) {
    _verticesNumber = verticenum;
    _array = new LinkedList[_verticesNumber];
    for (int i = 0; i < _verticesNumber; i++) {
        _array[i]._head = NULL;
        _array[i]._tail = NULL;
    }
}

void Graph::addNode() {
    ++_verticesNumber;
    LinkedList *_array1 = new LinkedList[_verticesNumber];
    for (int i = 0; i < _verticesNumber; i++) {
        _array1[i] = _array[i];
    }
    delete _array;
    _array = _array1;
}

void Graph::removeNode() {
    --_verticesNumber;
    LinkedList *_array1 = new LinkedList[_verticesNumber];
    for (int i = 0; i < _verticesNumber; i++) {
        _array1[i] = _array[i];
    }
    delete _array;
    _array = _array1;
}

void Graph::addEdge(int value, int v) {
    if (isEdgeExist(value, v)) {
        cout << "The edge is already exist " << endl;
    }
    else {
        Node *node = new Node(v);
        if (_array[value]._head == NULL) {
            _array[value]._head = node;
            _array[value]._tail = node;
        }
        else {
            _array[value]._tail->_next = node;
            _array[value]._tail = node;
        }
    }
}

void Graph::RemoveEdge(int index, int node) {
    if (!isEdgeExist(index, node)) {
        cout << "The edge that you want to delete doesn't exist " << endl;
    } 
    else {
        Node* prev = _array[index]._head;
        while (prev->_next->_data != node) {
            prev = prev->_next;
        }
        Node* toDelete = prev->_next;
        prev->_next = toDelete->_next;
        delete toDelete;
    }
}

bool Graph::isEdgeExist(int node1, int node2){
Node* newNode = _array[node1]._head;
    while (newNode ) {
        if (newNode->_data == node2) {
            return true;
        }
        newNode = newNode->_next;
    }
    return false;
}

bool Graph::hasNeighbours(int node) {
if (_array[node]._head == NULL)
return false;
return true;
}

void Graph::findNeighbours(int node) {
    if (!hasNeighbours(node)) {
        cout << "The given node doesn't have any neighbours " << endl;
    }
    else {
    Node* newNode = _array[node]._head;
    cout <<  "The neighbours of " << node << " are: ";
        while (newNode ) {
            cout <<newNode->_data << " ";
            newNode = newNode->_next;
        }
    }
}
void Graph::Display() {
    for (int i = 0; i < _verticesNumber; i++) {
        cout << i<< "---> ";
        Node* temp = _array[i]._head;
        while (temp != NULL) {
            cout << temp->_data << " ";
            temp = temp->_next;
        }
        cout << endl;
    }
}


#endif // __ADJLIST_H__