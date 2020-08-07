#include "firebaseResponseHandlers.h"

void handleSuccessfulResponse(FirebaseData &responseData)
{
  printMetadata(responseData);
  printResult(responseData);
  Serial.println("------------------------------------");
  Serial.println();
}

void handleFailedResponse(FirebaseData &responseData)
{
  Serial.println("FAILED");
  Serial.println("REASON: " + responseData.errorReason());
  Serial.println("------------------------------------");
  Serial.println();
}

boolean handleFirebaseResponse(boolean responseState, FirebaseData &responseData)
{
  if (responseState)
  {
    handleSuccessfulResponse(responseData);
    return true;
  }
  else
  {
    handleFailedResponse(responseData);
    return false;
  }
}
