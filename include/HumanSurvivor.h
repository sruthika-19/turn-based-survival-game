#ifndef HUMANSURVIVOR_H
#define HUMANSURVIVOR_H

#include "Survivor.h"

// Player-controlled survivor
class HumanSurvivor : public Survivor {
public:
    HumanSurvivor(string n);
    void takeTurn() override;
};

#endif