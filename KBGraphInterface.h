/*
 * @author Morgan Du Bois
 * @version 2/7/20
 *
 * This is an interface class for the KBGraph class. It has method
 * signatures for GraphInterface constructor, virtual destructor
 * virtual add method, virtual print method, and virtual
 * findBaconNumbers.
 */
#ifndef ASSIGNMENT_2_KBGRAPHINTERFACE_H
#define ASSIGNMENT_2_KBGRAPHINTERFACE_H

#include <string>
#include <vector>

using namespace std;

class GraphInterface{
public:
    //No argument constructor.
    GraphInterface(){}

    //Destructor.
    virtual ~GraphInterface(){}

    //Add method, takes an actor's name as the string "name" and
    //takes a string vector of works they have been in called
    //"titles".
    virtual bool add(string name, vector<string> titles) = 0;

    //Prints method to print out actor and Kevin Bacon number.
    virtual void print() = 0;

    //Finds the value of a particular actors Bacon Number.
    virtual void findBaconNumbers() = 0;
};

#endif //ASSIGNMENT_2_KBGRAPHINTERFACE_H
