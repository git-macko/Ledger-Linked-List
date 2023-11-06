#ifndef LINKEDLIST___ASSIGNMENT_4_STATE_H
#define LINKEDLIST___ASSIGNMENT_4_STATE_H
#include <iostream>
#include "Node.h"


using namespace std;
class State:public Node {
public:
    State(); //state constructor

    /* A function that takes the parameter of toName, fromName, amount.
    Validates the name and passes it to StateNodes and Summarize the balances of each accounts. */
    void Summarize(string toName, string fromName, int amount);

    /* Iterates through the list and deletes duplicates */
    void RemoveDuplicate();

    /* A Summarize helper function that iterates and check if the
    parameter DOES NOT exist so we can pass it through StateNodes function. */
    bool StateExist(string name);

    /* Takes a parameter of toName and amount and creates a node to get added
    in our State list.*/
    void StateNodes(string toName, int amount);

    /* Prints out all the positive balance accounts. */
    void PrintBlack();

    /* Prints out all the negative balance accounts. */
    void PrintRed();

    //inherit functions
    /* Prints all the account and their balance. */
    void PrintSettle();

};
#endif //LINKEDLIST___ASSIGNMENT_4_STATE_H
