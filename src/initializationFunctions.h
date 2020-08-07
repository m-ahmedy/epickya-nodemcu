#ifndef INITIALIZATION_FUNCTIONS_H
#define INITIALIZATION_FUNCTIONS_H

#include "FirebaseESP8266.h"

void initializeSerialCommunication(int baudRate);
void connectToWiFi(const char *ssid, const char *password);
void connectToFirebaseDatabase(const char *host, const char *databaseSecret);
void setFirebaseConnectionParameters(FirebaseData &firebaseData, int SSLBufferSize, int responseSize, int timeoutInSeconds, const char *writeSizeLimit);

#endif
