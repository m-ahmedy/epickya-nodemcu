#include "Location.h"

Location::Location()
{
    _longitude = 0;
    _latitude = 0;
}

Location::~Location() {}

Location::Location(double longitude, double latitude)
{
    _longitude = longitude;
    _latitude = latitude;
    generateJsonString();
}

void Location::generateJsonString()
{
    FirebaseJson json;
    json.set("latitude", _latitude);
    json.set("longitude", _longitude);

    String stringBuffer;
    json.toString(stringBuffer);
    _jsonString = (std::string)(stringBuffer.c_str());

    json.clear();
}