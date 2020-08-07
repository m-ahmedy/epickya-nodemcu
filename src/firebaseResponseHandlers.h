#ifndef FIREBASE_RESPONSE_HANDLERS_H
#define FIREBASE_RESPONSE_HANDLERS_H

#include "FirebaseESP8266.h"
#include "serialFunctions.h"

boolean handleFirebaseResponse(boolean, FirebaseData&);
void handleSuccessfulResponse(FirebaseData&);
void handleFailedResponse(FirebaseData&);

#endif
