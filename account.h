//
// Created by <Carson Riland> on <03/03/2020>.
//
#include <vector>
#include <string>;
using namespace std;

#pragma once

class Account {
    
  public:
    explicit Account(string nameFirst, string nameLast, int accNum);
    virtual ~Account();
    bool withdraw(int accNum, int amount);
    bool deposit(int accNum, int amount);
    void displayHistory(int accNum);
    void displayAllBalances();
    bool isAccFund(int accNum);
    int getAccID();
    string getAccHolderName();
    int getFundAcc(int index) const;
    void setFundAcc(int index, int newBalance);


  private:
    vector<string> accHistory[10];
    int userBankAccs[10];
    string userAccNames[10];
    int userAccID;
    string userNameFirst;
    string userNameLast;
    

};
