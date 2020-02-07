//
// Created by morgan on 2/6/20.
//

#ifndef ASSIGNMENT_2_KBGRAPHINTERFACE_H
#define ASSIGNMENT_2_KBGRAPHINTERFACE_H

#include <string>
#include <vector>

using namespace std;

class GraphInterface{
public:
    GraphInterface(){}

    virtual ~GraphInterface(){}

    virtual bool add(string name, vector<string> titles) = 0;

    virtual void print() = 0;
};

#endif //ASSIGNMENT_2_KBGRAPHINTERFACE_H
