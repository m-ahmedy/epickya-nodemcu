#include "Location.h"

Location::Location()
{
    _longitude = 0;
    _latitude = 0;
    _accuracy = 0;
}

Location::~Location() {}

Location::Location(double longitude, double latitude, double accuracy)
{
    _longitude = longitude;
    _latitude = latitude;
    _accuracy = accuracy;
    generateJsonString();
}

void Location::generateJsonString()
{
    FirebaseJson json;
    json.set("latitude", _latitude);
    json.set("longitude", _longitude);
    json.set("accuracy", _accuracy);

    String stringBuffer;
    json.toString(stringBuffer);
    _jsonString = (std::string)(stringBuffer.c_str());

    json.clear();
}