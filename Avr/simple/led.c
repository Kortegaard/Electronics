
#include <avr/io.h>
#include <util/delay.h>

int main(){
  //Setting all pins on port D to output (0 = input, 1 = output)
  DDRD = 0xFF;

  //Setting all pins high
  PORTD = 0xFF;
}
