#include "Steper.h"
#include <SoftwareSerial.h>


MStep motor(4, 5, 6, 7);
SoftwareSerial mySerial(10, 11);

void setup(){
  Serial.begin(115200);
  mySerial.begin(115200);
}

void loop(){
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
}

