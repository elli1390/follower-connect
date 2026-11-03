#include <Arduino.h>
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;


//array that stores all of the target positions for all 6 joints
int* targetJoints = new int[6];

void setup(){
  Serial.begin(115200);

  SerialBT.begin("SO101_Follower_BT");

  Serial.println("ESP32 ready. Search for 'SO101_Follower_BT' on your laptop.");
  Serial.println("Joint shit pass me that shit cuh CAW."); 
}

  void loop(){

    //first checks to see if the Bluetooth connection between the ESP32 and the laptop is present.
    if(SerialBT.available()){ 
      String incomingData = SerialBT.readStringUntil('\n');
    }

    //echo the data received from USb Serial out to Bluetooth
    if(Serial.available()){
      SerialBT.write(Serial.read());
    }

    //echo the data received over Bluetooth out to USB Serial yada yada yada.
    if(SerialBT.available()){
      Serial.write(SerialBT.read());
    }
    delay(10); //the amount of milliseconds you have to wait. delay good
  }