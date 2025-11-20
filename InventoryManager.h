#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include "Employee.h"

class InventoryManager : public Employee {
public:
    InventoryManager() {
        cout << "[InventoryManager Constructor] Inventory Manager created." << endl;
    }

    ~InventoryManager() override {
        cout << "[InventoryManager Destructor] Inventory Manager destroyed." << endl;
    }

    // Override again
    void accessLevel() override {
        cout << "Full Inventory Management Access" << endl;
    }
};

#endif
