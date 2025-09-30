#include <iostream>
#include <algorithm>
using namespace std;

int main()
{ 
    string breed;
    int quantity;
    float cost = 0, totalCost;

    cout << "Hello! We're excited to have you foster, but did you know the cost? Have you decided on the breed you'd prefer to take in? (Dalmatian, Poodle, Labrador): ";
    cin >> breed;

    transform(breed.begin(), breed.end(), breed.begin(), ::tolower);

    if (breed.substr(0, 3) == "dal")
        cost = 5000;
    else if (breed.substr(0, 3) == "poo")
        cost = 6000;
    else if (breed.substr(0, 3) == "lab")
        cost = 3000;
    else {
        cout << "Unknown breed selected." << endl;
        return 1;
    }

    cout << "Well isn't that cute? How many would you like? ";
    cin >> quantity;

    totalCost = quantity * cost;

    cout << "Total cost for " << quantity << " " << breed << "(s) is: $" << totalCost << endl;
    
    system("pause>0");
    return 0;
}
