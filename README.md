# arduino_fire_LED
Simple library for simulating firelight with an RGB LED

<i>This is my first contribution to GitHub, so be nice!  I've been playing around with code for years, but never really being serious about it until recently.  Anyhow, here's a simple library for Arduino to simulate firelight with an RGB LED.  There are more overkill ways of doing this (for example, a couple of 555 timers with some caps, but less random) but I needed a small package and something quick to deploy.

It was created for a project my 7-year-old has for school.  She's creating a Native American tepee and we decided to jazz it up with a simulated campfire.

Here are the comments from the header file and the single method in the class:

(From header)</i>

    /*
    Marty, 2019.

    Requires two PWM pins in order to work (uses the green and red portions
    of an RGB led).  Somewhat simulates firelight for use in projects.

    Create an object from the Fire_LED class; example:

        #include <Arduino.h>
        #include <Fire_LED.h>

        #define RED_LED     X  //  Where X is the red pin number (must be PWM)
        #define GREEN_LED   Y  //  Where Y is the green pin number (must be PWM)

        Fire_LED fire(RED_LED, GREEN_LED);  //  Keep reading comments; there's a third parameter!

        void setup() {

        }

        void loop() {
            fire.igniteFire();
        }


    The class only has one method, igniteFire(), which takes no arugments
    and doesn't return a value.  Creating the class object will initialize
    the pins automatically and the method will perform the correct actions.

    !!! IMPORTANT NOTE !!!
    The class object can take a third argument after the LED pins.  The parameter
    "common_cathode" is a boolean that defaults to true, but can be set to false
    if the LED is a common annode (where it requires a LOW to be full on).
    */


<i>(from method)</i>

    /*
    Function to light the fire!  "Simulates" firelight by using PWM on two
    portions of an RGB LED.  It supplies higher frequency pulses to the
    red LED and lower frequency pulses to the green LED.  This gives hues of
    reds, oranges, and yellows, much like a fire.
    */
