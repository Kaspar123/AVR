
#include <avr/io.h>
#include "USART.h"
#include <util/setbaud.h>

void initUSART(void) {
	/** requires BAUD to be defined. */
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;
#if USE_2X
	UCSR0A |= (1 << U2X0);
#else
	UCSR0A &= ~(1 << U2X0);
#endif

	/** Enable USART transmitter/receiver */
	UCSR0B = (1 << TXEN0) | (1 << RXEN0);
	/** 8 data bits, 1 stop bit */
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void transmitByte(uint8_t data) {
	/** wait until buffer is empty */
	loop_until_bit_is_set(UCSR0A, UDRE0);
	UDR0 = data;
}

uint8_t receiveByte(void) {
	loop_until_bit_is_set(UCSR0A, RXC0);
	return UDR0;
}

void printString(const char* myString) {
	uint8_t i = 0;
	while (myString[i]) {
		transmitByte(myString[i]);
		i++;
	}
}

void readString(char* myString, uint8_t maxLength) {
	char response;
	uint8_t i = 0;
	while (i < maxLength - 1) {
		response = receiveByte();
		// transmitByte(response);
		/** Enter marks the end */
		if (response == '\r') {
			break;
		} else {
			myString[i] = response;
			i++;
		}
	}
	myString[i] = 0;	/** terminal NULL char to the end */
}

void printByte(uint8_t byte) {
	/** one byte max value is 255 */
	transmitByte('0' + (byte / 100));
	transmitByte('0' + ((byte / 10) % 10));
	transmitByte('0' + (byte % 10));
}

void printWord(uint16_t word) {
	transmitByte('0' + (word / 10000));
	transmitByte('0' + ((word / 1000) % 10));
	transmitByte('0' + ((word / 100) % 10));
	transmitByte('0' + ((word / 10) % 10));
	transmitByte('0' + (word  % 10));
}

void printBinaryByte(uint8_t byte) {
	uint8_t bit;
	for (bit = 7; bit >= 0; bit--) {
		if (bit_is_set(byte, bit)) {
			transmitByte('1');
		} else {
			transmitByte('0');
		}
	}
}



