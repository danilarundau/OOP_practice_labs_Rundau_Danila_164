#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    BankAccount(string number, double initialBalance) : accountNumber(number), balance(initialBalance) {}

    string getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << ". New balance: " << balance << endl;
        }
        else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            cout << "Withdrawn " << amount << ". New balance: " << balance << endl;
        }
        else if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
        }
        else {
            cout << "Insufficient balance." << endl;
        }
    }
};

int main() {
    BankAccount account("1234567890", 1000.0);

    cout << "Account Number: " << account.getAccountNumber() << endl;
    cout << "Balance: " << account.getBalance() << endl;

    account.deposit(500.0);
    account.withdraw(200.0);
    account.withdraw(1500.0);
    account.withdraw(-100);
    account.deposit(-50);

    return 0;
}

