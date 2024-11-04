
#include "xc.h"
#include <p32xxxx.h>


void msDelay (int msec){
    int i, j;
    for (i=0 ; i<msec ; i++){
        for (j=0 ; j<50 ; j++){
        }
    }
}

int main(void){
    DDPCONbits.JTAGEN = 0;
    TRISA = 0x0000;
    PORTA = 0x0000;
    
    while(1){
        PORTA = 0;
        msDelay(3000);
        PORTA = 0b0110011;
        msDelay(1000);
        PORTA = 0x0000;
        msDelay(250);
        PORTA = 0b0110011;
        msDelay(500);
        PORTA = 0x0000;
        msDelay(3000);
        
        PORTA = 0b0110011;
        msDelay(1000);
        PORTA = 0x0000;
        msDelay(250);
        PORTA = 0b0110011;
        msDelay(500);
        PORTA = 0x0000;
        msDelay(250);
        PORTA = 0b0110011;
        msDelay(500);
        PORTA = 0x0000;
        msDelay(250);
        PORTA = 0b0110011;
        msDelay(500);
        PORTA = 0x0000;
        msDelay(3000);
        
        PORTA = 0b0110011;
        msDelay(1000);
        PORTA = 0x0000;
        msDelay(250);
        PORTA = 0b0110011;
        msDelay(500);
        PORTA = 0x0000;
        msDelay(250);
        PORTA = 0b0110011;
        msDelay(1000);
        PORTA = 0x0000;
        msDelay(250);
        PORTA = 0b0110011;
        msDelay(500);
        PORTA = 0x0000;
        msDelay(3000);
    }
}
