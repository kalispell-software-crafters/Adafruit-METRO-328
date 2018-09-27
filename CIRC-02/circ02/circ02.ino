    /*     
     *      This code was inspired by and adapted from the following Adafruit Experiment:
     *      
     *      ---------------------------------------------------------
     *     |  Arduino Experimentation Kit Example Code             |
     *     |  CIRC-02 .: 8 LED Fun :. (Multiple LEDs)              |
     *     ---------------------------------------------------------
     *     
     *     More information: https://learn.adafruit.com/experimenters-guide-for-metro/circ02-intro
     *     
     *     There are two methods which operate 8 LEDs and count in binary from 1 to 256 by blinking their values.
     *     We wrote these for fun after learning a bit more about Raspberry Pis, Arduinos, and similar boards.
     */
     
     #include <math.h>
     
    //LED Pin Variables
    int ledPins[] = {2,3,4,5,6,7,8,9}; //An array to hold the pin each LED is connected to
                                       //i.e. LED #0 is connected to pin 2, LED #1, 3 and so on
                                       //to address an array use ledPins[0] this would equal 2
                                       //and ledPins[7] would equal 9
     
    /*
     * setup() - this function runs once when you turn your Arduino on
     */
    void setup()
    {
      //Set each pin connected to an LED to output mode (pulling high (on) or low (off))
      for(int i = 0; i < 8; i++){         //this is a loop and will repeat eight times
          pinMode(ledPins[i],OUTPUT);     //we use this to set each LED pin to output
      }                                     
    }
     
     
    /*
     * loop() - this function will start after setup finishes and then repeat
     * we call a function called binaryBitLights(). if you would like a different behaviour
     * uncomment (delete the two slashes) one of the other lines
     */
    void loop()                     // run over and over again
    {
      //binaryLights();
      binaryBitLights();
    }

  /*
   * This method uses bit operations to calculate which LEDs to turn on and off to represent an integer in binary
   */
  void binaryBitLights() {
      // 2 ^ 8 = 256   
      // Given 8 LEDs we can count to 256 in binary!
      
      int delayTime = 100;
      int k = 0;
      
      for (int i = 0; i <= 255; i++) {
        for(int j = 0; j <= 7; j++) {
          //k = ((i & (1 << j)) >> j);

          digitalWrite(ledPins[j], ( (i >> j) & 1 ));
          
          /* This code is saved from an earlier version of this method
          if(1 == k) {
            digitalWrite(ledPins[j], HIGH);
          } else {
            digitalWrite(ledPins[j], LOW);
          }
          */
        }
       
        delay(delayTime);
      }
    }

/*
 * This method was the first route we went down in order to count in binary using the LEDs
 */
    void binaryLights() {
      int delayTime = 100;
      int k = 0;
      
      for (int i = 0; i <= 255; i++) {
        k = i;
        for(int j = 7; j >= 0; j--) {
          if((int)pow(2, j) < k) {
            digitalWrite(ledPins[j], HIGH);
            k -= (int)pow(2, j);
          } else {
            digitalWrite(ledPins[j], LOW);
          }
          
          /* This code is saved from an earlier version of this method
          if( i % (int)pow(2, j+1) == 0 ) {
            digitalWrite(ledPins[j], HIGH);
          } else {
            digitalWrite(ledPins[j], LOW);
          }  */
        }
       
        delay(delayTime);
      }
    }
}
