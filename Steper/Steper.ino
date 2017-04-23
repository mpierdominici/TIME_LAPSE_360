#include "Steperlib.h"
#include <SoftwareSerial.h>


MStep motor(4, 5, 6, 7);
SoftwareSerial mySerial(10, 11);

bool horario = true;
int num = 0;
int tiempo = 0;

void setup(){
  Serial.begin(115200);
  mySerial.begin(115200);
  pinMode(13, OUTPUT);
}

void loop(){
  Serial.println(horario);
  Serial.println(num);
  Serial.println(tiempo);
  while(!mySerial.available());
  obtenerValor();
}

void obtenerValor(){
  if(mySerial.available()){
    char a = mySerial.read();
    if(a == 'h'){
      horario = true;
      tiempo = 0;
      char b = '0';
      while(mySerial.available() && b != 't'){
        tiempo = tiempo * 10 + (b - 48);
        b = mySerial.read();
      }
    }else if(a == 'a'){
      horario = false;
      tiempo = 0;
      char b = '0';
      while(mySerial.available() && b != 't'){
        tiempo = tiempo * 10 + (b - 48);
        b = mySerial.read();
      }
    }
    num = 0;
    while(mySerial.available()){
      char b = mySerial.read();
      num = num * 10 + (b - 48);
    }
  }
}

