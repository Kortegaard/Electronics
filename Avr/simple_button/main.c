
#include <avr/io.h>
#include <util/delay.h>
#include "../lib/button.h"

int main() {
  //Setting all as output, buton PD0 as input
  DDRD = 0xFE;
  //Setting PD0 high, as pull-up
  PORTD = 0x01;

  //looping
  while(1){
    //Check if button is pressed
    if (is_pressed(0,PIND)) {
      //setting all pins high
      PORTD |= 0xFF;
    }else{
      //Setting all pins low, but the button pin
      PORTD &= 0x01;
    }
  }
  return 0;
}
