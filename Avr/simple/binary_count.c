
#include <avr/io.h>
#include <util/delay.h>

int main(){
  //Setting whole PORTD as output
  DDRD = 0xFF;
  //Setting whole PORTD low
  PORTD = 0x00;

  char count = 0xFD;
  while (1) {
    //Displaying count,
    PORTD = count;
    //Adding 1 to the count byte
    count++;
    _delay_ms(200);
  }
  return 0;
}
