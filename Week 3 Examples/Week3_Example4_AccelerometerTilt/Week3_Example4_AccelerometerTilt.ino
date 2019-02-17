/*
  Circuit Playground accelerometer example
  
  Reads x, y z axis acceleration, maps the result to a range from 0 to 255 and uses
  the result to set on-board NeoPixel.
  Also prints the results to the Serial Monitor.

  The circuit:
  Circuit Playground Classic

  created 10 Feb 2019
  by Jingwen
*/

#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin();
}

void loop() {
  int x = CircuitPlayground.motionX();
  int y = CircuitPlayground.motionY();
  int z = CircuitPlayground.motionZ();

  int red = map(x, -10, 10, 0, 200);
  int green = map(y, -10, 10, 0, 200);
  int blue = map(z, -10, 10, 0, 200);

  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, red, green, blue);
  }


}
