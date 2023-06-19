#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include "Graph.h"

using namespace std;

Graph::Graph() {

}

void Graph::print() {
    cout << "Node --> (adjNode, weight)\n\n";
	for (const auto& [key, value] : adjlist) {
		cout << key << " --> ";

		for (int i = 0; i < value.size(); i++) {
			cout << "(" << value[i].first << ", " << value[i].second << ") ";
		}
        cout << "\n";
	}
}

void Graph::addEdge(string node1, string node2, int weight) {
    if (adjlist.find(node1) == adjlist.end()) {
        adjlist[node1] = {make_pair(node2, weight)};
    }
    else {
        adjlist[node1].push_back(make_pair(node2, weight));
    }

    if (adjlist.find(node2) == adjlist.end()) {
        adjlist[node2] = {};
    }

}