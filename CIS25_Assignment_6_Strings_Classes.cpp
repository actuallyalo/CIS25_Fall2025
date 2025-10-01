#include "Item.h"
#include <iostream>
using namespace std;

int main() {
    Item water;
    water.name = "Water bottles";
    water.quantity = 12;
    water.saveToFile();

    Item flashlight;
    flashlight.name = "Flashlight";
    flashlight.quantity = 2;
    flashlight.saveToFile();

    Item kit;
    kit.name = "First Aid Kit";
    kit.quantity = 1;
    kit.saveToFile();

    Item tampons;
    kit.name = "Tampons";
    kit.quantity = 4;
    kit.saveToFile();

    Item::loadFromFile();
    return 0;
}
