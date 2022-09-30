// I, Caleb Priede, 000803812 certify that this material is my original work.
// No other person's work has been used without due acknowledgement.
#include <Arduino.h>

// the state (val) of the persistant button
int buttonVal;
// store the state of the LED globally (default to OFF by setting to HIGH)
int lightState = HIGH;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // configure pin D4 as a digital output - this is the LED
  pinMode(D4, OUTPUT);

  // configure pin D5 as digital input - this is the pushbutton
  pinMode(D5, INPUT_PULLUP);

  // set default PWM range
  analogWriteRange(1023);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the value from the variable resister
  int iVal = analogRead(A0);

  // read the state of the push button (0/1 ON/OFF)
  int iButton = digitalRead(D5);

  // check if the current button state is different from the one stored
  if(iButton != buttonVal){
    // update the button state
    buttonVal = iButton;

    // check if the button has been pressed
    if(buttonVal == HIGH){
      // if button pressed the flip the state of the light switch (toggle on or off)
      lightState = !lightState;
    }
  }

  // check if light should currently be on
  if(lightState){
    // if light should be on then write resister value to LED
    analogWrite(D4, iVal);
  } else {
    // when light should be off set LED val to max (OFF)
    digitalWrite(D4, HIGH);
  }

  delay(1);
}