#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include "Graph.h"

using namespace std;

int main() {
    Graph graph;
    fstream text;
    vector<string> words;
    text.open("text/test.txt", ios::in);
    
    // reads text file and pushes each word into words vector
    if (text.is_open()) {
        string line;
        string word = "";

        // setting ' ' as the third argument to getline can separate out each word from the line
        // however, it was causing issues when adding each word to the graph so I did it manually 
        while (getline(text, line)) {
            if (line.size() == 0) { // adds " " to words so I can account for empty lines separating paragraphs
                words.push_back(" ");
                continue;
            }

            line += ' '; // added so the last word is still pushed to words


            for (int i = 0; i < line.size(); i++) {
                if (line[i] == ' ' && word != "") {
                    words.push_back(word);
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

    // cout << "Words List: " << "\n";
    // for (int i = 0; i < words.size(); i++) {
    //     cout << words[i] << "\n";
    // }

	for (int i = 0; i < words.size()-1; i++) {
        if (words[i] != " " && words[i+1] != " ") { // keeps the last word of a paragraph from being adjacent to the beginning word of the next paragraph
            graph.addEdge(words[i], words[i+1], 1);
        }
	}

    graph.print();


    return 0;
}