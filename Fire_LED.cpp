#include "Arduino.h"
#include "Fire_LED.h"

Fire_LED::Fire_LED(int red_led, int green_led, bool common_cathode = true) {
    pinMode(red_led,OUTPUT);
    pinMode(green_led,OUTPUT);
    if (common_cathode == true) {  //  Common cathode handler
        analogWrite(red_led,0);
        analogWrite(green_led,0);
    } else {  //  Common annode handler
        analogWrite(red_led,255);
        analogWrite(green_led,255);
    }

    _red_led = red_led;
    _green_led = green_led;
    _common_cathode = common_cathode;
}

void Fire_LED::igniteFire(void) {
    /*
    Function to light the fire!  "Simulates" firelight by using PWM on two
    portions of an RGB LED.  It supplies higher frequency pulses to the
    red LED and lower frequency pulses to the green LED.  This gives hues of
    reds, oranges, and yellows, much like a fire.
    */
    char random_red;
    char random_green;
    int random_delay = int(random(20,100));  //  Random values can be changed if desired
    if (_common_cathode == true) {  //  Common cathode handler
        random_red = char(random(127,255));  //  Random values can be changed if desired
        random_green = char(random(33,100));  //  Random values can be changed if desired
    } else {  //  Common annode handler
        random_red = ~char(random(127,255));  //  Random values can be changed if desired
        random_green = ~char(random(33,100));  //  Random values can be changed if desired
    }
    analogWrite(_red_led,random_red);
    analogWrite(_green_led,random_green);
    delay(random_delay);
}