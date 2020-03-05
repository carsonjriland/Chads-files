//
// Created by <Name> on <Date>.
//

#include "accounttree.h"

// empty

AccountTree::AccountTree() { 
     starter = new Account("John", "Smith", 0000);
     root = new Node(starter);
}

// Delete all nodes in BST
AccountTree::~AccountTree() = default;

// Insert new account
bool AccountTree::insert(Account* account) { 
    
    return true; 
}



// Retrieve account
// returns true if successful AND *account points to account
bool AccountTree::retrieve(const int& accountNumber, Account*& account) const {
    return true;
}

// Display information on all accounts
void AccountTree::display() const {

}

// delete all information in AccountTree
void AccountTree::clear() {}

// check if tree is empty
bool AccountTree::isEmpty() const { 
    return root == nullptr; 
}