//This code was written using the functions of the Virtual Wire Library.
//Function list here: http://www.airspayce.com/mikem/arduino/VirtualWire/VirtualWire_8h.html

// Code is designed for the circuit built in this tutorial: https://www.youtube.com/watch?v=gkc9xN9pZ4Y
// Written by Sanjin Dedic as a part of Robotix Arduino Tutorial Course
// http://robotix.com.au/tutorials.html


#include <VirtualWire.h>
String message = "";
int potentiometerPin = A0;

int potentiometerState;
unsigned int len;
char buf[VW_MAX_MESSAGE_LEN];
void setup() {
  pinMode(potentiometerPin,INPUT);
  
  Serial.begin(9600);
  vw_set_ptt_inverted(true); // On a communication line means that each 
  // party is either transmitting or receiving ( like a walkie talkie)
  vw_set_tx_pin(12); // set transmitter pin
  vw_setup(4000);// speed of data transfer Kbps
}

void loop(){
  potentiometerState = analogRead(potentiometerPin);
    potentiometerState = map(potentiometerState, 0, 1023, 0 ,255);
    message="A" + (String)potentiometerState;
    
    message.toCharArray(buf, 5);
    Serial.println(buf);
    vw_send((uint8_t *)buf, 5); // send the message
    vw_wait_tx(); // Wait until the whole message is gone
}
