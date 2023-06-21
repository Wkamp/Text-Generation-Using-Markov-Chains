#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include "Graph.h"

using namespace std;

int main() {
    Graph correctOutput;

    correctOutput.addEdge("Terrible", "sucks", 2);
    correctOutput.addEdge("You", "hi", 3);
    correctOutput.addEdge("You", "hi", 3);
    correctOutput.addEdge("Hello", "C", 1);

    Graph graph;
    fstream testText;
    testText.open("text/test.txt", ios::in);
    
    string temp;
    
    if (testText.is_open()) {
        string word;
        while (getline(testText, word, ' ')) {
            if (temp.empty()) {
                temp = word;
            }

            else {
                graph.addEdge(temp, word, 1);
                temp = word;
            }
        }
    }
    testText.close();
    
    correctOutput.print();
    graph.print();


    return 0;
}