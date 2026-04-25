#ifndef SURVIVOR_H
#define SURVIVOR_H

#include <string>
#include "Inventory.h"
using namespace std;

// Base class for all survivors
class Survivor {
protected:
    string name;
    int health;
    int hunger;
    int energy;
    bool alive;
    Inventory inventory;

public:
    virtual void takeTurn() = 0;
    Survivor(string n);
    void search();
    void rest();
    void explore();
    void useItem(const string& itemType);
    void updateStatus();
    void displayStats();
    bool isAlive();
    void clampStats();
};

#endif