#include <iostream>
using namespace std;

void handleDinnerChoice(char choice) {
    switch (choice) {
    case 'a':
        cout << "You chose Alfredo Pasta.\n";
        break;
    case 'b':
        cout << "You chose Beef Stroganoff.\n";
        break;
    case 'c':
        cout << "You chose Chicken Parmesan.\n";
        break;
    case 'd':
        cout << "You chose Duck à l'Orange.\n";
        break;
    case 'e':
        cout << "You chose Eggplant Parmesan.\n";
        break;
    case 'f':
        cout << "You chose Fish Tacos.\n";
        break;
    case 'g':
        cout << "You chose Grilled Salmon.\n";
        break;
    case 'h':
        cout << "You chose Honey Glazed Ham.\n";
        break;
    case 'i':
        cout << "You chose Italian Sausage.\n";
        break;
    case 'j':
        cout << "You chose Jambalaya.\n";
        break;
    case 'k':
        cout << "You chose Kung Pao Chicken.\n";
        break;
    case 'l':
        cout << "You chose Lasagna.\n";
        break;
    case 'm':
        cout << "You chose Meatloaf.\n";
        break;
    case 'n':
        cout << "You chose Nachos Supreme.\n";
        break;
    case 'o':
        cout << "You chose Osso Buco.\n";
        break;
    case 'p':
        cout << "You chose Prime Rib.\n";
        break;
    case 'q':
        cout << "You chose Quiche Lorraine.\n";
        break;
    case 'r':
        cout << "You chose Roast Chicken.\n";
        break;
    case 's':
        cout << "You chose Steak.\n";
        break;
    case 't':
        cout << "You chose Tandoori Chicken.\n";
        break;
    case 'u':
        cout << "You chose Udon Noodle Bowl.\n";
        break;
    case 'v':
        cout << "You chose Vegetable Stir Fry.\n";
        break;
    case 'w':
        cout << "You chose Wiener Schnitzel.\n";
        break;
    case 'x':
        cout << "You chose Xacuti (Spicy Curry).\n";
        break;
    case 'y':
        cout << "You chose Yakitori.\n";
        break;
    case 'z':
        cout << "You chose Ziti Bake.\n";
        break;
    default:
        cout << "Invalid dinner item.\n";
    }
}