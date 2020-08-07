#include "TrashType.h"

TrashType::TrashType()
{
  _type = "NONE";
}

TrashType::~TrashType() {}

TrashType::TrashType(TrashTypeEnum type)
{
  enumTypeToString(type);
}

String TrashType::toString()
{
  return _type;
}

void TrashType::enumTypeToString(TrashTypeEnum typeInEnumFormat)
{
  switch (typeInEnumFormat)
  {
  case plastic:
    _type = "plastic";
    break;
  case metal:
    _type = "metal";
    break;
  case organic:
    _type = "organic";
    break;
  case paper:
    _type = "paper";
    break;
  case glass:
    _type = "glass";
    break;
  case mixed:
    _type = "mixed";
    break;
  case other:
    _type = "other";
    break;
  case NONE:
    _type = "NONE";
    break;
  default:
    _type = "NONE";
  }
}
