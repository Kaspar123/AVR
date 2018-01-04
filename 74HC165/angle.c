#include <avr/io.h>
#include <util/delay.h>
#include "USART.c"

#define Q7 PB5  // serial out
#define PL PB4  // parallel load
#define CE PB3  // clock enable
#define CP PB2  // clock

#define NUMBER_OF_BITS 8

uint8_t shiftIn(const uint8_t numberOfBits);

/**
* DDRB - data direction
* PORTB - output values
* PINB - input values
*/
int main(void) {
    DDRB = (1 << PL) | (1 << CE) | (1 << CP);

    PORTB |= (1 << Q7);

    initUSART();

    while(1) {
      	uint8_t res = shiftIn(NUMBER_OF_BITS);
    	printByte(res);
    	transmitByte('\r');
    	transmitByte('\n');
    }

  return 0;
}

uint8_t shiftIn(const uint8_t numberOfBits) {

  uint8_t value = 0, i = 0;

  PORTB &= ~(1 << CE);
  PORTB &= ~(1 << CP);

   // Paralell load
  PORTB &= ~(1 << PL);
  _delay_us(5);
  PORTB |= (1 << PL);
  _delay_us(5);


  for (i = 0; i < numberOfBits; i++) {
	value = value << 1;
    if (PINB & (1 << Q7)) {
      value |= 0x01;
    }
    PORTB &= ~(1 << CP);
    _delay_us(5);
	PORTB |= (1 << CP);

  }
  return value;
}
