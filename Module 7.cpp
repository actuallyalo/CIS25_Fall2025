#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item {
    string name;
    int id;
};

void populate(Item* collection, int total) {
    for (int i = 0; i < total; ++i) {
        collection[i].name = "Library Book #" + to_string(i + 1);
        collection[i].id = 0 + i * 10;
    }
}

void sortByName(Item* collection, int total) {
    sort(collection, collection + total, [](const Item& a, const Item& b) {
        return a.name < b.name;
    });
}

int* buildIndexById(const Item* collection, int total) {
    int* idx = new int[total];
    for (int i = 0; i < total; ++i) idx[i] = i;
    sort(idx, idx + total, [&](int lhs, int rhs) {
        return collection[lhs].id < collection[rhs].id;
    });
    return idx;
}

int binarySearchById(const Item* collection, const int* indexById, int total, int targetId) {
    int low = 0, high = total - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int midId = collection[indexById[mid]].id;
        if (midId == targetId)
            return indexById[mid];
        else if (midId < targetId)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    const int COUNT = 120;
    Item* warehouse = new Item[COUNT];

    populate(warehouse, COUNT);
    sortByName(warehouse, COUNT);

    int* indexById = buildIndexById(warehouse, COUNT);

    cout << "Welcome to the Library\n";
    cout << "-----------------------------------------------\n";
    cout << "Enter an ID to search for in multiples of 10 (e.g. 10, 20, 30, ...): ";
    int targetId;
    if (!(cin >> targetId)) {
        cerr << "Invalid input. Exiting.\n";
        delete[] indexById;
        delete[] warehouse;
        return 1;
    }

        int pos = binarySearchById(warehouse, indexById, COUNT, targetId);
    if (pos >= 0) {
        cout << "Found!  ID: " << warehouse[pos].id
             << "  Name: " << warehouse[pos].name << "\n";
    } else {
        cout << "ID " << targetId << " not found.\n";
    }

    delete[] indexById;
    delete[] warehouse;

    cout << "Press Enter to exit...";
    cin.ignore();
    cin.get();
    return 0;
}

