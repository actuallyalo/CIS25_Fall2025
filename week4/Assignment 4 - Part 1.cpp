#include <iostream> 
using namespace std;
int main() {
	cout << "Welcome to The Dollhouse! What would you like to do first?" << endl;
	int choice;
	cout << "1. Make the dolls breakfast\n2. Read the dolls a story\n3. Put the dolls to sleep\n";
	cout << "Choose an option: ";
	cin >> choice;

	if (choice == 1) cout << "The dolls sat in the kitchen and enjoyed breakfast!\n";
	else if (choice == 2) cout << "The dolls loved storytime but are getting tired\n";
	else if (choice == 3) cout << "The dolls lie in their beds and dream sweet dreams.\n";
	else cout << "Invalid option.\n";
	system("pause > 0");

}

