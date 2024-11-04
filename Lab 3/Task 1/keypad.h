#ifndef KEYPAD_H
#define	KEYPAD_H

#define R1 _RE0
#define R2 _RE1
#define R3 _RE2
#define R4 _RE3

#define C1 _RB3
#define C2 _RB4
#define C3 _RB5

#define key_pressed() (!C1||!C2||!C3)

int scan(void);

#endif	/* KEYPAD_H */

