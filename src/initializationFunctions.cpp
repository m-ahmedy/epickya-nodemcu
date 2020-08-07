#include "initializationFunctions.h"

void initializeSerialCommunication(int baudRate)
{
    Serial.begin(baudRate);
}

void connectToWiFi(const char *ssid, const char *password)
{
    WiFi.begin(ssid, password);
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(300);
    }
    Serial.println();
    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();
}

void connectToFirebaseDatabase(const char *host, const char *databaseSecret)
{
    Firebase.begin(host, databaseSecret);
    Firebase.reconnectWiFi(true);
}

void setFirebaseConnectionParameters(FirebaseData &firebaseData, int BSSLBufferSize, int responseSize, int timeoutInSeconds, const char *writeSizeLimit)
{
    //Set the size of WiFi rx/tx buffers in the case where we want to work with large data.
    firebaseData.setBSSLBufferSize(BSSLBufferSize, BSSLBufferSize);

    //Set the size of HTTP response buffers in the case where we want to work with large data.
    firebaseData.setResponseSize(responseSize);

    //Set database read timeout to 1 minute (max 15 minutes)
    Firebase.setReadTimeout(firebaseData, 1000 * timeoutInSeconds);
    //tiny, small, medium, large and unlimited.
    //Size and its write timeout e.g. tiny (1s), small (10s), medium (30s) and large (60s).
    Firebase.setwriteSizeLimit(firebaseData, writeSizeLimit);

    /*
    This option allows get and delete functions (PUT and DELETE HTTP requests) works for device connected behind the
    Firewall that allows only GET and POST requests.

    Firebase.enableClassicRequest(firebaseData, true);
    */
}