#include "dsp.hpp"

int main() {
    
   Graph graph(5);
   graph.print();
   graph.addEdge(0,1, 6);
   graph.addEdge(0,2, 2);
   graph.addEdge(0,3, 5);
   graph.addEdge(1,4, 7);
   graph.addEdge(2, 4, 8);
   graph.addEdge(4, 3, 12);
   graph.addEdge(1, 3, 5);
   graph.print();
   graph.dijkstra(graph.matrix,0);

    return 0;
}