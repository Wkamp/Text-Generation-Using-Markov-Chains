#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <cstdlib>
#include <algorithm>
#include "Graph.h"

using namespace std;

void generateWords(Graph graph, vector<string> wordList, int wordCount=100) {
    srand((unsigned) time(NULL));
    
    int randInt = rand() % graph.getSize();
    string newWord = wordList[randInt];
    vector<pair<string, int>> adjWords = graph.getNode(newWord);

    while (adjWords.empty()) {
        randInt = rand() % wordList.size();
        newWord = wordList[randInt];
        adjWords = graph.getNode(newWord);
    }

    cout << newWord << " ";

    for (int i = 0; i < wordCount; i++) {
        randInt = rand() % adjWords.size();
        newWord = adjWords[randInt].first;
        cout << newWord << " ";
        adjWords = graph.getNode(newWord);

        if (i % 10 == 0 && i != 0) {
            cout << "\n";
        }
    }
}

int main() {
    Graph graph;
    fstream text;
    vector<string> graphWords; // contains all words in txt file and whitespace to mark the end of a line 
    vector<string> uniqueWords; // contains only the unique words from txt file
    text.open("text/Frankenstein.txt", ios::in);
    
    // reads text file and pushes each word into words vector
    if (text.is_open()) {
        string line;
        string word = "";

        // setting ' ' as the third argument to getline can separate out each word from the line
        // however, I was haveing whitespace issues when adding each word to the graph so I did it manually 
        while (getline(text, line)) {
            if (line.size() == 0) { // adds " " to words so I can account for empty lines separating paragraphs
                graphWords.push_back(" ");
                continue;
            }

            line += ' '; // added so the last word is still pushed

            for (int i = 0; i < line.size(); i++) {
                if (line[i] == ' ' && word != "") {
                    graphWords.push_back(word);
                    
                    if (find(uniqueWords.begin(), uniqueWords.end(), word) == uniqueWords.end()) { // pushes word to unique words if not already in unique words
                        uniqueWords.push_back(word);
                    }
                    
                    word = "";
                }
                else {
                    word += line[i];
                    if (word[0] == ' ') {
                        word = "";
                    }
                }
            }
        }
    }
    text.close();

	for (int i = 0; i < graphWords.size()-1; i++) {
        if (graphWords[i] != " " && graphWords[i+1] != " ") { // keeps the last word of a paragraph from being adjacent to the beginning word of the next paragraph
            graph.addEdge(graphWords[i], graphWords[i+1]);


        }
	}

    generateWords(graph, uniqueWords);

    return 0;
}