/*

Marty, 2019.

Requires two PWM pins in order to work (uses the green and red portions
of an RGB led).  Somewhat simulates firelight for use in projects.

Create an object from the Fire_LED class; example:

        #include <Arduino.h>
        #include <Fire_LED.h>

        #define RED_LED     X  //  Where X is the red pin number
        #define GREEN_LED   Y  //  Where Y is the green pin number

        Fire_LED fire(RED_LED, GREEN_LED);

        void setup() {

        }

        void loop() {
            fire.igniteFire();
        }


The class only has one method, igniteFire(), which takes no arugments
and doesn't return a value.  Creating the class object will initialize
the pins automatically and the method will perform the correct actions.

The class object can take a third argument after the LED pins.  The parameter
"common_cathode" is a boolean that defaults to true, but can be set to false
if the LED is a common annode (where it requires a LOW to be full on).

*/

#ifndef Fire_LED_h
#define Fire_LED_h

#include "Arduino.h"

class Fire_LED {
    public:
        //  Public
        Fire_LED(int red_led, int green_led, bool common_cathode = true);
        void igniteFire(void);
    private:
        //  Private
        int _red_led, _green_led;
        bool _common_cathode;
};


#endif