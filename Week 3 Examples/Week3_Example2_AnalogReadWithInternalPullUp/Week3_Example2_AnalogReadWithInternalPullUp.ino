/*
  Analog input, serial output

  Reads two analog input pins, using internal pull up resistor, prints the results to the Serial Monitor.

  The circuit:
  - DIY velostat force sensor connected to analog pin 9 and ground
    FSR connected to analog pin 7 and ground

  created 29 Dec. 2008
  modified 9 Apr 2012
  by Tom Igoe

  modified 10 Feb 2019
  by Jingwen

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInOutSerial
*/

// These constants won't change. They're used to give names to the pins used:
const int velostatInPin = A9;  // Analog input pin that the velostat DIY FSR is attached to
const int fsrInPin = A7; //Analog input pin that the FSR is attached to

int velostatSensorValue = 0;        // value read from the velostat fsr
int fsrSensorValue = 0;        // value read from the fsr

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(velostatInPin, INPUT_PULLUP);
  pinMode(fsrInPin, INPUT_PULLUP);
}

void loop() {
  // read the analog in value:
  velostatSensorValue = analogRead(velostatInPin);
  fsrSensorValue = analogRead(fsrInPin);
 
  // print the results to the Serial Monitor:
  Serial.print("velostat: ");
  Serial.print(velostatSensorValue);
  Serial.print(" fsr: ");
  Serial.println(fsrSensorValue);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}
