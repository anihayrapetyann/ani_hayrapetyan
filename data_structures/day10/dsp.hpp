#ifndef __DSP_H__
#define __DSP_H__

#include <iostream>
#include <limits>

using namespace std;

class Graph {
private:
    int _size;
public:
    int** matrix;
    Graph(int size);
    ~Graph();
    void addEdge(int a, int b, int weight);
    void removeEdge(int a, int b);
    void addNode();
    void removeNode();
    bool isNodeExists(int node);
    bool isEdgeExists(int node1, int node2);
    void nodeNeighbours(int node); 
    void dijkstra(int **, int );
    int findMinDist(int*, bool*);
    void printDistances(int dist[]);
    void print();
};

Graph::Graph(int size) {
    _size = size;
    matrix = new int*[_size];
    for (int i = 0; i < _size; i++) {
        matrix[i] = new int[size];
        for (int j = 0; j < _size; j++) {
            matrix[i][j] = INT8_MAX;
        }
    }
}

Graph::~Graph() {
    for (int i =0; i < _size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int Graph::findMinDist(int* dist, bool* isvisited) {
    int min = INT8_MAX;
    for (int i = 0; i < _size; i++) {
        if (dist[i] < min && !isvisited[i]){
            min = dist[i];
        }   
    }
    return min;
}
 
bool Graph::isEdgeExists(int node1, int node2) {
    if (matrix[node1][node2]!=127) {
        return true;
    }
    return false;
}

bool Graph::isNodeExists(int node){ 
    if (node > _size - 1 || node < 0 ) {
        return false;
    }
    return true;
}

void Graph::addEdge(int a, int b, int weight) {
    if (isNodeExists(a) && isNodeExists(b) && !isEdgeExists(a, b)) {
        matrix[a][b] = weight;
        matrix[b][a] = weight; 
    }
    else  
        cout << "Action can not be perfomed" << endl;
}

void Graph::print() {
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            if (matrix[i][j] > 99)
                cout << matrix[i][j] << "  ";
            if (matrix[i][j] < 99 && matrix[i][j] > 9)
                cout << matrix[i][j] << "   ";
            if (matrix[i][j] < 9 )
                cout << matrix[i][j] << "    ";
        }
        cout << endl;
    }
    cout << endl;
}

void Graph::removeEdge(int a, int b) {
    if (isNodeExists(a) && isNodeExists(b) && isEdgeExists(a, b)) {
        matrix[a][b] = INT8_MAX;
        matrix[b][a] = INT8_MAX;
    }
    else  
        cout << "Action can not be perfomed" << endl;
       
}

void Graph::addNode() {
    ++_size;
    int** newmatrix = new int*[_size];
    for (int i = 0; i < _size; i++) {
            newmatrix[i] = new int[_size]; 
        for (int j = 0; j < _size; j++) {
            if (i != _size - 1 && j != _size - 1)
            newmatrix[i][j] = matrix[i][j];
            if(i != _size - 1 && j != _size - 1)
             matrix[i][j] = INT8_MAX;
        }
    }
    delete matrix;
    matrix = newmatrix;
}

void Graph::removeNode() {
    --_size;
    int** newmatrix = new int*[_size];
    for (int i = 0; i < _size; i++) {
        newmatrix[i] = new int[_size]; 
        for (int j = 0; j < _size; j++) {
            newmatrix[i][j] = matrix[i][j];
        }
    }
    delete matrix;
    matrix = newmatrix;
}

void Graph::nodeNeighbours(int node) {
    for (int i = 0; i < _size; i++) {
        if (matrix[node][i] != INT8_MAX) 
            cout << i << " ";
    }
}

void Graph::printDistances(int * dist) {
    cout << "Vertice \tDistance from Source" << endl;
    for (int i = 0; i < _size; i++)
        cout << i << " \t\t" << dist[i] << endl;
}

void Graph::dijkstra(int ** _matrix, int src) {
    int dist[_size];
    bool isvisited[_size];
    for (int i = 0; i < _size; i++) {
        dist[i] = INT8_MAX; 
        isvisited[i] = false;
    }
    dist[src] = 0;
    int index;
    for (int i = 0; i < _size - 1; i++) {
        index = findMinDist(dist, isvisited);
        isvisited[index] = true;
        for (int j = 0; j < _size; j++) {
            if (!isvisited[j] && isEdgeExists(i, j) 
                && dist[i] != INT8_MAX 
                && dist[i] + _matrix[i][j] < dist[j])
                dist[j] = dist[i] + _matrix[i][j];
        }
    }
    printDistances(dist);
}


#endif // __DSP_H__