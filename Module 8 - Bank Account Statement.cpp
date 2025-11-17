#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;

string nowStamp() {
    time_t t = time(nullptr);
    tm lt;
    localtime_s(&lt, &t);
    char buf[20];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M", &lt);
    return string(buf);
}

class BankAccount {
private:
    string name;
    double balance;

    void saveTransaction(const string& type, double amount, const string& memo = "") {
        ofstream file("transactions.txt", ios::app);
        if (file.is_open()) {
            file << left << setw(16) << nowStamp()
                << left << setw(12) << name
                << left << setw(12) << type
                << right << setw(10) << fixed << setprecision(2) << amount
                << "  "
                << left << setw(18) << memo
                << "Balance: $" << fixed << setprecision(2) << balance
                << "\n";
            file.close();
        }
        else {
            cout << "Error opening transactions.txt\n";
        }
    }

public:
    BankAccount(const string& accountName = "Checking") : name(accountName), balance(0.0) {}

    const string& getName() const { return name; }
    double getBalance() const { return balance; }

    void deposit(double amount) {
        if (amount <= 0) { cout << "Amount must be positive.\n"; return; }
        balance += amount;
        cout << "Deposited $" << fixed << setprecision(2) << amount
            << " to " << name << ". New balance: $"
            << fixed << setprecision(2) << balance << "\n";
        saveTransaction("Deposit", amount);
    }

    bool withdraw(double amount, const string& reason = "Withdrawal") {
        if (amount <= 0) { cout << "Amount must be positive.\n"; return false; }
        if (amount > balance) {
            cout << "Insufficient funds in " << name << ".\n";
            return false;
        }
        balance -= amount;
        cout << reason << " of $" << fixed << setprecision(2) << amount
            << " from " << name << ". New balance: $"
            << fixed << setprecision(2) << balance << "\n";
        saveTransaction(reason, amount);
        return true;
    }

    void purchase(const string& item, double cost) {
        if (withdraw(cost, "Purchase")) {
            saveTransaction("Purchase", cost, item);
        }
    }

    void display() const {
        cout << left << setw(12) << name
            << " | Current Balance: $"
            << fixed << setprecision(2) << balance << "\n";
    }

    bool transferTo(BankAccount& other, double amount) {
        if (amount <= 0) { cout << "Amount must be positive.\n"; return false; }
        if (amount > balance) {
            cout << "Insufficient funds in " << name << " for transfer.\n";
            return false;
        }
        balance -= amount;
        saveTransaction("Transfer Out", amount, "-> " + other.getName());

        other.balance += amount;
        other.saveTransaction("Transfer In", amount, "From " + name);

        cout << "Transferred $" << fixed << setprecision(2) << amount
            << " from " << name << " to " << other.getName() << ".\n";
        cout << "  " << name << " New Balance: $" << fixed << setprecision(2) << balance << "\n";
        cout << "  " << other.getName() << " New Balance: $" << fixed << setprecision(2) << other.getBalance() << "\n";
        return true;
    }
};

void printHeaderOnce() {
    ofstream file("transactions.txt", ios::app);
    if (file.is_open()) {
        file << "\n===== Session Start: " << nowStamp() << " =====\n";
        file << left << setw(16) << "Timestamp"
            << left << setw(12) << "Account"
            << left << setw(12) << "Type"
            << right << setw(10) << "Amount"
            << "  " << left << setw(18) << "Memo"
            << "Balance\n";
        file << string(78, '-') << "\n";
        file.close();
    }
}

void printMenu() {
    cout << "\n========== BANK OF ALEX ==========\n"
        << "Hello! What would you like to do today?\n"
        << "1) Deposit\n"
        << "2) Withdraw\n"
        << "3) Purchase (with item name)\n"
        << "4) Transfer (Checking <-> Savings)\n"
        << "5) Show Balances\n"
        << "6) Show Statement (from transactions.txt)\n"
        << "0) Exit\n"
        << "Select: ";
}

void showStatement() {
    ifstream file("transactions.txt");
    if (!file.is_open()) {
        cout << "No transactions yet (transactions.txt not found).\n";
        return;
    }
    cout << "\n========== Bank Statement ==========\n";
    string line;
    while (getline(file, line)) cout << line << "\n";
    cout << "====================================\n";
    file.close();
}

int main() {
    BankAccount checking("Checking");
    BankAccount savings("Savings");

    printHeaderOnce();

    int choice = -1;
    while (true) {
        printMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        switch (choice) {
        case 1: {
            // Deposit
            double amount;
            cout << "Enter amount to deposit: ";
            if (!(cin >> amount)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid amount. Please try again.\n";
                continue;
            }
            checking.deposit(amount);
        } break;
        case 2: {
            // Withdraw
            double amount;
            cout << "Enter amount to withdraw: ";
            if (!(cin >> amount)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid amount. Please try again.\n";
                continue;
            }
            checking.withdraw(amount);
        } break;
        case 3: {
            // Purchase
            string item;
            double cost;
            cout << "Enter item name: ";
            cin.ignore();
            getline(cin, item);
            cout << "Enter item cost: ";
            if (!(cin >> cost)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid cost. Please try again.\n";
                continue;
            }
            checking.purchase(item, cost);
        } break;
        case 4: {
            // Transfer
            double amount;
            cout << "Enter amount to transfer: ";
            if (!(cin >> amount)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid amount. Please try again.\n";
                continue;
            }
            cout << "1) Checking to Savings\n2) Savings to Checking\nSelect direction: ";
            int dir;
            if (!(cin >> dir) || (dir != 1 && dir != 2)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid direction. Please try again.\n";
                continue;
            }
            if (dir == 1) {
                checking.transferTo(savings, amount);
            } else {
                savings.transferTo(checking, amount);
            }
        } break;
        case 5:
            checking.display();
            savings.display();
            break;
        case 6:
            showStatement();
            break;
        case 0:
            cout << "Goodbye!\n";
            return 0;
        default:
            cout << "Invalid selection. Try again.\n";
        }
    }
}
