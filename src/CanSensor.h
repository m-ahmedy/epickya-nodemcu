#ifndef CAN_SENSOR_H
#define CAN_SENSOR_H

#include "Arduino.h"

class CanSensor
{
public:
    virtual ~CanSensor() {};
    virtual boolean isFull() = 0;
};

#endif