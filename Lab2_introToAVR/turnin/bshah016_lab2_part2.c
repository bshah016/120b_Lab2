/*	Author: bshah016
 *  Partner(s) Name: Brij Shah
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char GetBit(unsigned char x, unsigned char k) { //taken from the zyBooks getBit function
	return ((x & (0x01 << k )) != 0);
}
int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	//unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	unsigned int cntavail = 0x00; //will assign as PORTC = cntavail;
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A


	while(1) {
		tmpA = PINA & 0x0F; //set last 4 bits (4 - 7) to 0 using the & operator with  F (1111 in binary)
         
		if (GetBit(tmpA, 0) == 0x00) {
			cntavail += 1;
		}
		if (GetBit(tmpA, 1) == 0x00) {
                        cntavail += 1;
                }
		if (GetBit(tmpA, 2) == 0x00) {
                        cntavail += 1;
                }
		if (GetBit(tmpA, 3) == 0x00) {
                        cntavail += 1;
                }
	
		PORTC = cntavail;

	}
	return 0;
}
