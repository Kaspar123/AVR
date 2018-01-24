#include <avr/io.h>
#include "74HC595.h"

int main() {
  init();
  sendByte(0x25);
  sendByte(0x42);
  return 0;
}

void init() {
  DDRB = (1 << OE) | (1 << SER) | (1 << RCLK) | (1 << SRCLK) | (1 << SRCLR);
  PORTB &= ~((1 << SER) | (1 << OE));
  clear();
}

void clear() {
  PORTB &= ~((1 << SRCLK) | (1 << RCLK) | (1 << SRCLR));

  PORTB |= (1 << SRCLK);
  PORTB &= ~(1 << SRCLK);

  PORTB |= (1 << RCLK);
  PORTB &= ~(1 << RCLK);

  PORTB |= (1 << SRCLR);
}

void sendByte(uint8_t data) {
  PORTB &= ~((1 << SRCLK) | (1 << SER) | (1 << RCLK));
  uint8_t i;
  for (i = 0; i < 8; i++) {
    if (data & 0x01) PORTB |= (1 << SER);
    PORTB |= (1 << SRCLK);
    PORTB &= ~(1 << SRCLK);
    PORTB &= ~(1 << SER);
    data = data >> 1;
  }
  PORTB |= (1 << RCLK);
  PORTB &= ~(1 << RCLK);
}
