/*
 * @author Morgan Du Bois
 * @version 2/7/20
 *
 * Implementation of the KBGraph class. Function signatures in
 * KBGraph.h.
 */
#include "KBGraph.h"
#include <iostream>

//Default constructor
KBGraph::KBGraph() {}

//Single argument constructor. Adds the argument actor KBNode
//to actorList.
KBGraph::KBGraph(KBNode actor) {
    actorList.push_back(actor);
}

//KBGraph destructor.
KBGraph::~KBGraph() {
    actorList.clear();
}

//Adds the given string and titles to a new KBNode and then
//adds that node to actorList. findEdges is then called and
//the function returns true.
bool KBGraph::add(string name, vector<string> titles) {
    KBNode node(name, titles);
    actorList.push_back(node);
    findEdges();
    return true;
}

/*
 * findEdges looks at all actors in the graph and adds the index of
 * connected actors to those actors respective vector<int> edges. A
 * bool called secondBreak is created and set to false. This is used to
 * break the second loop when an edge is found between actors. The outer
 * loop loops through the stored actors, and the two inner loops go
 * through the vector<string> titles of both and looks for a match.
 * When one is found the two inner loops are broken and the next actor
 * in the actorList is compared to the last actor in the actorList.
 */
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

/*
 * findBaconNumbers creates an array of the same size of actorList
 * and initializes all of the indices to -1. The actorList is then
 * searched through for the actor "Bacon, Kevin (I)" and the index
 * of that KBNode is saved as 0 in the same index of KBNumbers. If
 * Kevin Bacon is not found an array of size 1, with the value of -2
 * is then passed to the private print method. If not then
 * assignNumbers is called and then print is called with the filled
 * KBNumbers array.
 */
void KBGraph::findBaconNumbers() {
    //Creates array and sets index to -1.
    int KBNumbers[actorList.size()];
    for (int i = 0; i < actorList.size(); i++) {
        KBNumbers[i] = -1;
    }
    //Finds where Kevin Bacon is in actorList.
    int index = -1;
    for (int k = 0; k < actorList.size(); k++) {
        if (actorList[k].name == "Bacon, Kevin (I)") {
            index = k;
            break;
        }
    }
    //If Kevin Bacon is not found, print method with appropriate
    //data is called.
    if (index == -1) {
        cout << "Bacon, Kevin (I) was not found in the Graph" << endl;
        int noKB[] = {-2};
        print(noKB);
        return;
    }

    //Calls assignNumber and then calls print with KBNumbers as argument.
    assignNumber(KBNumbers, 0, actorList.at(index), index);
    print(KBNumbers);
}

/*
 * Recursive method to assigning the Kevin Bacon numbers. The arguments for this
 * method are KBNumbers which is the array that stores the Kevin Bacon numbers,
 * the next argument stores which current Bacon Number you are on, this is
 * incremented as you call down the graph from Kevin Bacon, the currentActor
 * is a KBNode which is the current actor you are on. The last argument is
 * the index in actorList of the current actor. This function sets the currentActor
 * to the currentNum in KBNumbers. It then searches through the edges of the
 * currentActor and if the currentNum is less then the already set number for the
 * actor in currentActor edge, assignNumber is called on it. Or if currentNum has
 * not been set it will call assignNumber.
 */
void KBGraph::assignNumber(int* KBNumbers, int currentNum, KBNode currentActor, int theirIndex) {
    //Sets KBNumbers to currentNum at the currentActors index in actorList.
    KBNumbers[theirIndex] = currentNum;
    //Loops through the edges of the currentActor.
    for (int i = 0; i < currentActor.edges.size(); i++) {
        //Only calls if better Kevin Bacon number is found, or if it has not been set yet.
        if (KBNumbers[currentActor.edges[i]] == -1 || KBNumbers[currentActor.edges[i]] > currentNum) {
            assignNumber(KBNumbers, currentNum + 1, actorList.at(currentActor.edges[i]), currentActor.edges[i]);
        }

    }
}

//Public print method. Calls helper function findBaconNumber().
void KBGraph::print() {
    findBaconNumbers();
}

/*
 * Prints out the actors and their Kevin Bacon number in the
 * format "Last, First:\tnumber". If the argument given is
 * equal to -2 at index 0, Kevin Bacon was not found. This
 * is displayed and the function terminates. If Kevin Bacon
 * was found then the list of names and numbers is printed.
 */
void KBGraph::print(int *KBNumbers) {
    //Kevin Bacon was not found in Graph.
    if (KBNumbers[0] == -2) {
        cout << "Kevin Bacon was not found" << endl;
        return;
    }
    //Outputs Actor name and Kevin Bacon number to console.
    for (int i = 0; i < actorList.size(); i++) {
        if (KBNumbers[i] == -1) {
            cout << actorList[i].name << ':' << '\t' << "Infinite" << '\n';
        } else {
            cout << actorList[i].name << ':' << '\t' << KBNumbers[i] << '\n';
        }
    }

}