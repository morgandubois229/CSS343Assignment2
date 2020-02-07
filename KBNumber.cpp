#include <iostream>
#include <fstream>
#include "KBGraph.h"

using namespace std;

void addToGraph(vector<string> titles, string line, KBGraph& graph);

string getName(string line);
string getTitle(string title);
bool alreadyEntered(string title, vector<string> listOfTitles);

KBGraph parseInput(char **argv) {
    KBGraph theGraph;
    string line = "";
    vector<string> titles;
    string name;
    //ifstream myFile(argv[1]);
    ifstream myFile("bacon.txt");
    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            if (line == "") {
                addToGraph(titles, name, theGraph);
                name.clear();
                titles.clear();
            } else if (line[0] != '\t' && line != "") {
                name = getName(line);
                line = line.substr(name.size(), line.size() - name.size());
                if (!alreadyEntered(getTitle(line), titles)) {
                    titles.push_back(getTitle(line));
                }
            } else {
                if (!alreadyEntered(getTitle(line), titles)) {
                    titles.push_back(getTitle(line));
                }
            }
        }
        myFile.close();
    } else cout << "Unable to open file";
    return theGraph;
}

bool alreadyEntered(string title, vector<string> listOfTitles) {
    for (int i = 0; i < listOfTitles.size(); i++) {
        if (title == listOfTitles[i]){
            return true;
        }
    }
    return false;
}

string getTitle(string title) {
    string returnString = "";
    for (int i = 0; i < title.size(); i++) {
        if (title[i] == '\t') {
            //do nothing
        } else if (title[i] == ')') {
            returnString.push_back(title[i]);
            return returnString;
        } else {
            returnString.push_back(title[i]);
        }
    }
    return returnString;
}

string getName(string line) {
    string returnString = "";
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == '\t') {
            return returnString;
        } else {
            returnString.push_back(line[i]);
        }
    }
    return returnString;
}

void addToGraph(vector<string> titles, string name, KBGraph& graph) {
    graph.add(name, titles);
}

int main(int argc, char **argv) {
    KBGraph theGraph = parseInput(argv);
    theGraph.print();
    return 0;
}