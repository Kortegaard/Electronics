/*
*         Title : PWM
*        Author : Anders S. Kortegaard
*          Date : 18/01 - 2016
*
*   Description : PWM
*       Credits : http://www.avrfreaks.net/forum/tut-c-newbies-guide-avr-pwm-incomplete?page=all
*                 http://extremeelectronics.co.in/avr-tutorials/pwm-signal-generation-by-using-avr-timers-part-ii/
*/

#ifndef __pwm_h__
  #define __pwm_h__
  void pwm_init()
  {
   //TCCR0 - Timer Counter Control Register (TIMER0)


   TCCR0|=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00);

   //Set OC0 PIN as output. It is  PB3 on ATmega16 ATmega32
   DDRB|=(1<<PB3);
  }


  void pwm_set(uint8_t duty)
  {
    OCR0=duty;
  }

  void pwm_wait()
  {
    _delay_loop_2(3200);
  }
#endif
