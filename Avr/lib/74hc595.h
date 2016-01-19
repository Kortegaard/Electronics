/*
*         Title : 74HC595 Lib
*        Author : Anders S. Kortegaard
*          Date : 19/01 - 2016
*
*   Description : For controlling a shift register (74hc595) with the ATmega16/32
*
*       credits : https://www.youtube.com/watch?v=6fVbJbNPrEU
*     Datasheet : http://www.ti.com/lit/ds/symlink/sn74hc595.pdf
*
*   Daisy chain : TODO
*
*  How it works : TODO
*
*/


#ifndef __74hc595_h__
  #define __74hc595_h__

  //defining ports
  #define SR_DDR DDRB
  #define SR_PORT PORTB

  //defining pins
  #define SER_pin PB0     //Data in pin
  #define SRCLK_pin PB1   //Clock pin (storage register clock)
  #define RCLK_pin PB2    //Latch pin (shift register clock)
  #define CLEAR_pin PB3   //Clear pin (SRCLR)


  //Setting the necessary pins to output
  void 74hc595_init(){
    SR_DDR |= (1<<SER_pin)|(1<<SRCLK_pin)|(1<<RCLK_pin);
  }

  void 74hc595_write_bit(int bit){
    //Setting latch pin low, to tell SR we are writing
    SR_PORT &= ~(1<<RCLK_pin);

    //Setting the data pin to high or low.
    if(bit){
      SR_PORT |= (1<<SER_pin);
    }else{
      SR_PORT &= ~(1<<SER_pin);
    }

    //Sending bit to SR
    SR_PORT |= (1<<SRCLK_pin);
    SR_PORT &= ~(1<<SRCLK_pin);

    //Setting latch pin to high, finish and showing the results
    SR_PORT |= (1<<RCLK_pin);
  }

  void 74hc595_write_byte(uint8_t data){
    //Setting latch pin low, to tell SR we are writing
    SR_PORT &= ~(1<<RCLK_pin);

    //Sending one bit at a time
    for (uint8_t i = 0; i < 8; i++) {

      //Setting the data pin to high or low.
      if(data & 0x40){
        SR_PORT |= (1<<SER_pin);
      }else{
        SR_PORT &= ~(1<<SER_pin);
      }

      //Sending bit to SR
      SR_PORT |= (1<<SRCLK_pin);
      SR_PORT &= ~(1<<SRCLK_pin);

      //Shifting data to get next bit
      data = data << 1;
    }
    //Setting latch pin to high, finish and showing the results
    SR_PORT |= (1<<RCLK_pin);
  }

#endif
