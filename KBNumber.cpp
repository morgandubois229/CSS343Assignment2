#include <iostream>
#include <fstream>
#include "KBGraph.h"

using namespace std;

void addToGraph(vector<string> titles, string line);

string getName(string line);
string getTitle(string title);
bool alreadyEntered(string title, vector<string> listOfTitles);

void parseInput(char **argv) {
    string line = "";
    vector<string> titles;
    string name;
    ifstream myFile(argv[1]);
    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            if (line == "") {
                addToGraph(titles, name);
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
}

void addToGraph(vector<string> titles, string name) {
    cout << name << '\n';
    for (int i = 0; i < titles.size(); i++) {
        cout << titles[i] << '\n';
    }
    cout << endl;
}

int main(int argc, char **argv) {
    parseInput(argv);
    return 0;
}