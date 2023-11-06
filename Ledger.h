#ifndef LINKEDLIST_ASSIGNMENT_4_LEDGER_H
#define LINKEDLIST_ASSIGNMENT_4_LEDGER_H
#include <iostream>
#include <vector>
#include "Transaction.h"
#include "State.h"

using namespace std;

class Ledger {

protected:
    int transactCount=0; //keeps track of transaction counts
    vector<string> ledgerFrom; //used to store parameters to pass after 10 transactions
    vector<string> ledgerTo;
    vector<int> ledgerAmount;

public:

    //Constructor() -- Creates a new, empty Ledger
    Ledger();

    //Destructor() -- Cleans up all of the allocated memory
    ~Ledger();

    /* overload += -- Adds a transaction to the ledger.
       Every 10 transactions, your method should automatically
       insert a State node that summarizes the current values of each account. */
    void operator += (const Transaction& transact);

    /* overload -= -- Deletes a single exact match of FromName, ToName,
       and Amount, but only if it hasn't been included in a State node yet.
       If the node isn't found then throw an exception. */
    void operator -= (const Transaction& transact);

    /* Clear() -- Removes all of the transactions. */
    void Clear();

    /* << overload -- Prints every transaction in the ledger */
    friend ostream& operator << (ostream& COUT, Ledger& myLedger);

    /* Settle() -- Prints the name and balance of each user.
    You must use the state nodes in this calculation.
    InTheBlack() -- Prints the name and balance of each user who has positive money.
    You must use the state nodes in this calculation.
    InTheRed() -- Prints the name and balance of each user who has negative money.
    You must use the state nodes in this calculation. */
    void Settle();
    void InTheBlack();
    void InTheRed();
};

#endif //LINKEDLIST_ASSIGNMENT_4_LEDGER_H

/* INSTRUCTIONS
 * This assignment is designed to give you in depth
 experience with linked lists. You will build a ledger
 that keeps track of transactions. You can both add payments
 and issue refunds. You will also need to implement some printing
 functions to examine the list.  You will need to create at least
 three classes for this assignment -- a generic Node class,
 a State class, a Transaction class and a Ledger class.
 The State and Transaction class should inherit from the
 Node class so that you can easily use them both in the
 linked list.  You need to use smart pointers in this
 assignment.  You need to create your own linked list --
 don't use std::list.
 You will implement the following functionality
 (along with any supporting functionality necessary):

 In addition to typical node functionality,
 State nodes include a summary of the current state of the
 Ledger.  This is a listing of every person in the system
 and their current amount.

 In addition to typical node functionality,
 Transaction nodes include a ToName, FromName, and Amount.
 If the FromName is "EXTERNAL" then the money was put into
 the system and is not associated with any user previously.*/