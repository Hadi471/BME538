#include "xc.h"
#include <p24fj128ga010.h>

#pragma config FNOSC=FRCDIV

int main(void){
    CLKDIVbits.RCDIV = 2;
    TRISF = 0b0000010;
    PORTF = 0;
    __builtin_enable_interrupts();
    T2CON = 0x8030; //0b1000 0000 0111 0000
    PR2 = 976; // [(2000000*0.25)/256] - 1, *0.25 because we need 0.5 a second
    _T2IP = 4;
    _T2IF = 0;  
    _T2IE = 1;
    
    T3CON = 0x8030;
    PR3 = 1952; // [(2000000*0.5)/256] - 1, *0.5 because we need 1 a second
    _T3IP = 5;
    _T3IF = 0;
    _T3IE = 1;
    while(1);
    return 0;
}
void __attribute__ ((interrupt, no_auto_psv)) _T2Interrupt (){
    if(!_RF1){
        _RF2 = ! _RF2;
    }
    _T2IF = 0;
}

void __attribute__ ((interrupt, no_auto_psv)) _T3Interrupt(){
    if(_RF1){
        _RF2 =! _RF2;
    }
    _T3IF = 0;
}
