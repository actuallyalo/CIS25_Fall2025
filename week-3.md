#include <iostream>
#include <string>   // Needed for string input
using namespace std;

int main() {
    // Declare variables using clear naming conventions
    string itemName;
    int itemQuantity;
    float itemCost;

    // Prompt and accept user input
    cout << "Enter item name: ";
    cin >> itemName;  // Note: cin stops at spaces (use getline if multi-word names are needed)

    cout << "Enter quantity: ";
    cin >> itemQuantity;

    cout << "Enter cost per item: $";
    cin >> itemCost;

    // Calculate total
    float totalCost = itemQuantity * itemCost;

    // Display result
    cout << "Total cost for " << itemName << ": $" << totalCost << endl;

    return 0;
}
