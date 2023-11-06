# Ledger-Linked-List

Ledger Linked List is of bank transaction, trading, and account balances.

This assignment is designed to give you in depth
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
 the system and is not associated with any user previously.