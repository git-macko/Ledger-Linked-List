#ifndef LINKEDLIST___ASSIGNMENT_4_NODE_H
#define LINKEDLIST___ASSIGNMENT_4_NODE_H
#include <iostream>

using namespace std;

class Node {
public:
    Node(); //constructor

    //State Function
    virtual void PrintSettle();

    //Transaction Function
    virtual void TransactionPrint();

    //Node pointers
    Node* head;
    Node* next;

    // Transaction Nodes
    string nodeFrom;
    string nodeTo;
    int nodeAmount;

    //State Nodes
    string stateName;
    int stateAmount;

};


#endif //LINKEDLIST___ASSIGNMENT_4_NODE_H
