//
// Created by <Carson Riland> on <03/03/2020>.
//

#pragma once

#include "account.h"
#include <iostream>

class AccountTree {
  public:
    // Create BST
    AccountTree();

    // Delete all nodes in BST
    ~AccountTree();

    // Insert new account
    bool insert(Account* account);
    //need to write recursive helperss
    
    // Retrieve account
    // returns true if successful AND *Account points to account
    bool retrieve(const int& accountNumber, Account*& account);

    // Display information on all accounts
    void display();

    // delete all information in AccountTree
    void clear();

    // check if tree is empty
    bool isEmpty() const;

  private:
    struct Node {
        explicit Node(Account* account)
            : account{account}, right{nullptr}, left{nullptr} {}

        Account* account;
        Node* right;
        Node* left;
    };
    void recursiveInsert(Node *& root, Account* target);
    Account* recursiveFind(Node* node, int accNum);
    void displayHelper(Node* node);
    void deleteHelper(Node* node);
    Account* starter;
    Node* root;
};
