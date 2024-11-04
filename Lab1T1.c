/*
 * File:   Lab1T1.c
 * Author: Hadi Khokhar (501178997)
 *         Husna Haroon (501078921)
 *
 * Created on September 8, 2024, 2:28 PM
 */


#include <xc.h>
#include <P24FJ256GA110.h>

void msDelay (int msec){
    int i,j;
    for (i=0 ; i<msec ; i++){
        for (j=0 ; j<50 ; j++){
            
        }
    }
}

int main(void) {

    TRISD = 0x0000;
    PORTD = 0x0000;
    while(1){
        PORTD = 0;
        msDelay(250);
        PORTD = 0b00010000000;
        msDelay(1000);
        PORTD = 0;
        msDelay(250);
        PORTD = 0b01000000000;
        msDelay(1000);
        PORTD = 0;
        msDelay(250);
        PORTD = 0b01010000000;
        msDelay(1000);
        PORTD = 0;
        msDelay(250);
        PORTD = 0b00000000010;
        msDelay(1000);
        PORTD = 0;
        msDelay(250);
        PORTD = 0b00010000010;
        msDelay(1000);
        PORTD = 0;
        msDelay(250);
        PORTD = 0b01000000010;
        msDelay(1000);
        PORTD = 0;
        msDelay(250);
        PORTD = 0b01010000010;
        msDelay(1000);
        PORTD = 0;
        msDelay(250);
        PORTD = 0b00000000100;
        msDelay(1000);
        PORTD = 0;
        msDelay(250);
        PORTD = 0b00010000100;
        msDelay(1000);
        PORTD = 0;
        msDelay(250);
        PORTD = 0b01000000100;
        msDelay(1000);
        PORTD = 0;
        msDelay(250);
        PORTD = 0b01010000100;
        msDelay(1000);
        PORTD = 0;
        msDelay(250);
        PORTD = 0b00000000110;
        msDelay(1000);
        PORTD = 0;
        msDelay(250);
        PORTD = 0b00010000110;
        msDelay(1000);
        PORTD = 0;
        msDelay(250);
        PORTD = 0b01000000110;
        msDelay(1000);
        PORTD = 0;
        msDelay(250);
        PORTD = 0b01010000110;
        msDelay(1000);
        PORTD = 0;
    }
return 0;
}
