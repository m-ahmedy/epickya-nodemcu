#ifndef CAN_FIREBASE_ENTRY_H
#define CAN_FIREBASE_ENTRY_H

#include "Arduino.h"
#include "TrashCan.h"
#include "FirebaseESP8266.h"
#include "firebaseResponseHandlers.h"

#define BASE_DATABASE_PATH "TrashCans"

class CanFirebaseEntry
{
private:
    TrashCan* _canRef;
    FirebaseData *_firebaseDataRef;

    static const String registeredEntriesPath;
    static const String registerNewEntryPath;
    static const String pickUpOrdersPath;

public:
    CanFirebaseEntry();
    ~CanFirebaseEntry();

    CanFirebaseEntry(TrashCan &can, FirebaseData &firebaseData);

    boolean checkIfRegisteredAlready();

    boolean registerEntry();

    boolean placePickupOrder();

    // boolean updateOnlineStatus(unsigned long);
};

#endif