/*
Design the class(es) for the following. Each account has account number and
balance amount. A list of account is to be maintained where one can add and
find account, display information of all accounts. While adding, account number
must be unique. Withdraw object has account number (must exist) and amount
(will not exceed balance amount of corresponding account). Withdraw object will
update the balance of corresponding account in the list. User will be able to
search and view account, add account and withdraw money from the
account. Implement your design. Use friend function wherever required and
again, modify your implementation to avoid friend function.
*/


#include <iostream>
#include <vector>
#include <set>
#include <stdexcept>
#include <string>


enum Status {
    pending,
    successful,
    failed
};


enum TransactionType {
    withdrawal,
    deposit
};


class Transaction;


class Account {
public:
    Account(int accountNumber, int initialBalance, std::string dateOfLastUpdate) {
        _accountNumber = accountNumber;
        _balance = initialBalance;
        _dateOfLastUpdate = dateOfLastUpdate;
    }

    int getBalance() const {
        return _balance;
    }

    std::string getDateOfLastUpdate() const {
        return _dateOfLastUpdate;
    }

    bool isWithdrawalPossible(int withdrawalAmount) {
        return (withdrawalAmount <= _balance);
    }

    int updateBalance(int delta) {
        _balance += delta;
    }

    void pushTransaction(Transaction* transaction) {
        TransactionLog.push_back(transaction);
    }

private:
    int _accountNumber;
    int _balance;
    std::string _dateOfLastUpdate;

    std::vector<Transaction *> TransactionLog;
};



class Transaction {
public:
    Transaction(Account* balance, int amount, std::string _dateOfTransaction, char transactionType) {
        _balance = balance;
        _amount = amount;
        _dateOfTransaction = _dateOfTransaction;
        _status = Status::pending;

        if (transactionType == 'W') {
            _transactionType = TransactionType::withdrawal;
        } else if (transactionType == 'D') {
            _transactionType = TransactionType::deposit;
        } else {
            throw std::runtime_error("Invalid Transaction Type!");
        }
    }


    void performTransaction() {
        if (_transactionType == TransactionType::deposit) {
            performDeposit();
        } else {
            performWithdrawal();
        }

        if (_status == Status::successful) {
            _balance->pushTransaction(this);
        }
    }

private:
    Account* _balance;
    std::string _dateOfTransaction;
    int _amount;
    Status _status;
    TransactionType _transactionType;

    void performDeposit() {
        _balance->updateBalance(_amount);
        _status = Status::successful;
    }


    void performWithdrawal() {
        if (_balance->isWithdrawalPossible(_amount)) {
            _balance->updateBalance(-_amount);
            _status = Status::successful;
        } else {
            _status = Status::failed;
        }
    }
};



class AccountFactorySingleton {
public:
    static AccountFactorySingleton* getInstance() {
        if (_accountFactory == nullptr) {
            _accountFactory = new AccountFactorySingleton();
        }

        return _accountFactory;
    }

    AccountFactorySingleton(const AccountFactorySingleton&) = delete;
    AccountFactorySingleton& operator=(const AccountFactorySingleton&) = delete;

    bool isAccountNumberUnique(int accountNumber) {
        return (_accountNumberSet.find(accountNumber) == _accountNumberSet.end());
    }

    Account* createBalance(int accountNumber, int initialBalance) {
        if (isAccountNumberUnique(accountNumber)) {
            _accountNumberSet.insert(accountNumber);

            return new Account(accountNumber, initialBalance, "N/A");
        } else {
            return nullptr;
        }
    }

private:
    static AccountFactorySingleton *_accountFactory;

    AccountFactorySingleton() = default;
    std::set<int> _accountNumberSet;
};

AccountFactorySingleton* AccountFactorySingleton::_accountFactory = nullptr;


int main() {
    // Client Code

    return 0;
}
