
#include <avr/io.h>
#include <util/delay.h>

int main(){
  //Setting whole PORTD as output
  DDRD = 0xFF;
  //Setting whole PORTD high
  PORTD = 0x00;

  //Setting vars to control bit shift
  int count = 0;
  int direction = 1;

  while (1) {
    //Changing direction
    if (count > 6) {
      direction = -1;
    }else if(count < 1){
      direction = 1;
    }
    //Bit shifting, to set the right pin high
    PORTD = 1 << count;
    count += direction;
    _delay_ms(100);
  }
  return 0;
}
