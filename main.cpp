#include <Arduino.h>
#include <Fire_LED.h>

#define RED_LED         9
#define GREEN_LED       5

Fire_LED fire(RED_LED,GREEN_LED,false);

void setup() {

}

void loop() {
  fire.igniteFire();
}