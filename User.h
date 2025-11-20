#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

// Base class
class User {
public:
    // Constructor
    User() {
        cout << "[User Constructor] User created." << endl;
    }

    // Destructor
    virtual ~User() {
        cout << "[User Destructor] User destroyed." << endl;
    }

    // Virtual method for overriding
    virtual void accessLevel() {
        cout << "General Access" << endl;
    }
};

#endif
