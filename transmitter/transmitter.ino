//This code was written using the functions of the Virtual Wire Library.
//Function list here: http://www.airspayce.com/mikem/arduino/VirtualWire/VirtualWire_8h.html

// Code is designed for the circuit built in this tutorial: https://www.youtube.com/watch?v=gkc9xN9pZ4Y
// Written by Sanjin Dedic as a part of Robotix Arduino Tutorial Course
// http://robotix.com.au/tutorials.html


#include <VirtualWire.h>
const char *message = "Merry Christmas";
int button = 2;


void setup() {
  pinMode(button,INPUT);
  
  Serial.begin(9600);
  vw_set_ptt_inverted(true); // On a communication line means that each 
  // party is either transmitting or receiving ( like a walkie talkie)
  vw_set_tx_pin(12); // set transmitter pin
  vw_setup(4000);// speed of data transfer Kbps
}

void loop(){
  
  if (digitalRead(button) == HIGH){  
    message="X";
    Serial.println("X");
    vw_send((uint8_t *)message, strlen(message)); // send the message
    vw_wait_tx(); // Wait until the whole message is gone
  } else{
    message="A";
    Serial.println("X");
    vw_send((uint8_t *)message, strlen(message)); // send the message
    vw_wait_tx(); // Wait until the whole message is gone
  }
}
