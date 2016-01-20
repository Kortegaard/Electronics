/*
*         Title : Serial communication
*        Author : Anders S. Kortegaard
*          Date : 19/01 - 2016
*
*   Description : For uart serial communication with the ATmega16/32
*
*       credits : http://extremeelectronics.co.in/avr-tutorials/using-the-usart-of-avr-microcontrollers-reading-and-writing-data/
*
*/


#ifndef __serial_h__
  #define __serial_h__
  #include <stdio.h>
  #include <string.h>

  void serial_init();
  char serial_read_char();
  void serial_read(char *data);
  void serial_write_char(char data);
  void serial_write(char *arr);

  void serial_init()
  {
     //uint16_t ubrr_value = 51
     //Set Baud rate
     UBRRL = 51;
     UBRRH = (51>>8);

     //Set Frame Format
     UCSRC=(1<<URSEL)|(3<<UCSZ0);

     //Enable The receiver and transmitter
     UCSRB=(1<<RXEN)|(1<<TXEN);
  }


  //This function is used to read the available data
  //from USART. This function will wait untill data is
  //available.
  char serial_read_char()
  {
     //Wait untill a data is available
     while(!(UCSRA & (1<<RXC))){}
     return UDR;
  }

  void serial_newline(){
    serial_write_char(0x0A);
    serial_write_char(0x0D);
  }

  void serial_read(char *data){
    char in;
    int i=0;
    do{
      in = serial_read_char();
      if(in != 0x0D){
        data[i] = in;
        i++;
        serial_write_char(in);
      }else{
        serial_newline();
        data[i] = '\0';
      }
    }while(in != 0x0D);
  }

  //This fuction writes the given "data" to
  //the USART which then transmit it via TX line
  void serial_write_char(char data)
  {
     //Wait untill the transmitter is ready
     while(!(UCSRA & (1<<UDRE))){}

     //Now write the data to USART buffer
     UDR=data;
  }

  void serial_write(char *arr){
    int i = 0;
    while (arr[i] != '\0') {
      serial_write_char(arr[i]);
      i++;
    }
    serial_newline();
  }

#endif
