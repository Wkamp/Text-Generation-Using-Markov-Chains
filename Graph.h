#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>

using namespace std;

// directed graph
class Graph {
    public:
    Graph();

    void print();

    void addEdge(string node1, string node2, int weight = 1);
    
    private:
    // nodeName -> (adjNode, weight)
    map<string, vector<pair<string, int>>> adjlist;
};