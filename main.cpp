#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include "Graph.h"

using namespace std;

int main() {
    Graph graph;

    graph.addEdge("A", "B", 2);
    graph.addEdge("A", "C", 3);
    graph.addEdge("B", "C", 1);
    graph.print();

    return 0;
}