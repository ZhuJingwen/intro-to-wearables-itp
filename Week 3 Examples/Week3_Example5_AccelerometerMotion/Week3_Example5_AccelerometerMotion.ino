/*
  Circuit Playground accelerometer example
  
  Reads x, y z axis acceleration, calculates the total absolute movements and use 
  the result to set on-board NeoPixel.
  Also prints the results to the Serial Monitor.

  The circuit:
  Circuit Playground Classic

  created 10 Feb 2019
  by Jingwen
*/

#include <Adafruit_CircuitPlayground.h>

int prevX, prevY, prevZ;

void setup() {
  CircuitPlayground.begin();
}

void loop() {
  int x = CircuitPlayground.motionX();
  int y = CircuitPlayground.motionY();
  int z = CircuitPlayground.motionZ();

  int accel = abs(x - prevX) + abs(y - prevY) + abs(z - prevZ);
  Serial.println(accel);
  int movement = map(accel, 0, 20, 0, 255);
  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, 0, movement, movement);
  }
  prevX = x;
  prevY = y;
  prevZ = z;

}
