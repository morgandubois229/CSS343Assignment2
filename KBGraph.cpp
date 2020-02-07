//
// Created by morgan on 2/6/20.
//
#include "KBGraph.h"
#include <iostream>

KBGraph::KBGraph() {}

KBGraph::KBGraph(KBNode actor) {
    actorList.push_back(actor);
}

KBGraph::~KBGraph(){

}

bool KBGraph::add(string name, vector<string> titles){
    KBNode node(name, titles);
    findEdges(node);
    actorList.push_back(node);
    return true;
}

void KBGraph::findEdges(KBNode& node) {
    bool secondBreak = false;
    for (int i = 0; i < actorList.size(); i++) { //How many actors are in the graph
        for (int k = 0; k < node.titles.size(); k++) { //The roles the new actor has
            for (int j = 0; j < actorList[i].titles.size(); j++) { //Roles of the current actor in graph
                if(node.titles[k] == actorList[i].titles[j]) { //Adds current actors to each others edges
                    actorList[i].edges.push_back(node.name);
                    node.edges.push_back(actorList[i].name);
                    secondBreak = true;
                    break;
                }
            }
            if (secondBreak) {
                break;
            }
        }
        secondBreak = false;
    }
}

void KBGraph::print(){
    for (int i = 0; i < actorList.size(); i++) {
        cout << actorList[i].name << '\n';
    }
    cout << endl;
}