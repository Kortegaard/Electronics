
BAUDRATE=115200
SRC=main
AVR_TYPE=atmega16
AVR_DEVICE=m16
AVR_FREQ=16000000UL
PROGRAMMER=avr910
DEVICE=/dev/tty.usbmodem1421
CC = avr-gcc
CFLAGS=-g -DF_CPU=$(AVR_FREQ) -funsigned-char -Os -Werror -Wextra -lm

all: object elf hex flash clean

clean:
	rm -f -v $(SRC).elf $(SRC).flash.hex $(SRC).o $(SRC).lst $(SRC).hex

object:
	$(CC) $(CFLAGS) -mmcu=$(AVR_TYPE) -Wa,-ahlmns=$(SRC).lst -c -o $(SRC).o $(SRC).c

elf: object
	$(CC) $(CFLAGS) -mmcu=$(AVR_TYPE) -o $(SRC).elf $(SRC).o

hex: elf
	avr-objcopy -j .text -j .data -O ihex $(SRC).elf $(SRC).hex

flash: hex
	sudo avrdude -q -b $(BAUDRATE) -c $(PROGRAMMER) -p $(AVR_DEVICE) -P $(DEVICE) -U flash:w:$(SRC).hex
