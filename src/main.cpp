#include <Arduino.h>
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup(){
  Serial.begin(115200);

  SerialBT.begin("SO101_Follower_BT");

  Serial.println("ESP32 ready. Search for 'SO101_Follower_BT' on your laptop. rahhhhhh skibidi toilet");
}

  void loop(){
    //echo the data received from USb Serial out to Bluetooth
    if(Serial.available()){
      SerialBT.write(Serial.read());
    }

    //echo the data received over Bluetooth out to USB Serial yada yada yada.
    if(SerialBT.available()){
      Serial.write(SerialBT.read());
    }
    delay(10);
  }