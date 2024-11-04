

#include "xc.h"
#include <p24fj128ga010.h>
#pragma config FNOSC = FRCPLL

void __attribute__((__interrupt__,auto_psv))_ISR_OC1Interrupt (void){
    OC1R = OC1R + (8000);
    _OC1IF = 0;
}

int main(void) {
    TRISD = 0x0000;
    PORTD = 0x0000;
    PR2 = 8000;
    T2CON = 0x8000;
    OC1R = 8000;
    OC1RS = 8000;
    OC1CON = 0x0003;
    _OC1IF = 0;
    _OC1IP = 1;
    _OC1IE = 1;
    while(1);
    
    return 0;
}
