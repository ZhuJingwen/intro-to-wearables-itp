/*
  Button LED

  This example creates a BLE peripheral with service that contains a
  characteristic to represents the state of the button.

  The circuit:
  - Arduino MKR WiFi 1010 or Arduino Uno WiFi Rev2 board
  - Button connected to pin 4

  This example code is in the public domain.
*/

#include <ArduinoBLE.h>

const int buttonPin = 4; // set buttonPin to digital pin 4

BLEService buttonService("19B10010-E8F2-537E-4F6C-D104768A1214"); // create service

// create button characteristic and allow remote device to read and write
BLEBoolCharacteristic buttonCharacteristic("19B10012-E8F2-537E-4F6C-D104768A1214", BLERead | BLENotify);

void setup() {
  Serial.begin(9600);
  while (!Serial);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin, INPUT); // use button pin as an input

  // begin initialization
  if (!BLE.begin()) {
    Serial.println("starting BLE failed!");

    while (1);
  }

  // set the local name peripheral advertises
  BLE.setLocalName("Button");

  // set the UUID for the service this peripheral advertises:
  BLE.setAdvertisedService(buttonService);

  // add the characteristics to the service
  buttonService.addCharacteristic(buttonCharacteristic);

  // add the service
  BLE.addService(buttonService);

  //set init value
  buttonCharacteristic.writeValue(0);

  // start advertising
  BLE.advertise();

  Serial.println("Bluetooth device active, waiting for connections...");
}

void loop() {
  // poll for BLE events
  BLE.poll();

  bool buttonValue = digitalRead(buttonPin);
  if (buttonValue) {
    digitalWrite(LED_BUILTIN, HIGH);
  }else{
    digitalWrite(LED_BUILTIN, LOW);
  }
  buttonCharacteristic.writeValue(buttonValue);

}
