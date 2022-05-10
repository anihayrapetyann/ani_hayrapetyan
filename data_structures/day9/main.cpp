#include "adjlist.hpp"

using namespace std;

int main() {
    Graph *graph = new Graph(3);
    graph->addNode();
    graph->addEdge(0, 1);
    graph->addEdge(0, 3);
    graph->addEdge(0,2);
    graph->addEdge(1, 2);
    graph->addEdge(4, 3);
    graph->addNode();
    graph->addEdge(3, 2);
    graph->Display();
    cout << endl;
    graph->RemoveEdge(0, 2);
    graph->removeNode();
    graph->Display();
    cout << graph->isEdgeExist(4, 0) << endl;
    graph->findNeighbours(0);

    return 0;
}