/*
*         Title : Timer
*        Author : Anders S. Kortegaard
*          Date : 17/01 - 2016
*
*   Description : Blinking
*
*           MCU : ATmega16/32
*           ref : datasheet s. 113
*/

#include <avr/io.h>
#include <util/delay.h>

int counter = 0;

int main(){
  DDRD = 0xFF;
  PORTD = 0x00;

  //TTCR1B, setting prescaler
  TCCR1B = 1 << CS10;

  while (1) {
    if(TCNT1 > 100000){
      //TCNT1 is the timer count
      TCNT1 = 0;
      PORTD ^= 0xFF;
    }
  }
}
