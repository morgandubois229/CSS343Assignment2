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
        vector<KBNode*> edges;

        KBNode(string n, vector<string> roles) : name(n) {
            for (int i = 0; i < roles.size(); i++) {
                titles.push_back(roles[i]);
            }
        }
    };

    vector<KBNode> actorList;

public:

    KBGraph();

    KBGraph(KBNode actor);

    ~KBGraph();

    bool add(string name, vector<string> titles);

    void findEdges(KBNode&);

    void print();

};

#endif //ASSIGNMENT_2_KBGRAPH_H
