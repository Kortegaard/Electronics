/*
*         Title : ADC - light sensor
*        Author : Anders S. Kortegaard
*          Date : 17/01 - 2016
*
*   Description : Reading analog value, using adc
*/

#include <avr/io.h>
#include <util/delay.h>
#include "../lib/adc.h"   //importing adc lib

int main(){
  //initializing adc
  adc_init();
  //Setting input outputs (input on pin 0, light sensor)
  DDRA = 0xFE;
  while(1)
    {
      //Checkking adc/light value, and set pin high if value is over 400
      if (adc_read(0) > 400) {
        PORTA |= 1<<PA7;
      }else{ // if not setting pin low
        PORTA &= 0<<PA7;
      }
      _delay_ms(50);
    }
  return 0;
}
