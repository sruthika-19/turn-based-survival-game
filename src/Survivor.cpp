#include "Survivor.h"
#include <iostream>
using namespace std;

// Collect resources from environment
void Survivor::search() {}

// Rest to recover energy
void Survivor::rest() {}

// Explore unknown area (may trigger events)
void Survivor::explore() {}

// Use item from inventory
void Survivor::useItem() {}

// Update health, hunger, energy each turn
void Survivor::updateStatus() {}

// Show current stats of player
void Survivor::displayStats() {}

// Check if player is alive
bool Survivor::isAlive() {
    return alive;
}