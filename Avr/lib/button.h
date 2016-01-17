/*
*         Title : Check button pressed
*        Author : Anders S. Kortegaard
*          Date : 17/01 - 2016
*
*   Description : function for checking if button is pressed
*/

#ifndef __button_h__
  #define __button_h__

  /**
   *Check if button is pressed
   *
   *@var int - pin (0-7)
   *@var char - Button Pins (ex 'PIND')
   *@return char (if btn is pressed or not)
   */
  char is_pressed(int pin, char buttonPin){
      return ~buttonPin & (1 << pin);
  }

#endif
