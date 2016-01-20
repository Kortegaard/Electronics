
#include <avr/io.h>
#include <util/delay.h>
#include "../lib/serial.h"

int main(){
  char data[255];
  char din;
  serial_init(52);
  serial_write("PROGRAM STARTED");
	while(1){
    serial_write("test");
    _delay_ms(500);
  }
  return 0;
}
