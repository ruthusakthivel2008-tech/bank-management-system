#include <iostream>
#include <fstream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string name;
    float balance;

public:
    void createAccount() {
        cout << "\nEnter Account Number: ";
        cin >> accountNumber;

        cin.ignore();
        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Initial Balance: ";
        cin >> balance;

        saveToFile();

        cout << "\nAccount Created Successfully!\n";
    }

    void deposit() {
        float amount;
        cout << "\nEnter amount to deposit: ";
        cin >> amount;

        balance += amount;

        cout << "Amount Deposited Successfully!\n";
        cout << "Updated Balance: " << balance << endl;
    }

    void withdraw() {
        float amount;
        cout << "\nEnter amount to withdraw: ";
        cin >> amount;

        if (amount > balance) {
            cout << "Insufficient Balance!\n";
        } else {
            balance -= amount;
            cout << "Withdrawal Successful!\n";
            cout << "Remaining Balance: " << balance << endl;
        }
    }

    void display() {
        cout << "\n----- Account Details -----\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Customer Name  : " << name << endl;
        cout << "Balance        : " << balance << endl;
    }

    void saveToFile() {
        ofstream file("bankdata.txt", ios::app);

        file << accountNumber << endl;
        file << name << endl;
        file << balance << endl;

        file.close();
    }
};

int main() {
    BankAccount acc;
    int choice;

    do {
        cout << "\n====== Bank Management System ======\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Display Account Details\n";
        cout << "5. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                acc.createAccount();
                break;

            case 2:
                acc.deposit();
                break;

            case 3:
                acc.withdraw();
                break;

            case 4:
                acc.display();
                break;

            case 5:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}