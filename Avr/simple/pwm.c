/*
*         Title : PWM
*        Author : Anders S. Kortegaard
*          Date : 18/01 - 2016
*
*   Description : PWM
*       Credits : http://www.avrfreaks.net/forum/tut-c-newbies-guide-avr-pwm-incomplete?page=all
*                 http://extremeelectronics.co.in/avr-tutorials/pwm-signal-generation-by-using-avr-timers-part-ii/
*/


#include <avr/io.h>
#include <util/delay.h>
#include "../lib/pwm_ocr.h"

int i = 0;

void main()
{
   uint8_t brightness=0;

   //Initialize PWM
   pwm_init();

   while(1){
     for(i = 0 ; i < 255; i++){
       //Setting pwm value
       pwm_set(i);
       pwm_wait();
     }
     for(i = 255 ; i > 0; i--){
       pwm_set(i);
       pwm_wait();
     }
   }
}
