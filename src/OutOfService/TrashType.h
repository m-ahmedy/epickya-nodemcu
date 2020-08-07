#ifndef TRASH_TYPE_H
#define TRASH_TYPE_H

#include "Arduino.h"

enum TrashTypeEnum
{
    plastic,
    metal,
    organic,
    paper,
    glass,
    mixed,
    other,
    NONE
};

class TrashType
{
private:
    String _type;
    void enumTypeToString(TrashTypeEnum type);

public:
    TrashType();
    ~TrashType();
    
    TrashType(TrashTypeEnum type);
    String toString();
};

#endif