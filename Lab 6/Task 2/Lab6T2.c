
#include "xc.h"
#include "p24fj128ga010.h"

#define sysFreq 8000000UL
#define freqCY sysFreq/2
#define mode 16
#define baudRate 9600
#define baudVal (int) ((freqCY/baudRate)/mode)-1


void sendDataBuff (const int *buff, uint8_t size){
    while(size){
        while(!U1STAbits.TRMT);
        U1TXREG = *buff;
        buff++;
        size--;
    }
    while(!U1STAbits.TRMT);
}

int main(void) {
    CLKDIVbits.RCDIV = 0;
    TRISB = 0x00FF;
    TRISE = 0x0000;
    PORTE = 0x0000;
    U1MODEbits.UARTEN = 0;
    U1MODEbits.STSEL = 0; // 1-Stop bit
    U1MODEbits.PDSEL = 0; // No Parity, 8-Data bits
    U1MODEbits.ABAUD = 0; // Auto-Baud disabled
    U1MODEbits.BRGH = 0; // Low Speed Mode
    U1BRG = baudVal;
    U1MODEbits.UARTEN = 1;
    U1STAbits.UTXEN = 1;
    
    int buf[4024]={33,33,33,34,34,34,34,34,34,35,37,39,41,42,42,41,40,38,37,36,35,34,32,31,31,31,31,30,31,31,32,33,34,33,31,28,27,29,34,45,63,89,122,154,177,182,163,127,84,46,23,16,18,23,25,25,24,23,24,24,24,24,23,24,25,26,27,28,28,28,29,29,30,30,31,31,32,32,33,33,34,35,36,38,39,39,41,42,43,44,46,47,48,49,50,52,52,53,54,55,55,55,55,55,55,54,53,52,50,48,45,43,41,40,38,36,35,33,32,31,31,31,30,30,29,29,30,30,31,31,30,30,30,31,31,31,32,32,32,32,32,33,33,34,34,34,34,34,34,34,34,34};
    sendDataBuff(buf, 150);
    U1MODEbits.UARTEN = 0;
    return 0;
}
