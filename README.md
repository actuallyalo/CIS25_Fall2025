.5// hello_inventory.cpp
#include <iostream>8

int main() {
    // Print greeting with escape characters
    std::cout << "Hello Inventory System!\n";
    std::cout << "\tWelcome to the inventory tracker.\n";
    std::cout << "\nLet's explore some data types:\n";

    // Output sizes of int, float, and char
    std::cout << "\tSize of int: " << sizeof(int) << " bytes\n";
    std::cout << "\tSize of float: " << sizeof(float) << " bytes\n";
    std::cout << "\tSize of char: " << sizeof(char) << " bytes\n";

    return 0;
}