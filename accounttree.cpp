//
// Created by <Carson Riland> on <03/03/2020>.
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
    recursiveInsert(root, account);
    return true;
}

void AccountTree::recursiveInsert(Node*& node, Account* target) {
    // this will get rid of the dummy account once a first account is added to
    // the tree.
    if (node->account == starter) {
        delete starter;
        delete node;
        node = new Node(target);
    }
    // Base Case: If node is empty, taget is placed in empty node. Then if
    // the targets account ID is bigger or smaller than the thers it will call
    // Itself again but with the node moved to the right or left. Lastly it will
    // say error if the account is already in the system.
    if (node == nullptr) {
        node = new Node(target);
    } else if (node->account->getAccID() == target->getAccID()) {
        cout << "ERROR: Account already exists.";
    } else if (node->account->getAccID() < target->getAccID()) {
        recursiveInsert(node->right, target);
    } else {
        recursiveInsert(node->left, target);
    }
}

// Retrieve account
// returns true if successful AND *account points to account
bool AccountTree::retrieve(const int& accountNumber, Account*& account) {
    int accNum = accountNumber;
    account = recursiveFind(root, accNum);
    return true;
}

Account* AccountTree::recursiveFind(Node* node, int accNum) {

    if (accNum <= 10, 000) { // if it is a accID
        if (node == nullptr) {
            return nullptr;
        } else if (accNum ==
                   node->account->getAccID()) { // Compares accNum to AccID
            return node->account;
        } else if (accNum < node->account->getAccID()) {
            return recursiveFind(node->left, accNum);
        } else {
            return recursiveFind(node->right, accNum);
        }

    } else { // if it is a fund ID
        if (node == nullptr) {
            return nullptr;
        } else if (node->account->isAccFund(
                       accNum)) { // Compares accNum to fund account Numbers of
                                  // an account.
            return node->account;
        } else if ((accNum / 10) < node->account->getAccID()) {
            return recursiveFind(node->left, accNum);
        } else {
            return recursiveFind(node->right, accNum);
        }
    }
}

// Display information on all accounts
void AccountTree::display() { displayHelper(root); }

void AccountTree::displayHelper(Node* node) {
    if (node->left != nullptr) {
        displayHelper(node->left);
    }
    if (node->right != nullptr) {
        displayHelper(node->right);
    }

    node->account->displayAllBalances();
}
// delete all information in AccountTree
void AccountTree::clear() { deleteHelper(root); }
//Helps with the deletion and clearing of all nodes
void AccountTree::deleteHelper(Node* node) { 
    if (node->left != nullptr) {
        deleteHelper(node->left);
    }
    if (node->right != nullptr) {
        deleteHelper(node->right);
    }
    delete (node->account);
    delete node;
}
    // check if tree is empty
    bool AccountTree::isEmpty() const {
    return root == nullptr;
}