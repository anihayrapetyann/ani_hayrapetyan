#include "graph.hpp"

using namespace std;

int main() {

   Graph graph(4);
   graph.print();
   graph.addEdge(1, 2);
   graph.addEdge(0, 1);
   graph.addEdge(3, 1);
   graph.addEdge(2, 3);
   graph.removeEdge(0, 1);
   graph.addNode();
   graph.removeNode(3);
   graph.print();
   cout << graph.isEdgeExists(1, 2) << endl;
   graph.nodeNeighbours(1);

    return 0;
}
