#ifndef KEYPAD_H
#define	KEYPAD_H

#define R1 _RA4
#define R2 _RA5
#define R3 _RA6
#define R4 _RA7

#define C1 _RA9
#define C2 _RA10
#define C3 _RA14
#define C4 _RA15

int scan(void);
void delay (int m);
#endif	/* KEYPAD_H */

