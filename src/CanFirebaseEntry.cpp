#include "CanFirebaseEntry.h"

const String CanFirebaseEntry::registeredEntriesPath = String(BASE_DATABASE_PATH) + "/registeredEntries";
const String CanFirebaseEntry::pickUpOrdersPath = String(BASE_DATABASE_PATH) + "/pickUpOrders";
const String CanFirebaseEntry::registerNewEntryPath = String(BASE_DATABASE_PATH) + "/registerNewEntry";

CanFirebaseEntry::CanFirebaseEntry() {}
CanFirebaseEntry::~CanFirebaseEntry() {}

CanFirebaseEntry::CanFirebaseEntry(TrashCan &can, FirebaseData &firebaseData)
{
  _canRef = &can;
  _firebaseDataRef = &firebaseData;
}

boolean CanFirebaseEntry::checkIfRegisteredAlready()
{
  String queryPath = registeredEntriesPath + "/" + _canRef->getCanId() + "/registered";
  boolean queryResult = Firebase.getBool(*_firebaseDataRef, queryPath);
  handleFirebaseResponse(queryResult, *_firebaseDataRef);
  return (*_firebaseDataRef).dataAvailable();
}

boolean CanFirebaseEntry::registerEntry()
{
  // std::string jsonString = (std::string)(_canRef->getJsonString().c_str());
  std::string jsonString = _canRef->getJsonString();
  FirebaseJson json = FirebaseJson(jsonString);
  String queryPath = registerNewEntryPath + "/" + _canRef->getCanId();

  boolean queryResult = Firebase.setJSON(*_firebaseDataRef, queryPath, json);
  return handleFirebaseResponse(queryResult, *_firebaseDataRef);
}

boolean CanFirebaseEntry::placePickupOrder()
{
  String queryPath = pickUpOrdersPath + "/" + _canRef->getCanId();
  boolean queryResult = Firebase.setString(*_firebaseDataRef, queryPath, "full");
  return handleFirebaseResponse(queryResult, *_firebaseDataRef);
}
/* 
boolean CanFirebaseEntry::updateOnlineStatus(unsigned long currentTimestamp)
{
  FirebaseJson json;
  json.set("registered", true);
  json.set("online", true);
  json.set("lastUpdateTimestamp", (int)currentTimestamp);

  String queryPath = registeredEntriesPath + "/" + _canRef->getCanId();
  boolean queryResult = Firebase.setJSON(*_firebaseDataRef, queryPath, json);
  json.clear();

  return handleFirebaseResponse(queryResult, *_firebaseDataRef);
}
 */