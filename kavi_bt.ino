#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;
bool o1 = false;
bool o2 = false;
bool o3 = false;
bool o4 = false;
#define m1 16//
#define m2 17//
#define m3 18//
#define m4 19//




void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32"); // Bluetooth device name
  Serial.println("Bluetooth Device is Ready to Pair");
pinMode(m1,OUTPUT);
pinMode(m2,OUTPUT);
pinMode(m3,OUTPUT);
pinMode(m4,OUTPUT);

}

void loop() {
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  if (Serial.available()) {
SerialBT.write(Serial.read());
   if((Serial.read()==1)&&(o1==false))
    {
      digitalWrite(m1,HIGH);
     o1=true;
     delay(1000);
    }
    else if((Serial.read()==2)&&(o2==false)){
     digitalWrite(m2,HIGH);
    o2=true;
    delay(1000);
    }
    else if((Serial.read()==3)&&(o3==false)){
    digitalWrite(m3,HIGH);
    o3=true;
    delay(1000);
    }
    else if((Serial.read()==4)&&(o4==false)){
      digitalWrite(m4,HIGH);
    o4=true;
    delay(1000);
    }
    else if((Serial.read()==1)&&(o1==true)){
    digitalWrite(m1,LOW);
    o1=false;
    delay(1000);
    }
    else if((Serial.read()==2)&&(o2==true)){
    digitalWrite(m2,LOW);
    o2=false;
    delay(1000);
    }
    else if((Serial.read()==3)&&(o3==true)){
    digitalWrite(m3,LOW);
    o3=false;
    delay(1000);
    }
    else if((Serial.read()==4)&&(o4==true)){
    digitalWrite(m4,LOW);
    o4=false;
    delay(1000);
    }

  }
 
}
