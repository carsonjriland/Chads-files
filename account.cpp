//
// Created by <Carson Riland> on <03/03/2020>.
//
#include "account.h";
#include <iostream>;
using namespace std;

Account::Account(string nameFirst, string nameLast, int accNum) {
    userAccID = accNum;
    userNameFirst = nameFirst;
    userNameLast = nameLast;
    userAccNames[0] = "Money Market";
    userAccNames[1] = "Prime Money Market";
    userAccNames[2] = "Long-Term Bond";
    userAccNames[3] = "Short-Term Bond";
    userAccNames[4] = "500 Index Fund";
    userAccNames[5] = "Capital Value Fund";
    userAccNames[6] = "Growth Equity Fund";
    userAccNames[7] = "Growth Index Fund";
    userAccNames[8] = "Value Fund";
    userAccNames[9] = "Value Stock Index";
}

Account::~Account() {}

/* The deposit and withdraw functions in this program can only function propery
when used for withdrawls or deposits. Transfers between acounts will have to
happen in a different class using the setFundAcc to help.

*/

bool Account::withdraw(int accNum, int amount) {
    accNum = accNum - (userAccID * 10);
    if (amount > userBankAccs[accNum]) {
        cout << "ERROR invalid deposit amount: " << amount;
        return false;
    } else {
        int m = accNum - (userAccID * 10);
        accHistory[m].push_back("W " + accNum + ' ' + amount);
        userBankAccs[accNum] = userBankAccs[accNum] - amount;
        return true;
    }
}
bool Account::deposit(int accNum, int amount) {
    if (amount >= 0) {
        int m = accNum - (userAccID * 10);
        accHistory[m].push_back("D " + accNum + ' ' + amount);
        userBankAccs[accNum] = userBankAccs[accNum] + amount;
        return true;
    } else {
        cout << "ERROR invalid deposit amount: " << amount;
        return false;
    }
}

void Account::displayHistory(int accNum) {

    if (accNum == userAccID) {
        cout << "Displaying Transaction History for " << userNameFirst << ' '
             << userNameLast << " by fund.";
        cout << endl;
        for (int i = 0; i <= 9; i++) {
            cout << userAccNames[i] << " : $" << userBankAccs[i];
            // below code should print out all strings within the vector at
            // array location accNum
            for (auto j = accHistory[accNum].begin();
                 j != accHistory[accNum].end(); ++j) {
                cout << *j << endl;
            }
        }
    } else {
        accNum = accNum - (userAccID * 10);
        cout << "Displaying Transaction History for " << userNameFirst << ' '
             << userNameLast << "'s ";
        cout << userAccNames[accNum] << " Fund: $" << userBankAccs[accNum]
             << endl;
        // below code should print out all strings within the vector at array
        // location accNum
        for (auto i = accHistory[accNum].begin(); i != accHistory[accNum].end();
             ++i) {
            cout << *i << endl;
        }
    }
}

void Account::displayAllBalances() {
    cout << endl
         << userNameFirst << ' ' << userNameLast << " Account ID: " << userAccID
         << endl;
    for (int i = 0; i <= 9; i++) {
        cout << userAccNames[i] << ": $" << userBankAccs[i] << endl;
    }
}

int Account::getFundAcc(int index) const {
    index = index - (userAccID * 10);
    return userBankAccs[index];
}
void Account::setFundAcc(int index, int newBalance) {
    index = index - (userAccID * 10);
    userBankAccs[index] = newBalance;
}

int Account::getAccID() { return userAccID; }

// Checks to see if ID number is of a fund within this account
bool Account::isAccFund(int accNum) {
    int accComp = userAccID * 10;
    //takes user ID like 1001 multiplies it by 10. Then 
    //adds one to it each loop to see if it matches the AccNum.
    for (int i = 0; i <= 9; i++) {
        accComp = accComp + i;
        if (accNum == accComp) {
            return true;
        }
    }
    return false;
}

string Account::getAccHolderName() {
    return userNameFirst + " " + userNameLast;
}