/*
 * Blinking LED
 * Turns on an LED for two seconds to a brightness of 10, 
 * then to a brightness of 150 for three seconds, 
 * and finally to a brightness of 255 (the max) for one second, repeatedly.
 */
int ledPin = 9;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize ledPin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // this is the main code which runs repeatedly
  // the loop function runs over and over again forever
  analogWrite(ledPin, 10);  // turn the LED on
  delay(2000);                 // wait for two seconds
  analogWrite(ledPin, 150); // increase the brightness to 150
  delay(3000);                 // wait for three seconds
  analogWrite(ledPin, 255); // increase the brightness again to 255
  delay(1000);                 // wait for one second
}
