#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Survivor.h"
using namespace std;

// Controls the entire game flow
class Game {
private:
    vector<Survivor*> players;   // list of all players
    int currentDay;              // game day counter
    bool gameOver;               // game status

public:
    void startGame();
    void gameLoop();
    void nextTurn();
    void checkGameOver();
    void displayGameStatus();
};

#endif