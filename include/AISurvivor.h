#ifndef AISURVIVOR_H
#define AISURVIVOR_H

#include "Survivor.h"

// AI-controlled survivor
class AISurvivor : public Survivor {
public:
    void takeTurn() override;
};

#endif