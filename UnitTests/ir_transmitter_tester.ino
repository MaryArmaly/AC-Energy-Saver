/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremoteESP8266.h>
#include <IRsend.h>

const uint16_t kirled=16;
IRsend irsend(kirled);

void setup()
{
  irsend.begin();
  Serial.begin(9600);
  delay(3000); // 3 sec delay to let you set up direction of IR properly - reduce or increase as desired
  
}

void loop() {
  irsend.sendNEC(0xFFB04F);   //ON
  delay(2000);
  irsend.sendNEC(0xFF9867);   //RED
  delay(2000);
  irsend.sendNEC(0xFFD827);   //GREEN
  delay(2000);
  irsend.sendNEC(0xFF8877);   //BLUE
  delay(2000);
  irsend.sendNEC(0xFFF807);   //OFF
  delay(2000);
}