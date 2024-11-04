
#include "xc.h"
#include <p32xxxx.h>
#include "keypad.h"
#include <stdio.h>

int main(void) {
    uint8_t keynum = 0;
    DDPCONbits.JTAGEN = 0;
    TRISA = 0xC600; //0b1100 0110 0000 0000
    TRISF = 0;
    PORTF=0;
    while(1){
        PORTA = 0x00;
        if(!C1){
            keynum = scan();
            switch(keynum){
                case 0x1:
                    PORTF = 0b00001;
                    break;
                case 0x4:
                    PORTF = 0b00100;
                    break;
                case 0x7:   
                    PORTF = 0b00111;
                    break;
                case 0xE:
                    PORTF = 0b01110;
                    break;
            }
        }
    }
    delay(150);
    return 0;
}

