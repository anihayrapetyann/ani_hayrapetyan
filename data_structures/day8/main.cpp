#include "graph.hpp"

using namespace std;

int main() {
   Graph graph(4);
   graph.print();
   graph.addEdge(0,0);
   graph.addEdge(1, 3);
   graph.addNode();
   graph.print();
   graph.removeNode();
   graph.print();
   cout << graph.isEdgeExists(1, 3) << endl;
   graph.nodeNeighbours(1);

    return 0;
}
