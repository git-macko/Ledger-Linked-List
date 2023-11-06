#include <iostream>
#include "Node.h"

using namespace std;

Node::Node() {} //Node constructor

//Transaction inheritance
void Node::TransactionPrint() {
    cout << "Print from Node: Transaction Records" << endl;
    Node* temp = head;
    if(temp != nullptr) {
        cout << "----------------" << endl;
        while(temp != nullptr) {
            cout << "To: " << temp->nodeTo<< endl;
            cout << "From: " << temp->nodeFrom<< endl;
            cout << "Amount: " << temp->nodeAmount<< endl;
            cout << "----------------" << endl;
            temp = temp->next;
        }
    } else {
        cout << "-------------------------------------" << endl;
        cout << "No Records Found. The List is Empty." << endl;
        cout << "-------------------------------------" << endl;
    }
}

//State inheritance
void Node::PrintSettle() {
    cout << "Print from Node: All Balances" << endl;
    Node* temp = head;
    if(temp != nullptr) {
        cout << "-----------------------------" << endl;
        while(temp != nullptr) {
            cout << "Account Owner: " << temp->stateName<< endl;
            cout << "Account Balance: " << temp->stateAmount<< endl;
            cout << "-----------------------------" << endl;
            temp = temp->next;
        }

    } else {
        cout << "-------------------------------------" << endl;
        cout << "No Records Found. The List is Empty." << endl;
        cout << "-------------------------------------" << endl;
    }
}





