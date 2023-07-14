#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include "Graph.h"

using namespace std;

Graph::Graph() {

}

vector<pair<string, int>> Graph::getNode(string node) {
    auto it = adjlist.find(node);
    return it->second;
};

int Graph::getSize() {
    return adjlist.size();
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
        adjlist[node1] = {make_pair(node2, weight)}; // creates vector of pairs if one doesn't exist
    }
    else {
        bool exist = false;
        for (int i = 0; i < adjlist[node1].size(); i++) { // increases weight by one if pair already exists in graph 
            if (adjlist[node1][i].first == node2) {
                exist = true;
                adjlist[node1][i].second++;
                break;
            }
        }

        if (!exist) {
            adjlist[node1].push_back(make_pair(node2, weight)); // adds new pair to graph, if pair not already in graph
        }
        
    }

    if (adjlist.find(node2) == adjlist.end()) {
        adjlist[node2] = {};
    }

}
