
BAUDRATE=115200
src=main
AVR_TYPE=atmega16
AVR_DEVICE=m16
AVR_FREQ=16000000UL
PROGRAMMER=avr910
DEVICE=/dev/tty.usbmodem1421
CC = avr-gcc
CFLAGS=-g -DF_CPU=$(AVR_FREQ) -funsigned-char -Os -Werror -Wextra -lm

all: object elf hex flash clean

clean:
	rm -f -v $(src).elf $(src).flash.hex $(src).o $(src).lst $(src).hex

object:
	$(CC) $(CFLAGS) -mmcu=$(AVR_TYPE) -Wa,-ahlmns=$(src).lst -c -o $(src).o $(src).c

elf: object
	$(CC) $(CFLAGS) -mmcu=$(AVR_TYPE) -o $(src).elf $(src).o

hex: elf
	avr-objcopy -j .text -j .data -O ihex $(src).elf $(src).hex

flash: hex
	sudo avrdude -q -b $(BAUDRATE) -c $(PROGRAMMER) -p $(AVR_DEVICE) -P $(DEVICE) -U flash:w:$(src).hex
