#include "../include/AISurvivor.h"
#include <iostream>
#include <cstdlib>
using namespace std;

AISurvivor::AISurvivor(string n): Survivor(n){}

// AI logic for survival decisions
void AISurvivor::takeTurn() {
    if (!isAlive()) return;

    cout << "\n🤖 AI Survivor Turn: " << endl;
    displayStats();

    int decision = rand() % 100;

    if (health <= 25) {
        if (inventory.hasItem("medicine")) {
            useItem("medicine");
        } else {
            rest();
        }
    }
    else if (hunger >= 70) {
        if (inventory.hasItem("food")) {
            useItem("food");
        } else {
            search();
        }
    }
    else if (energy <= 20) {
        rest();
    }
    else {
        if (decision < 50) search();
        else explore();
    }

    updateStatus();
    cout << "🤖 AI Turn Ended\n";
}