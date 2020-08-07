#ifndef TRASH_CAN_H
#define TRASH_CAN_H

#include "Ultrasonic.h"
#include "FirebaseESP8266.h"
#include "Location.h"
#include "CanSensor.h"

class TrashCan : public JSONSerializer
{
private:
    String _canId;
    String _ownerUserId;
    String _trashType;
    Location _location;
    double _maxWeight;
    std::vector<CanSensor*> _sensorRefs;

public:
    TrashCan();
    ~TrashCan();

    TrashCan(String canId, String ownerUserId, String trashType, Location &location, double maxWeight);

    String getCanId();
    void addSensor(CanSensor&);

    void generateJsonString();
    boolean isFull();
};
#endif