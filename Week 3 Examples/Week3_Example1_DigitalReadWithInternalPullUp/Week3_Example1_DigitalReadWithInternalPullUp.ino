/*
  Control Flora on-board LEDs using two digital inputs with internal pull-up resistor

  Reads a digital input on pin 6 and pin 9, prints the results to the Serial Monitor, and use the results to control onboard LED #7 
  
  This example code is based on DigitalReadSerial example in the public domain.

  http://www.arduino.cc/en/Tutorial/DigitalReadSerial

  Jingwen Zhu
  2019/2
*/

// digital pin 9 has a soft switch attached to it.
int softSwitchPin = 9;

// digital pin 6 has a sewable switch attached to it.
int sewableSwitchPin = 6;

//Flora has an on-board LED on digital pin 7
int onBoardLEDPin = 7;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // make the switch's pin an input with internal pull-up resistor:
  pinMode(softSwitchPin, INPUT_PULLUP);
  pinMode(sewableSwitchPin, INPUT_PULLUP);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the soft switch pin:
  int softSwitchState = digitalRead(softSwitchPin);
  // print out the state of the the soft switch:
  Serial.print("soft switch: ");
  Serial.print(softSwitchState);
  Serial.print(" ");

  if (softSwitchState == 0) {
    //switch on, turn on on-board LED
    digitalWrite(onBoardLEDPin, HIGH);
  } else {
    digitalWrite(onBoardLEDPin, LOW);
  }

  int sewableSwitchState = digitalRead(sewableSwitchPin);
  Serial.print("sewable switch: ");
  Serial.println(sewableSwitchState);

  delay(1);        // delay in between reads for stability
}
