#include "../include/Inventory.h"
#include <iostream>
using namespace std;

// Add items to inventory
void Inventory::addItem(string item, int qty) {}

// Use item if exists
bool Inventory::useItem(string item) { return false; }

// Show inventory contents
void Inventory::displayInventory() {}

bool Inventory::hasItem(const string& item) const {
    auto it = items.find(item);
    return it != items.end() && it->second > 0;
}