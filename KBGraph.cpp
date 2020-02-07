//
// Created by morgan on 2/6/20.
//
#include "KBGraph.h"
#include <iostream>

KBGraph::KBGraph() {}

KBGraph::KBGraph(KBNode actor) {
    actorList.push_back(actor);
}

KBGraph::~KBGraph() {

}

bool KBGraph::add(string name, vector<string> titles) {
    KBNode node(name, titles);
    actorList.push_back(node);
    findEdges();
    return true;
}

void KBGraph::findEdges() {
    bool secondBreak = false;
    for (int i = 0; i < actorList.size() - 1; i++) { //How many actors are in the graph
        for (int k = 0; k < actorList[actorList.size() - 1].titles.size(); k++) { //The roles the new actor has
            for (int j = 0; j < actorList[i].titles.size(); j++) { //Roles of the current actor in graph
                if (actorList[actorList.size() - 1].titles[k] ==
                    actorList[i].titles[j]) { //Adds current actors to each others edges
                    actorList[i].edges.push_back(actorList.size() - 1);
                    actorList[actorList.size() - 1].edges.push_back(i);
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

void KBGraph::findBaconNumbers() {
    int KBNumbers[actorList.size()];
    for (int i = 0; i < actorList.size(); i++) {
        KBNumbers[i] = -1;
    }
    int index = -1;
    for (int k = 0; k < actorList.size(); k++) {
        if (actorList[k].name == "Bacon, Kevin (I)") {
            index = k;
            break;
        }
    }
    if (index == -1) {
        cout << "Bacon, Kevin (I) was not found in the Graph" << endl;
        int noKB[] = {-2};
        print(noKB);
        return;
    }
    assignNumber(KBNumbers, 0, actorList.at(index), index);

    print(KBNumbers);
}

void KBGraph::assignNumber(int array[], int currentNum, KBNode currentActor, int theirIndex) {
    if(array[theirIndex] != -1 && array[theirIndex] > currentNum) { //Improves
        array[theirIndex] = currentNum;
        return;
    }
    if (array[theirIndex] != -1) { //Already set
        return;
    }
    array[theirIndex] = currentNum;
    for (int i = 0; i < currentActor.edges.size(); i++) {
        if (array[currentActor.edges[i]] == -1 || array[currentActor.edges[i]] > currentNum) {
            assignNumber(array, currentNum + 1, actorList.at(currentActor.edges[i]), currentActor.edges[i]);
        }

    }
}

void KBGraph::print() {
    findBaconNumbers();
}

void KBGraph::print(int *KBNumbers) {
    if (KBNumbers[0] == -2) {
        cout << "Kevin Bacon was not found" << endl;
        return;
    }
    for (int i = 0; i < actorList.size(); i++) {
        if (KBNumbers[i] == -1) {
            cout << actorList[i].name << ':' << '\t' << "Infinite" << '\n';
        } else {
            cout << actorList[i].name << ':' << '\t' << KBNumbers[i] << '\n';
        }
    }

}