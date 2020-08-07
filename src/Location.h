#ifndef LOCATION_H
#define LOCATION

#include "FirebaseESP8266.h"
#include "JsonSerializer.h"

class Location : public JSONSerializer
{
private:
    double _longitude;
    double _latitude;
    double _accuracy;

public:
    Location();
    ~Location();

    Location(double longitude, double latitude, double accuracy = 0);

    void generateJsonString();
};

#endif