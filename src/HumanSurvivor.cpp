#include "../include/HumanSurvivor.h"
#include <iostream>
#include <string>
using namespace std;

HumanSurvivor::HumanSurvivor(string n): Survivor(n){}

// Handles user input actions
void HumanSurvivor::takeTurn() {
    if(!isAlive()) return;
    int choice = -1;
    string input;

    displayStats();
    cout << "\n----- Choose Action ----- \n";
    cout << "1. Search  (Cost: 10 Energy)\n";
    cout << "2. Rest    (Gain: 20 Energy)\n";
    cout << "3. Explore (Cost: 20 Energy, Risky)\n";
    cout << "4. Use Food \n";
    cout << "5. Use Medicine \n";



    while(true)
    {
        cout << "Enter Choice (1-5): ";
        getline(cin, input);
        if (input.empty()) {
            cout << "Input cannot be empty.\n";
            continue;
        }
        try {
            choice = stoi(input);
            if (choice >= 1 && choice <= 5) break;
            else
                cout << "Choice must be between 1 and 5.\n"; 
        }
        catch(...) {
            cout << "Invalid input. Please enter a number.\n";
        }
    }
    
    cout << "\n";
    switch(choice)
    {
        case 1: search(); break;
        case 2: rest(); break;
        case 3: explore(); break; 
        case 4: useItem("food"); break;
        case 5: useItem("medicine"); break;
    }

    updateStatus();
    cout << "\n----- Turn Ended -----\n";
}