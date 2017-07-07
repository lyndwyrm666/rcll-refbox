// The ring station mounts rings on bases
#pragma once

#include "Machine.h"

class RingStation: public Machine {
  public:
    RingStation();
    virtual ~RingStation();

    // Send command to get a ring
    // void getRing();
    // Check, if the cap is ready for take away
    // deprecated
    bool ringReady();

    // identify: tell PLC, which machine it is running on
    virtual void identify();
};
