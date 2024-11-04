
#include "xc.h"
#include <p24fj128ga010.h>

void _ISR _INT0Interrupt(void){
    _RD0=!_RD0;
    _RD1=!_RD1;
    _INT0IF = 0;
}

int main(void) {
    TRISD = 0;
    PORTD = 0;
    TRISF = 0b01000000;
    __builtin_enable_interrupts();
    _INT0IE = 1;
    _INT0EP = 1;
    _INT0IP = 5;
    _INT0IF = 0;
    
    while(1);
    return 0;
}
