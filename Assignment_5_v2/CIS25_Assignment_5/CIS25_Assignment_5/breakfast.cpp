#include <iostream>
using namespace std;

void handleBreakfastChoice(char choice) {
    switch (choice) {
    case 'a':
        cout << "You chose Avocado Toast.\n";
        break;
    case 'b':
        cout << "You chose Bagel with Cream Cheese.\n";
        break;
    case 'c':
        cout << "You chose Cereal.\n";
        break;
    case 'd':
        cout << "You chose Donut.\n";
        break;
    case 'e':
        cout << "You chose Eggs Benedict.\n";
        break;
    case 'f':
        cout << "You chose French Toast.\n";
        break;
    case 'g':
        cout << "You chose Granola Bar.\n";
        break;
    case 'h':
        cout << "You chose Hash Browns.\n";
        break;
    case 'i':
        cout << "You chose Irish Oatmeal.\n";
        break;
    case 'j':
        cout << "You chose Juice.\n";
        break;
    case 'k':
        cout << "You chose Kielbasa Sausage.\n";
        break;
    case 'l':
        cout << "You chose Lox and Bagel.\n";
        break;
    case 'm':
        cout << "You chose Muffin.\n";
        break;
    case 'n':
        cout << "You chose Nutella Crepe.\n";
        break;
    case 'o':
        cout << "You chose Omelette.\n";
        break;
    case 'p':
        cout << "You chose Pancakes.\n";
        break;
    case 'q':
        cout << "You chose Quiche.\n";
        break;
    case 'r':
        cout << "You chose Raisin Toast.\n";
        break;
    case 's':
        cout << "You chose Smoothie.\n";
        break;
    case 't':
        cout << "You chose Toast.\n";
        break;
    case 'u':
        cout << "You chose Upside-down Cake.\n";
        break;
    case 'v':
        cout << "You chose Veggie Scramble.\n";
        break;
    case 'w':
        cout << "You chose Waffles.\n";
        break;
    case 'x':
        cout << "You chose Xigua (Chinese Watermelon).\n";
        break;
    case 'y':
        cout << "You chose Yogurt Parfait.\n";
        break;
    case 'z':
        cout << "You chose Zucchini Bread.\n";
        break;
    default:
        cout << "Invalid breakfast item.\n";
    }
}
