
#include "xc.h"
#include <p24fj128ga010.h>
#pragma config FNOSC = FRCPLL

void __attribute__((__interrupt__,auto_psv))_T2Interrupt (void){
    OC1RS = 3200; //20% of 16000 = 3200, 60% of 16000 = 9600, 90% of 16000 = 14400
    _T2IF = 0;
}

int main(void) {
    TRISD = 0x0000;
    PORTD = 0x0000;
    PR2 = 16000;  
    T2CON = 0x8000;
    OC1R = 0;
    OC1RS = 0;
    OC1CON = 0x0006;
    _T2IF = 0;
    _T2IP = 4;
    _T2IE = 1;
    
    while(1);
    return 0;
}
