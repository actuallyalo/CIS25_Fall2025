#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "User.h"

// Employee class inherits from User
// This means Employee automatically gets accessLevel(),
// but can override it to provide different behavior.
class Employee : public User {
public:
    // Override the parent's version to customize access rules
    void accessLevel() override {
        cout << "Employee Access" << endl;
    }
};

#endif
