#include "../include/Survivor.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>  
#include <ctime>    
using namespace std;

// Constructor
Survivor::Survivor(string n)
{
    name = n;
    health = 100;
    hunger = 0;
    energy = 100;
    alive = true;
}

void Survivor::clampStats() {
    health = max(0, health);
    hunger = min(100, max(0, hunger));
    energy = min(100, max(0, energy));
}

// Collect resources from environment
void Survivor::search() {
    if (!alive) return;

    if (energy < 10) {
        cout << name << " is too exhausted to search properly.\n";
        return;
    }
    string messages[] = {
    " searches the area for supplies.",
    " looks around for anything useful.",
    " scavenges the surroundings.",
    " explores cautiously, staying alert."
    };

    cout << name << messages[rand() % 4] << "\n";
    
    int roll = rand() % 100;  
    energy -= 10;
    hunger += 5;

    if (roll < 10) {
        cout << "Trap triggered! Injured!\n";
        health -= 15;
    }
    else if (roll < 55) {
        cout << "Found food.\n";
        inventory.addItem("food", 1);
    }
    else
        cout << "Nothing found.\n";

    clampStats();
}

// Rest to recover energy
void Survivor::rest() {
    if (!alive) return;
    if (energy >= 100) {
    cout << name << " is already fully rested.\n";
    return;
    }

    string restMsgs[] = {
    " takes a short rest.",
    " lies down to regain energy.",
    " relaxes for a while.",
    " rests in a safe place."
    };

    cout << name << restMsgs[rand() % 4] << "\n";
    energy += 20;
    health += 5;
    hunger += 5;
    clampStats();
}

// Explore unknown area (may trigger events)
void Survivor::explore() {
    if (!alive) return;
    if (energy < 20) {
        cout << name << " is too exhausted to act.\n";
        return;
    }

    string exploreMsgs[] = {
    " ventures into dangerous territory.",
    " steps into a hostile area.",
    " explores a place filled with threats.",
    " moves forward despite the danger."
    };

    cout << name << exploreMsgs[rand() % 4] << "\n";
    int event = rand() % 3;

    int roll = rand() % 100;   

    energy -= 20;
    hunger += 10;

    if (roll < 15) {
        cout << "Ambush! Heavy damage.\n";
        health -= 25;
    }
    else if (roll < 40) {
        cout << "Enemy attack!\n";
        health -= 15;
    }
    else if (roll < 70) {
        cout << "Found supplies.\n";
        inventory.addItem("food", 1);
    }
    else {
        cout << "Great find!\n";
        inventory.addItem("food", 2);
        energy += 10;
    }

    clampStats();
}

// Use item from inventory
void Survivor::useItem(const string& itemType) {
    if (!alive) return;
    int effectiveness = rand() % 100;  // 0–99

    if (itemType == "food") {
        cout << name << " consumes food.\n";

        if (inventory.useItem("food")) {
            hunger -= 20;
            energy += 5;
        }
        else {
            cout << "No food available.\n";
        }
    }
    else if (itemType == "medicine") {
        cout << name << " uses medicine.\n";

        if (inventory.useItem("medicine")) {
            health += 25;
        }
        else {
            cout << "No medicine available.\n";
        }
    }

    clampStats();
}

// Update health, hunger, energy each turn
void Survivor::updateStatus() {
    if (!alive) return;
    hunger += 5;
    energy -= 5;

    clampStats();
    if (hunger >= 100) {
        health -= 10;
        energy -= 5;
        cout << name << " is starving!\n";
    }

    clampStats();

    if (health <= 0) {
        alive = false;
        cout << name << " has died 💀\n";
    }
}

// Show current stats of player
void Survivor::displayStats() {
    cout << "\n--- " << name << " Stats ---\n";
    cout << "Health: " << health << "\n";
    cout << "Hunger: " << hunger << "\n";
    cout << "Energy: " << energy << "\n";
    inventory.displayInventory();
}

// Check if player is alive
bool Survivor::isAlive() {
    return alive;
}