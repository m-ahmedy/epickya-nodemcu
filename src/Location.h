#ifndef LOCATION_H
#define LOCATION

#include "FirebaseESP8266.h"
#include "JsonSerializer.h"

class Location : public JSONSerializer
{
private:
    double _longitude;
    double _latitude;

public:
    Location();
    ~Location();

    Location(double longitude, double latitude);

    void generateJsonString();
};

#endif