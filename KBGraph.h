/*
 * @author Morgan Du Bois
 * @version 2/7/20
 *
 * This class has the method definition for KBGraph. It also contains
 * a private struct KBNode that represents a node and the edges in a
 * vertex in the Graph. The KBGraph contains the private data member
 * actorList which is a vector of type KBNode, as well as the private
 * methods assignNumber, overloaded print and find bacon number. This
 * class publicly inherits from GraphInterface in KBGraphInterface.h
 */
#ifndef ASSIGNMENT_2_KBGRAPH_H
#define ASSIGNMENT_2_KBGRAPH_H

#include "KBGraphInterface.h"

//Inherits from GraphInterface
class KBGraph : public GraphInterface {
    /*
     * This is a private struct within the KBGraph class. It has data
     * member name, which is of type string and holds the actors name.
     * It has a vector of type string, which holds all of the titles
     * that the actors have been in. Its last data member is a vector
     * of type int called edges that holds the index of adjacent actors
     * from the actorList data member in KBGraph.
     */
    struct KBNode {
        string name = ""; //Actor name "Last, First"
        vector<string> titles; //Vector of works an actor has been in "Title (Year)"
        vector<int> edges; //Holds index of adjacent actors using titles as links.

        /*
         * Uses string n and a vector of strings called roles to fill in member
         * data. The name is initialized to the value of n with an initializer list.
         * roles is then copied into titles.
         */
        KBNode(string n, vector<string> roles) : name(n) {
            for (int i = 0; i < roles.size(); i++) {
                titles.push_back(roles[i]);
            }
        }

        //Destructor for KBNode. Empties vector member data and set name to "".
        ~KBNode() {
            titles.clear();
            edges.clear();
            name = "";
        }
    };

    //Private member data that is a vector of KBNode
    vector<KBNode> actorList;

    //Private function that assigns values to an array that represent
    //each actors Kevin Bacon number.
    void assignNumber(int* KBNumbers, int currentNum, KBNode currentActor, int theirIndex);

    //Finds where Kevin Bacon is and calls assignNumber based on that
    //or will reflect if Kevin Bacon is not found.
    void findBaconNumbers();

    //Private helper method that prints out each actors name and their
    //Kevin Bacon number.
    void print(int* KBNumbers);

public:

    //Public no argument constructor.
    KBGraph();

    //Public single argument constructor. Adds a single KBNode to actorList.
    KBGraph(KBNode actor);

    //KBGraph destructor.
    ~KBGraph();

    //Public method that creates and then adds a KBNode to actorList.
    bool add(string name, vector<string> titles);

    //Finds the values of edges in each KBNode based on the last KBNode in
    //actorList.
    void findEdges();

    //Public print method that prints the actors and their Kevin Bacon number.
    void print();

};

#endif //ASSIGNMENT_2_KBGRAPH_H
