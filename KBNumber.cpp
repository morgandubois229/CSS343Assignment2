/*
 * @author Morgan Du Bois
 * @version 2/7/20
 *
 * Driver program that parses the inputs from a given text
 * file, and then adds the actors from that to a graph and
 * creates the Kevin Bacon number.
 */
#include <iostream>
#include <fstream>
#include "KBGraph.h"

using namespace std;

//Calls the add method on the graph.
void addToGraph(vector<string> titles, string name, KBGraph &graph) {
    graph.add(name, titles);
}

//Given a line from the text file, this returns the name portion
//of the line.
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

//Given a line from the text file, this returns the name portion
//and the year of the title.
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

//Checks to see if a title has already been entered in a KBNode.
bool alreadyEntered(string title, vector<string> listOfTitles) {
    for (int i = 0; i < listOfTitles.size(); i++) {
        if (title == listOfTitles[i]) {
            return true;
        }
    }
    return false;
}

/*
 * Uses a char** argument, and attempts to open a file. If it is not found
 * then this is displayed to the console and an empty Graph is returned. If
 * not then based on the current line either the stored values of titles
 * and name is added to theGraph. If the line is not a "", then the name
 * is parsed and title is added to name and titles respectivly, or just
 * the title name will be parsed and added.
 */
KBGraph parseInput(char **argv) {
    KBGraph theGraph;
    string line = "";
    vector<string> titles;
    string name;
    ifstream myFile(argv[1]);
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
    }
    else cout << "Unable to open file";
    return theGraph;
}

//Main method. Takes a command line argument and calls parseInput
//with the input and saves it to theGraph which is a KBGraph.
//The print method is then called on theGraph.
int main(int argc, char **argv) {
    KBGraph theGraph = parseInput(argv);
    theGraph.print();
    return 0;
}