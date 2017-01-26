//This code was written using the functions of the Virtual Wire Library.
//Function list here: http://www.airspayce.com/mikem/arduino/VirtualWire/VirtualWire_8h.html

// Code is designed for the circuit built in this tutorial: https://www.youtube.com/watch?v=gkc9xN9pZ4Y
// Written by Sanjin Dedic as a part of Robotix Arduino Tutorial Course
// http://robotix.com.au/tutorials.html


#include <VirtualWire.h>    

void setup()
{
  Serial.begin(9600);
  vw_set_ptt_inverted(true); // On a communication line means that each 
// party is either transmitting or receiving ( like a walkie talkie)
  vw_set_rx_pin(12); // set receiver pin
  vw_setup(4000);  // Bits per sec
  vw_rx_start();       // Start Phase Locked Loop (listening to the receiver)
}
    void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN]; // 80 bytes is messgage length
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) { // if message received
    if(buf[0]=='X'){  // and if the first letter in message array is X 
      Serial.println("PLEASE"); 
     }  
  else if(buf[0]!='X'){
      Serial.println("NO GO");
    }

  } 
}
 
