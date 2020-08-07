#include "TrashCan.h"

TrashCan::TrashCan()
{
  _canId = "";
  _ownerUserId = "";
  _trashType = "NONE";
  _location = Location();
  _maxWeight = 0.0;
}

TrashCan::~TrashCan() {}

TrashCan::TrashCan(String canId, String ownerUserId, String trashType, Location &location, double maxWeight)
{
  _canId = canId;
  _ownerUserId = ownerUserId;
  _trashType = trashType;
  _location = location;
  _maxWeight = maxWeight;

  generateJsonString();
}

String TrashCan::getCanId()
{
  return _canId;
}

boolean TrashCan::isFull()
{
  // Serial.println("TrashCan.isFull() invocation start");
  for(CanSensor* it: _sensorRefs)
  {
    // Serial.println("TrashCan.isFull() invocation inside for loop");
    if (!(it->isFull()))
      return false;
  }
  return true;
}

void TrashCan::addSensor(CanSensor &sensor)
{
  // Serial.println("Sensors before: " + _sensorRefs.size());
  _sensorRefs.push_back(&sensor); 
  // Serial.println("Sensors after: " + _sensorRefs.size());
}

void TrashCan::generateJsonString()
{
  FirebaseJson json;
  json.set("canId", _canId);
  json.set("ownerUserId", _ownerUserId);
  json.set("trashType", _trashType);
  json.set("maxWeight", _maxWeight);

  // std::string locationString = (std::string)(_location.getJsonString().c_str());
  std::string locationString = _location.getJsonString();
  FirebaseJson subJson = FirebaseJson(locationString);
  json.set("location", subJson);

  String stringBuffer;
  json.toString(stringBuffer);
  _jsonString = (std::string)(stringBuffer.c_str());

  json.clear();
  subJson.clear();
}