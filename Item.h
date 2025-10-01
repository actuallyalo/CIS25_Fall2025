#pragma once
#include <string>

class Item {
public:
    std::string name{};
    int quantity{0};

    void saveToFile() const;
    static void loadFromFile();
};