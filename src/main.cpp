#include "Arduino.h"
#include "FirebaseESP8266.h"
#include "arduino-timer.h"
#include "Ultrasonic.h"

#include "initializationFunctions.h"
#include "CanFirebaseEntry.h"

#define FIREBASE_HOST "epickya.firebaseio.com/"
#define FIREBASE_AUTH "4zEUWXGBVviwYzXzTFpphyTAxy1JITy1hg4XSyqb"

#define WIFI_SSID "WE560061"
#define WIFI_PASSWORD "l2034330"

#define CAN_ID "vFrN5ybyDmrgod7oJwgL"
#define LOCATION_LATITUDE 0.15478
#define LOCATION_LONGITUDE 0.15478
#define LOCATION_ACCURACY NULL
#define MAX_WEIGHT 20.0
#define TRASH_TYPE "plastic"
#define OWNER_USER_ID "testUserId"

#define ULTRASONIC_TRIG_PIN 16
#define ULTRASONIC_ECHO_PIN 5

#define INTERVAL_IN_SECONDS 3

class UltrasonicSensor : public CanSensor
{
private:
  Ultrasonic *_sensorRef;
  unsigned int _threshold;

public:
  UltrasonicSensor() {}
  UltrasonicSensor(Ultrasonic &sensor, unsigned int threshold)
  {
    _sensorRef = &sensor;
    _threshold = threshold;
  }
  
  boolean isFull()
  {
    Serial.println("UltrasonicSensor.isFull(); invocation");
    Serial.print("Threshold: ");
    Serial.println(_threshold, DEC);
    getRead();
    Serial.print("Condition: ");
    Serial.println(_sensorRef->read(CM) < _threshold);

    return _sensorRef->read(CM) < _threshold;
  }

  void getRead() 
  {
    Serial.println();
    Serial.print("Reading: ");
    Serial.println(_sensorRef->read(CM), DEC);
  }
};


FirebaseData firebaseData;

Location location;
TrashCan can;
CanFirebaseEntry entry;
Ultrasonic sensor(ULTRASONIC_TRIG_PIN, ULTRASONIC_ECHO_PIN);

UltrasonicSensor canSensor1;

Timer<1, millis> canTimer;


void setup()
{
  initializeSerialCommunication(115200);
  connectToWiFi(WIFI_SSID, WIFI_PASSWORD);
  connectToFirebaseDatabase(FIREBASE_HOST, FIREBASE_AUTH);
  setFirebaseConnectionParameters(firebaseData, 1024, 1024, 60, "tiny");

  delay(2000);

  location = Location(LOCATION_LONGITUDE, LOCATION_LATITUDE);
  Serial.println("Created location object");
  delay(500);
  can = TrashCan(CAN_ID, OWNER_USER_ID, TRASH_TYPE, location, MAX_WEIGHT);
  Serial.println("Created can object");
  delay(500);
  canSensor1 = UltrasonicSensor(sensor, 5);
  can.addSensor(canSensor1);
  Serial.println("Appended sensors to the can");
  delay(500);

  entry = CanFirebaseEntry(can, firebaseData);
  Serial.println("Created entry");
  delay(500);

  Serial.println("Registering can with ID: " + can.getCanId());
  while (!entry.checkIfRegisteredAlready())
  {
    entry.registerEntry();
    delay(2000);
  }
  Serial.println("Can registered successfully.");

  canTimer.every(INTERVAL_IN_SECONDS * 1000, [](void *opaque) {
    Serial.print("Checking can status: ");
    boolean isFull = can.isFull();
    Serial.println(isFull ? "Can is full" : "Can is not full");

    if (isFull)
    {
      entry.placePickupOrder();
    }
    return true;
  });
}

void loop()
{
  // client.update();
  canTimer.tick();
}