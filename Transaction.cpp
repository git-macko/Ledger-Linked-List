#include <iostream>
#include <memory>
#include "Transaction.h"

using namespace std;

Transaction::Transaction() {} //transaction destructor

Transaction::Transaction(string toName, string fromName, int amount) {
    /* getters and setters, used as a parameter to Ledger.cpp */
    this->tName = toName;
    this->tFrom = fromName;
    this->tAmount = amount;
}

void Transaction::TransactionNodes(string toName, string fromName, int amount) { //adding Transaction Nodes
    //1. allocate node
    Node* newNode = new Transaction();

    //2. assign data element
    newNode->nodeFrom = fromName;
    newNode->nodeTo = toName;
    newNode->nodeAmount = amount;

    //3. assign null to the next of new node
    newNode->next = nullptr;

    //4. Check the Linked List is empty or not,
    //if empty make the new node as head
    if(head == nullptr) {
        head = newNode;
    }
    else {
        //5. Else, traverse to the last node
        Node* temp = head;
        while(temp->next != nullptr)
            temp = temp->next;

        //6. Change the next of last node to new node
        temp->next = newNode;
    }
}

void Transaction::TransactionPrint() {
    cout << "[Ledger: Transaction Records]" << endl;
    Node* temp = head; //starting from the head node.

    if(temp != nullptr) { //loop til temp points to null.
        cout << "----------------" << endl;
        while(temp != nullptr) { //prints the transaction nodes.
            cout << "To: " << temp->nodeTo<< endl;
            cout << "From: " << temp->nodeFrom<< endl;
            cout << "Amount: " << temp->nodeAmount<< endl;
            cout << "----------------" << endl;
            temp = temp->next; //point to the next node every iteration.
        }
    }
    else {
        /* prompts the user when there's no node found in the list */
        cout << "----------------------------------------------" << endl;
        cout << "Ledger: No Records Found. The List is Empty." << endl;
        cout << "----------------------------------------------" << endl;

    }
}


void Transaction::DeleteNode(string toName, string fromName, int amount) {
    Node* temp = head; //create head pointer
    Node* prev = nullptr; //create prev pointer to link to the next to delete the specific node.
    if(temp != nullptr) {
        while(temp != nullptr) {
            if(temp->nodeTo == toName && temp->nodeFrom == fromName && temp->nodeAmount == amount) {
                prev->next = temp->next; //skips the node match and will get deleted automatically.
                delete temp;
            }
            prev = temp;
            temp = temp->next; //point to the next node every iteration.
        }
    }
    else {
        /* prompts an ERROR to the user when there's match found in the list */
        throw runtime_error("NO MATCH FOUND! CALL 911");
    }
}

void Transaction::DeleteTransaction() {
        head = nullptr; //deallocates and deletes all nodes automatically.
}


