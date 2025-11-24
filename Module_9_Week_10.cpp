#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// =======================================
// Item Class (Meetup Inventory Item)
// =======================================
class Item {
public:
    string name;
    int quantity;

    Item() {
        name = "";
        quantity = 0;
    }

    void printItem() const {
        cout << name << " - Qty: " << quantity << endl;
    }
};

// =======================================
// Save to File
// =======================================
void saveInventoryToFile(Item inventory[], int size, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error opening file for writing." << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        outFile << inventory[i].name << " " << inventory[i].quantity << endl;
    }
    outFile.close();
    cout << "Inventory saved to " << filename << endl;
}

// =======================================
// Show Inventory from File
// =======================================
void showInventoryFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error opening file for reading." << endl;
        return;
    }
    cout << "\n=========== INVENTORY FROM FILE ===========" << endl;
    string name;
    int quantity;
    while (inFile >> name >> quantity) {
        cout << name << " - Qty: " << quantity << endl;
    }
    inFile.close();
}

// =======================================
// MAIN PROGRAM
// =======================================
int main() {
    const int SIZE = 5;
    Item inventory[SIZE];
    const string filename = "meetup_inventory.txt";

    cout << "=======================================" << endl;
    cout << " SMALL DOG MEETUP - INVENTORY TRACKER" << endl;
    cout << " Brooklyn Basin, Oakland" << endl;
    cout << "=======================================" << endl;

    cout << "\nEnter the 5 items you want to track." << endl;
    cout << "(Examples: TreatBags, WaterBowls, Wristbands, Toys, DogSnacks)" << endl;

    // User input (inventory setup)
    for (int i = 0; i < SIZE; i++) {
        cout << "\nEnter name for inventory item #" << (i + 1) << ": ";
        cin >> inventory[i].name;

        int qty;
        cout << "Enter quantity for " << inventory[i].name << ": ";
        while (true) {
            cin >> qty;
            if (cin.fail() || qty < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a non-negative integer for quantity: ";
            } else {
                inventory[i].quantity = qty;
                break;
            }
        }
    }

    cout << "\n=========== MEETUP INVENTORY LIST ===========" << endl;
    for (int i = 0; i < SIZE; i++) {
        inventory[i].printItem();
    }

    while (true) {
        cout << "\nWhat item would you like to check?" << endl;
        cout << "Type the item name, 'print' to show inventory, 'save' to save to file, 'showfile' to display saved inventory, or 'exit' to quit: ";
        string searchName;
        cin >> searchName;

        if (searchName == "exit") {
            cout << "Exiting search." << endl;
            break;
        } else if (searchName == "print") {
            cout << "\n=========== MEETUP INVENTORY LIST ===========" << endl;
            for (int i = 0; i < SIZE; i++) {
                inventory[i].printItem();
            }
            continue;
        } else if (searchName == "save") {
            saveInventoryToFile(inventory, SIZE, filename);
            continue;
        } else if (searchName == "showfile") {
            showInventoryFromFile(filename);
            continue;
        }

        bool found = false;
        for (int i = 0; i < SIZE; i++) {
            if (inventory[i].name == searchName) {
                cout << "\nFOUND in Meetup Inventory!" << endl;
                cout << searchName << " - Quantity Available: "
                    << inventory[i].quantity << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "\nSorry, that item isn't in the Meetup inventory. Try again." << endl;
        }
    }

    return 0;
}
