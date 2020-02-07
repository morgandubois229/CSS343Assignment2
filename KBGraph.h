//
// Created by morgan on 2/6/20.
//

#ifndef ASSIGNMENT_2_KBGRAPH_H
#define ASSIGNMENT_2_KBGRAPH_H

#include "KBGraphInterface.h"

class KBGraph : public GraphInterface {
    struct KBNode {
        string name = "";
        vector<string> titles;
        vector<int> edges;

        KBNode(string n, vector<string> roles) : name(n) {
            for (int i = 0; i < roles.size(); i++) {
                titles.push_back(roles[i]);
            }
        }
    };

    vector<KBNode> actorList;

    void assignNumber(int array[], int currentNum, KBNode currentActor, int theirIndex);

    void findBaconNumbers();

    void print(int* KBNumbers);

public:

    KBGraph();

    KBGraph(KBNode actor);

    ~KBGraph();

    bool add(string name, vector<string> titles);

    void findEdges();

    void print();

};

#endif //ASSIGNMENT_2_KBGRAPH_H
