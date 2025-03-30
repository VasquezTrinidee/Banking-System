#include <iostream>
#include <cassert>

using namespace std;

class BankingSystem {
private:
    double balance;

public:
    BankingSystem() : balance(0.0) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful! New balance is: $" << balance << "\n";
        } else {
            cout << "Invalid amount. Deposit must be positive.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful! New balance: $" << balance << "\n";
        } else if (amount > balance) {
            cout << "Insufficient funds! Withdrawal failed.\n";
        } else {
            cout << "Invalid amount. Withdrawal must be positive.\n";
        }
    }

    void checkBalance() const {
        cout << "Your current balance is: $" << balance << "\n";
    }
};

int main() {
    BankingSystem bank;
    int choice;
    double amount;

    while (true) {
        cout << "\n==== BANKING SYSTEM ====\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "========================\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                bank.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                bank.withdraw(amount);
                break;
            case 3:
                bank.checkBalance();
                break;
            case 4:
                cout << "Exiting the banking system. Thank you for using our service!\n";
                return 0;
            default:
                cout << "Invalid option! Please choose a valid menu option.\n";
        }
    }
}
