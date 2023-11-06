#include <iostream>
#include "State.h"

using namespace std;

State::State() {} //State constructor


bool State::StateExist(string name) {
    Node* temp = head;

    //Base case
    if (head == nullptr) {
        return false;
    }

    //If name is present in current node, return true
    if (head->stateName == stateName) {
        return true;
    }
    if(temp != nullptr) { //loops til it finds it match
        while(temp != nullptr) {
            if (temp->stateName == name)
                return true;
            temp = temp->next;
        }
    }
    return false; //return false if no match found.
}
void State::Summarize(string toName, string fromName, int amount) {
    /* if parameter fromName is EXTERNAL then we add the toName and amount to our State node */
    if (fromName == "EXTERNAL") {
        StateNodes(toName, amount);
    }
    else {
        //trading and summarizing balances between accounts
        Node* trade = head; //start from head node
        if (trade != nullptr) {
            while (trade != nullptr) {
                /* as the iteration go we pass the parameter to our bool StateExist function
                to see if this name already exists in our state nodes list. */
                if(trade->stateName != toName && trade->stateName != fromName) {
                    if(!StateExist(toName)) {
                        StateNodes(toName, 0); //if false then pass to the StateNodes function with an amount of 0 to avoid the amount from multiplying.
                    }
                    else if(!StateExist(fromName)) {
                        StateNodes(fromName, 0); //if false then pass to StateNodes function
                    }
                }
                else { //Summarizing balances between accounts
                    if (trade->stateName == fromName) {
                        trade->stateAmount = trade->stateAmount - amount;
                    }
                    else if (trade->stateName == toName) {
                        trade->stateAmount = trade->stateAmount + amount;
                    }
                }

                trade = trade->next;
            }
        }

    }


}
void State::RemoveDuplicate() {
    Node *temp = head; //start with the head node
    while(temp->next != nullptr){
        //Duplicate Found
        if(temp->stateName == temp->next->stateName){
            //Duplicate Removed
            temp -> next = temp ->next ->next;
        }
        else{
            //No Duplicate Present
            temp = temp->next;
        }
    }
}
void State::StateNodes(string name, int amount) {


    //1. allocate node
    Node* newNode = new State();

    //2. assign data element
    newNode->stateName = name;
    newNode->stateAmount = amount;

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
    RemoveDuplicate(); //check and removes duplicate names in state node list
}

void State::PrintSettle()  { /* printing ALL balance */
    cout << "[State Settle: All Balances]" << endl;
    Node* temp = head;
    if(temp != nullptr) { //iteration to print the names and their current balance
        cout << "-----------------------------" << endl;
        while(temp != nullptr) {
            cout << "Account Owner: " << temp->stateName<< endl;
            cout << "Account Balance: " << temp->stateAmount<< endl;
            cout << "-----------------------------" << endl;
            temp = temp->next;
        }

    }
    else {
        /* prompts the user when there's no node found in the list */
        cout << "---------------------------------------------------" << endl;
        cout << "State Settle: No Records Found. The List is Empty." << endl;
        cout << "---------------------------------------------------" << endl;
    }
}




void State::PrintBlack() { /* printing positive balance only */
    cout << "[State Black: Positive Balances]" << endl;
    Node* temp = head;
    if(temp != nullptr) {
        cout<< "-----------------------------" << endl;
        while(temp != nullptr) { //iteration to print the names and their current balance
            if(temp->stateAmount > 0) {
                cout << "Account Owner: " << temp->stateName << endl;
                cout << "Account Balance: " << temp->stateAmount << endl;
                cout << "-----------------------------" << endl;
            }
            temp = temp->next;
        }

    }
    else {
        /* prompts the user when there's no node found in the list */
        cout << "---------------------------------------------------" << endl;
        cout << "State Black: No Records Found. The List is Empty." << endl;
        cout << "---------------------------------------------------" << endl;
    }
}

void State::PrintRed() { /* printing negative balance only */
    cout << "[State Red: Negative Balances]" << endl;
    Node* temp = head;
    if(temp != nullptr) {
        cout<<"-----------------------------" << endl;
        while(temp != nullptr) {
            if(temp->stateAmount < 0) { //iteration to print the names and their current balance
                cout << "Account Owner: " << temp->stateName<< endl;
                cout << "Account Balance: " << temp->stateAmount<< endl;
                cout << "-----------------------------" << endl;
            }
            temp = temp->next;
        }

    }
    else {
        /* prompts the user when there's no node found in the list */
        cout << "---------------------------------------------------" << endl;
        cout << "State Red: No Records Found. The List is Empty." << endl;
        cout << "---------------------------------------------------" << endl;
    }
}








