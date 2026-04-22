#ifndef EVENT_H
#define EVENT_H

#include "Survivor.h"

// Handles random survival events
class Event {
public:
    static void triggerRandomEvent(Survivor* player);
};

#endif