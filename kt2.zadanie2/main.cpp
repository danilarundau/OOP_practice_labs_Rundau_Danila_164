#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class BankAccount {
protected:
    string ownerName;
    string accountNumber;
    double balance;

    bool isValidAmount(double amount) const {
        return amount > 0;
    }

public:
    BankAccount(const string& owner, const string& accNum, double initialBalance)
        : ownerName(owner), accountNumber(accNum), balance(initialBalance) {}
    virtual ~BankAccount() {}

    virtual void deposit(double amount) {
        if (isValidAmount(amount)) {
            balance += amount;
        }
    }

    virtual bool withdraw(double amount) {
        if (isValidAmount(amount) && balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    virtual void displayInfo() const {
        cout << "Owner: " << ownerName << ", Account: " << accountNumber << ", Balance: " << balance << endl;
    }

    BankAccount operator+=(double amount) {
        deposit(amount);
        return *this;
    }

    BankAccount operator-=(double amount) {
        withdraw(amount);
        return *this;
    }

    bool operator>(const BankAccount& other) const {
        return balance > other.balance;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(const string& owner, const string& accNum, double initialBalance, double rate)
        : BankAccount(owner, accNum, initialBalance), interestRate(rate) {}

    void deposit(double amount) override {
        if (isValidAmount(amount)) {
            balance += amount + (amount * interestRate);
        }
    }

    void displayInfo() const override {
        BankAccount::displayInfo();
        cout << "Interest Rate: " << interestRate << endl;
    }

    SavingsAccount operator+(const SavingsAccount& other) const {
        return SavingsAccount(ownerName, accountNumber, balance + other.balance, interestRate);
    }
};

void processTransaction(BankAccount& acc, double amount) {
    acc.deposit(amount);
}

void processTransaction(BankAccount& acc1, BankAccount& acc2, double amount) {
    if (acc1.withdraw(amount)) {
        acc2.deposit(amount);
    }
}

int main() {
    SavingsAccount sa1("Alice", "123", 1000.0, 0.05);
    SavingsAccount sa2("Bob", "456", 1500.0, 0.07);
    BankAccount ba1("Charlie", "789", 500.0);

    vector<BankAccount*> accounts;
    accounts.push_back(&sa1);
    accounts.push_back(&sa2);
    accounts.push_back(&ba1);

    cout << "--- Initial Info ---" << endl;
    for (auto acc : accounts) {
        acc->displayInfo();
    }
    cout << endl;

    cout << "--- Operator Overloads ---" << endl;
    sa1 += 200.0;
    sa1.displayInfo();
    ba1 -= 100.0;
    ba1.displayInfo();
    cout << "sa1 > sa2: " << (sa1 > sa2) << endl;
    cout << endl;

    cout << "--- Overloaded Function Calls ---" << endl;
    processTransaction(sa1, 300.0);
    processTransaction(sa1, ba1, 150.0);
    
    cout << "\n--- Final Info ---" << endl;
    for (auto acc : accounts) {
        acc->displayInfo();
    }
    cout << endl;

    SavingsAccount combinedSA = sa1 + sa2;
    cout << "--- Combined Savings Account ---" << endl;
    combinedSA.displayInfo();

    return 0;
}
