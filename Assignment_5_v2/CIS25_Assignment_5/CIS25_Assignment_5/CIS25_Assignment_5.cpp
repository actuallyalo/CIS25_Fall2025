#include <iostream>
#include <cstdlib>
#include "lunch.h"
#include "breakfast.h"
#include "dinner.h"

using namespace std;

// Update showMenu to accept a name parameter
void showMenu(const string& name) {
    cout << "What can we get for you today, " << name << "?\n1. Breakfast\n2. Lunch\n3. Dinner\n";
}

int main() {
    string name;
    cout << "Please let us know your name to begin your order: ";
    cin >> name;

    char again = 'y';
    while (tolower(again) == 'y') {
        showMenu(name); // Pass the name to showMenu
        int choice = 0;
        cin >> choice;

        char letter;
        if (choice == 1) {
            cout << "What a great choice, Breakfast!\n";
            cout << "Choose a breakfast item (a-z): ";
            cin >> letter;
            handleBreakfastChoice(tolower(letter));
        }
        else if (choice == 2) {
            cout << "Lunch sounds excellent!\n";
            cout << "Choose a lunch item (a-z): ";
            cin >> letter;
            handleLunchChoice(tolower(letter));
        }
        else if (choice == 3) {
            cout << "Dinner is the most important meal of the day!\n";
            cout << "Choose a dinner item (a-z): ";
            cin >> letter;
            handleDinnerChoice(tolower(letter));
        }
        else {
            cout << "Invalid menu choice.\n";
        }

        cout << "Would you like to order anything else? (y/n): ";
        cin >> again;
    }

    cout << "Thanks for stopping by, " << name << ". Have a great day!" << endl;
    system("pause>0");
    return 0;
}