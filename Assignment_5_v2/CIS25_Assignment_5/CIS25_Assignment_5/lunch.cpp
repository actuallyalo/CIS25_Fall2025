#include <iostream>
using namespace std;

void handleLunchChoice(char choice) {
    switch (choice) {
    case 'a':
        cout << "You chose Avocado BLT.\n";
        break;
    case 'b':
        cout << "You chose Burrito.\n";
        break;
    case 'c':
        cout << "You chose Chicken Caesar Wrap.\n";
        break;
    case 'd':
        cout << "You chose Deli Sandwich.\n";
        break;
    case 'e':
        cout << "You chose Egg Salad Sandwich.\n";
        break;
    case 'f':
        cout << "You chose Falafel Pita.\n";
        break;
    case 'g':
        cout << "You chose Grilled Cheese.\n";
        break;
    case 'h':
        cout << "You chose Ham and Swiss.\n";
        break;
    case 'i':
        cout << "You chose Italian Sub.\n";
        break;
    case 'j':
        cout << "You chose Jambon-Beurre.\n";
        break;
    case 'k':
        cout << "You chose Kale Salad.\n";
        break;
    case 'l':
        cout << "You chose Lentil Soup.\n";
        break;
    case 'm':
        cout << "You chose Meatball Sub.\n";
        break;
    case 'n':
        cout << "You chose Noodle Bowl.\n";
        break;
    case 'o':
        cout << "You chose Open-Faced Turkey Sandwich.\n";
        break;
    case 'p':
        cout << "You chose Panini.\n";
        break;
    case 'q':
        cout << "You chose Quinoa Salad.\n";
        break;
    case 'r':
        cout << "You chose Reuben Sandwich.\n";
        break;
    case 's':
        cout << "You chose Salad.\n";
        break;
    case 't':
        cout << "You chose Tuna Melt.\n";
        break;
    case 'u':
        cout << "You chose Udon Noodle Soup.\n";
        break;
    case 'v':
        cout << "You chose Veggie Burger.\n";
        break;
    case 'w':
        cout << "You chose Waldorf Salad.\n";
        break;
    case 'x':
        cout << "You chose Xacuti (Goan Curry Sandwich).\n";
        break;
    case 'y':
        cout << "You chose Yellow Split Pea Soup.\n";
        break;
    case 'z':
        cout << "You chose Zucchini Fritters.\n";
        break;
    default:
        cout << "Invalid lunch item.\n";
    }
}
