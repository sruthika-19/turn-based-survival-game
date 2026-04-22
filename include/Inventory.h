#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include <string>
using namespace std;

// Stores items for each survivor
class Inventory {
private:
    map<string, int> items;

public:
    void addItem(string item, int qty);
    bool useItem(string item);
    void displayInventory();
};

#endif