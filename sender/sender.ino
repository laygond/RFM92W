////=======================================
//// SEND MESSAGE VERSION 1 (Set to 10 characters max)
// Send via LoRa ONN and OFF every 10 seconds
//#include "rfm92w.h"
//
//char msg[11];
//char OFF[] = "OFF"; // 3 chars is less than 10, anything above is cut
//char ONN[] = "ONN"; // 3 chars is less than 10, anything above is cut
//
//void setup() {                
//  beginLoraTX();      //It also starts SPI and Serial(9600)
//}
//
//void loop() {
//  char tmp[] = {0,0,0,0,0,0,0,0,0,0};// max length 10
//
//  //Send OFF
//  for(byte i = 0;i<3;i++){
//    tmp[i] = OFF[i]; 
//  }
//  sendData(tmp);
//  delay(10000);
//
//  //Send ONN
//  for(byte i = 0;i<3;i++){
//    tmp[i] = ONN[i]; 
//  }
//  sendData(tmp);
//  delay(10000);
//}


//=======================================
// SEND MESSAGE VERSION 2 (Set to 10 characters max)
// Send via LoRa info received from Serial; either ONN or OFF 
#include "rfm92w.h"

char msg[11];         // Predefined message to send via LoRa
char OFF[] = "OFF";   // 3 chars is less than 10, anything above is cut
char ONN[] = "ONN"; 
String content = "";  // Placeholder for info received from Serial
char character;       // where content is a concatenation of characters

void setup() {                
  beginLoraTX();      //It also starts SPI and Serial(9600)
} 

void loop() {
  // Read char into string:
  while (Serial.available()>0) {
    character = Serial.read();
    content += character;
  }
  // Once fully read, send via LoRa
  if (content != "") {
    if(content == "1"){
      char tmp[] = {0,0,0,0,0,0,0,0,0,0};// max length 10
      for(byte i = 0;i<3;i++){
        tmp[i] = ONN[i]; 
      }
      sendData(tmp);
      delay(100);
    }
    else if (content == "0"){
      char tmp[] = {0,0,0,0,0,0,0,0,0,0};// max length 10
      for(byte i = 0;i<3;i++){
        tmp[i] = OFF[i]; 
      }
      sendData(tmp);
      delay(100);
    }
    //Reset content
    content = "";
  }  
}
