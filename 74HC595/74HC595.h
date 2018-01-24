#ifndef __74HC595_H__
#define __74HC595_H__

void init();
void clear();
void sendByte(uint8_t data);

#define OE     PB0 // enable output
#define SER    PB1 // serial input
#define RCLK   PB2 // storage register clock (positive edge triggered)
#define SRCLK  PB3 // shift register clock (positive edge triggered)
#define SRCLR  PB4 // clears shift register

#endif
