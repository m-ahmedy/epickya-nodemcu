#ifndef JSON_SERIALIZER_H
#define JSON_SERIALIZER_H

#include "Arduino.h"

class JSONSerializer
{
protected:
    // String _jsonString;
    std::string _jsonString;
    void generateJsonString();

public:
    JSONSerializer();
    ~JSONSerializer();

    std::string getJsonString();
};

#endif
