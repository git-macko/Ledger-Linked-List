#include <iostream>
#include <memory>
#include "Ledger.h"
#include "State.h"
#include "Transaction.h"
/* used std::memory */

using namespace std;

Ledger::Ledger() {} //ledger constructor

void Ledger::operator+=(const Transaction &transact) {

    /* adding to transaction nodes, using shared pointer with
     parameter tName = toName, tFrom = fromName, tAmount = amount */
    shared_ptr<Transaction>tn = make_shared<Transaction>();
    tn->TransactionNodes(transact.tName, transact.tFrom,transact.tAmount);

    /* adding transactions to ledger vectors, since we need to pass this to the state nodes after
    10 transactions */
    ledgerTo.push_back(transact.tName);
    ledgerFrom.push_back(transact.tFrom);
    ledgerAmount.push_back(transact.tAmount);

    ++transactCount; //keeping track of transaction count


    if(transactCount == 10) { //when transaction hits 10
        /* After 10 transactions, we pass the transaction that was stored in our ledger vector
        and unto the state where we summarize the user's balance */
        shared_ptr<State> sn = make_shared<State>(); //using shared pointer to call state
        int i = 0;
        while(i < ledgerTo.size()) { //using while-loop iteration to pass the parameter ledger vector
            sn->Summarize(ledgerTo.at(i),ledgerFrom.at(i),ledgerAmount.at(i));
            i++;
        }
        /* clearing out the ledger vectors to avoid duplicates */
        ledgerTo.clear();
        ledgerFrom.clear();
        ledgerAmount.clear();
        transactCount=0;
    }

}


void Ledger::operator-=(const Transaction& transact) {
    /* delete prompt that warns the user that a certain transaction will be deleted. */
    cout << "--------------------------------------------------" << endl;
    cout << "LEDGER WARNING: This Transaction is to be deleted." << endl;
    cout << "To: " << transact.tName << endl;
    cout << "From: " << transact.tFrom << endl;
    cout << "Amount: " << transact.tAmount << endl;
    cout << "--------------------------------------------------" << endl;


    int x = 0; // every record match must be deleted including our ledger vectors
    while(x < ledgerTo.size()) {
        if(ledgerTo.at(x) == transact.tName && ledgerFrom.at(x) == transact.tFrom) {
            ledgerTo.erase(ledgerTo.begin() + x);
            ledgerFrom.erase(ledgerFrom.begin() + x);
            ledgerAmount.erase(ledgerAmount.begin() + x);
        }
        x++;
    }

    /* calling a function that deletes a specific node using parameters. */
    shared_ptr<Transaction>tn = make_shared<Transaction>(); //using shared pointer to call DeleteNode function.
    tn->DeleteNode(transact.tName, transact.tFrom, transact.tAmount);
}


void Ledger::Clear() {
    /* warning prompt to the user that we are erasing the entire transaction records. */
    cout << endl;
    cout << "-------------------------------------------" << endl;
    cout << "LEDGER WARNING: Clearing ALL Transactions." << endl;
    cout << "-------------------------------------------" << endl;
    cout << endl;
    /* calling a function that deletes the entire list of transaction */
    shared_ptr<Transaction>tn = make_shared<Transaction>(); //using shared pointer to call DeleteTransaction function
    tn->DeleteTransaction();
}

ostream& operator << (ostream& output, Ledger& myLedger) {
    /* using shared pointer we call TransactionPrint function that prints out
    the entire list of transactions. */
    shared_ptr<Transaction>tn = make_shared<Transaction>();
    tn->TransactionPrint();
    return output;
}

void Ledger::Settle() {
    /* using shared pointer we call PrintSettle function that prints out
    the entire list of State account balances. */
    shared_ptr<State>sn = make_shared<State>();
    sn->PrintSettle();
}

void Ledger::InTheBlack() {
    /* using shared pointer we call InTheBlack function that prints out all
    positive balances accounts. */
    shared_ptr<State>sn = make_shared<State>();
    sn->PrintBlack();
}

void Ledger::InTheRed() {
    /* using shared pointer we call InTheRed function that prints out all
    negative balances accounts. */
    shared_ptr<State>sn = make_shared<State>();
    sn->PrintRed();
}

Ledger::~Ledger() { //ledger destructor
    /* deallocates memory */
    cout << "-------------------------------------" << endl;
    cout << "LEDGER WARNING: Destructor Initiated." << endl;
    cout << "-------------------------------------" << endl;
}






