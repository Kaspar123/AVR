
/** Functions to initialize, send, receive data over USART */

/** initUSART requires BAUD to be defined in order to calculate the bit-rate*/
#ifndef BAUD
#define BAUD 9600
#endif

/** configures USART hardware */
void initUSART(void);

void transmitByte(uint8_t data);
uint8_t receiveByte(void);

/** for transmitting entire string */
void printString(const char* myString);
/** define string variable, pass it to this function and get the string */
void readString(char* myString, uint8_t maxLength);

/** print byte as ascii equivalent */
void printByte(uint8_t byte);
void printWord(uint16_t word);

/** prints a byte in 1s and 0s */
void printBinaryByte(uint8_t byte);

char nibbleToHex(uint8_t nibble);
char nibbleToHexCharacter(uint8_t nibble);
/** prints a byte in hexadecimal */
void printHexByte(uint8_t byte);

uint8_t getNumber(void);
