#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <iostream>
#include <limits>

using namespace std;

class Graph {
public:
    int _size;
    bool** matrix;

public:
    Graph(int size);
    ~Graph();
    void addEdge(int a, int b);
    void removeEdge(int a, int b);
    void addNode();
    void removeNode();
    bool isNodeExists(int node);
    bool isEdgeExists(int node1, int node2);
    void nodeNeighbours(int node); 
    void print();
};

Graph::Graph(int size) {
    _size = size;
    matrix = new bool*[_size];
    for (int i = 0; i < _size; i++) {
        matrix[i] = new bool[size];
        for (int j = 0; j < _size; j++) {
                matrix[i][j] = false;
            }
        }
    }

Graph::~Graph(){
        for (int i =0; i < _size; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }


void Graph::addEdge(int a, int b) {
    if (isNodeExists(a) && isNodeExists(b) && !isEdgeExists(a, b)) {
                matrix[a][b] = true;
                matrix[b][a] = true; 
    }
    else  
        cout << "Action can not be perfomed" << endl;
    
}

void Graph::removeEdge(int a, int b) {
    if (isNodeExists(a) && isNodeExists(b) && isEdgeExists(a, b)) {
      
                matrix[a][b] = 0;
                matrix[b][a] = 0;
    }
    else  
        cout << "Action can not be perfomed" << endl;
       
}

void Graph::addNode() {
    ++_size;
    bool** newmatrix = new bool*[_size];
    for (int i = 0; i < _size; i++) {
            newmatrix[i] = new bool[_size]; 
        for (int j = 0; j < _size; j++) {
            if (i != _size - 1 && j != _size - 1)
            newmatrix[i][j] = matrix[i][j];
            if(i != _size - 1 && j != _size - 1)
             matrix[i][j] = false;
        }
    }
    delete matrix;
    matrix = newmatrix;
}

void Graph::removeNode() {
    --_size;
    bool** newmatrix = new bool*[_size];
    for (int i = 0; i < _size; i++) {
        newmatrix[i] = new bool[_size]; 
        for (int j = 0; j < _size; j++) {
            newmatrix[i][j] = matrix[i][j];
        }
    }
    delete matrix;
    matrix = newmatrix;
}

bool Graph::isNodeExists(int node){ 
    if (node > _size - 1 || node < 0 ) {
        return false;
    }
    return true;
}

bool Graph::isEdgeExists(int node1, int node2) {
    if (matrix[node1][node2]) {
        return true;
    }
    return false;
}

void Graph::nodeNeighbours(int node) {
    for (int i = 0; i < _size; i++) {
        if (matrix[node][i] == 1) {
            cout << i << " ";
        }
    }
}
void Graph::print() {
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

#endif 
