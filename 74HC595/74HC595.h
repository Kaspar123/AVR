#ifndef __74HC595_H__
#define __74HC595_H__

void init();
void clear();
void sendByte(uint8_t data);
void sendSymbol(const uint8_t symbol);

#define OE     PB0 // enable output
#define SER    PB1 // serial input
#define RCLK   PB2 // storage register clock (positive edge triggered)
#define SRCLK  PB3 // shift register clock (positive edge triggered)
#define SRCLR  PB4 // clears shift register

const uint8_t NUMBERS[] = {
   0b11111100, // 0
   0b01100000, // 1
   0b11011010, // 2
   0b11110010, // 3
   0b01100110, // 4
   0b10110110, // 5
   0b10111110, // 6
   0b11100000, // 7
   0b11111110, // 8
   0b11110110, // 9
   0b11101110, // A
   0b00111110, // B
   0b10011100, // C
   0b01111010, // D
   0b10011110, // E
   0b10001110  // F
};

#endif
