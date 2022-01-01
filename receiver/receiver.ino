//=======================================
// RECEIVE MESSAGE
#include "rfm92w.h"

char msg[11];
char payload[] = "OFF";

void setup() {                
  beginLoraRX();
}

// the loop routine runs over and over again forever:
void loop() {
  if(digitalRead(dio0) == 1)
  {
     receiveMessage(msg);
     Serial.print(msg);
     Serial.println("\n");
  }
   
}
