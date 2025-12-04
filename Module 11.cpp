#include <iostream>
using namespace std;

class Product {
private:
    int id;
    string name;
    float price;

public:
    // Constructor
    Product(int i, string n, float p) : id(i), name(n), price(p) {
        cout << "Constructor called for: " << name << endl;
    }

    // Destructor
    ~Product() {
        cout << "Destructor called for: " << name << endl;
    }

    // Display method
    void printDetails() {
        cout << "Product ID: " << id
            << ", Name: " << name
            << ", Price: $" << price
            << endl;
    }
};

int main() {
    // Creates an array of 5 Product objects
    Product products[5] = {
        Product(101, "Dog Treats - Chicken Bites", 8.99),
        Product(102, "Small Dog Harness - Blue", 19.49),
        Product(103, "Puppy Chew Toy - Squeaker", 5.79),
        Product(104, "Dog Hoodie - Pink", 24.99),
        Product(105, "Collapsible Travel Water Bowl", 7.49)
    };

    cout << "\n--- Product Inventory ---" << endl;

    // Loops array of 5 Product objects and prints each product
    for (int i = 0; i < 5; i++) {
        products[i].printDetails();
    }

    return 0;
}
