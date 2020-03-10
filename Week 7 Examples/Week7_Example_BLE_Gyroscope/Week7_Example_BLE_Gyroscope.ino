/*
  Arduino LSM9DS1 - Simple Gyroscope

  This example reads the gyroscope values from the LSM9DS1
  sensor and continuously prints them to the Serial Monitor and BLE

  The circuit:
  - Arduino Nano 33 BLE Sense

  created 10 Jul 2019
  by Riccardo Rizzo

  edited 8 Mar 2020
  by Jingwen Zhu

  This example code is in the public domain.
*/

#include <ArduinoBLE.h>
#include <Arduino_LSM9DS1.h>

BLEService customService("19B10000-E8F2-537E-4F6C-D104768A1216");

BLEIntCharacteristic CharacteristicX("4227f3b1-d6a2-4fb2-a916-3bee580a9c84", BLERead | BLENotify);
BLEIntCharacteristic CharacteristicY("5b974f46-6f48-43ee-9a55-4fb009867603", BLERead | BLENotify);
BLEIntCharacteristic CharacteristicZ("09a64f10-32b3-497a-93c2-c914f46eba22", BLERead | BLENotify);


void setup() {
  Serial.begin(9600);
  //while (!Serial);
  Serial.println("Started");
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Acceleration in G's");
  Serial.println("X\tY\tZ");

  // begin initialization
  BLE.begin();

  // set advertised local name and service UUID:
  BLE.setLocalName("BLE");
  BLE.setAdvertisedService(customService);

  // add the characteristic to the service
  customService.addCharacteristic(CharacteristicX);
  customService.addCharacteristic(CharacteristicY);
  customService.addCharacteristic(CharacteristicZ);

  // add service
  BLE.addService(customService);

  // set the initial value for the characeristic:
  CharacteristicX.writeValue(0);
  CharacteristicY.writeValue(0);
  CharacteristicZ.writeValue(0);

  // start advertising
  BLE.advertise();

  Serial.println("BLE LED Peripheral");

}

void loop() {
  // poll for BLE events
  BLE.poll();

  float x, y, z;

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);

    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.println(z);

     CharacteristicX.writeValue(x*100);
    CharacteristicY.writeValue(y*100);
    CharacteristicZ.writeValue(z*100);
  }
  



}
