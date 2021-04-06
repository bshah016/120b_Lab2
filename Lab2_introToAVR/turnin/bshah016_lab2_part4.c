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
	DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as outputs
	DDRC - 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;
	//unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	//unsigned int cntavail = 0x00; //will assign as PORTC = cntavail;
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char tmpVal = 0x00;


	while(1) {
		tmpA = PINA;
		tmpB = PINB;
		tmpC = PINC;

		if (tmpA + tmpB + tmpC > 0x8C) { //140 in hex = 0x8C, so if combined weight > 240,
			PORTD = PORTD | 0x01; // if too much weight, puts a 1 in PD0
		}
		if (tmpA > tmpC) { //if tmpC < tmpA, can lead to a wrong value bc a negative number, need to go both ways
			if (tmpA - tmpC > 0x50) { //80 in hex = 0x50, so if unbalanced,
				PORTD = PORTD | 0x02; //if unbalanced, puts a 1 in PD1;
			}
		}
		else {
			if (tmpC - tmpA > 0x50) { //same as above
				PORTD = PORTD | 0x02; //same as above
			}
		}

		PORTD = (tmpA + tmpB + tmpC) | tmpVal; //sets it to its weight value
	}
	return 0;
}
