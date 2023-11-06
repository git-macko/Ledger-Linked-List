#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include "Node.h"

using namespace std;

class Transaction:public Node {
public:
    /* constructor */
    Transaction();

    /* A function that takes a parameter of toName, fromName, amount that
    gets and sets them for the ledger. */
    Transaction(string toName, string fromName, int amount);

    /* A function that takes a parameter of toName, fromName, amount
     and turns it in to a Transaction Node */
    void TransactionNodes(string toName, string fromName, int amount);

    /* A function that deletes a specific transaction node */
    void DeleteNode(string toName, string fromName, int amount);

    /* A function that deletes the entire list of transaction nodes */
    void DeleteTransaction();

    //inherit functions
    /* A function that prints the entire Transaction Records */
    void TransactionPrint();

    /* used as parameters */
    string tName;
    string tFrom;
    int tAmount;

};

#endif //TRANSACTION_H
