#include "Item.h"
#include <fstream>
#include <iostream>

void Item::saveToFile() const {
    std::ofstream file("earths.txt", std::ios::app);
    if (file.is_open()) {
        file << name << "," << quantity << std::endl;
        file.close();
    }
}

void Item::loadFromFile() {
    std::ifstream file("earths.txt");
    std::string line;
    if (file.is_open()) {
        std::cout << "Earthquake Supply Bag Contents:\n";
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }
}