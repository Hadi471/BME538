
#include "xc.h"
#include "p24fj128ga010.h"

#define sysFreq 8000000UL
#define freqCY sysFreq/2
#define mode 16
#define baudRate 9600
#define baudVal (int) ((freqCY/baudRate)/mode)-1
unsigned char Rxdata[1024];
const char Txdata[] = {
    "Main Menu Choices\r\n"\
    "1. Display a Welcome Message rate\r\n"\
    "2. Turn on LED Rate\r\n"\
    "3. Display My Last Two ID Digits\r\n"\
    "4. UART Echo\r\n"
    "\r\n\r\nPlease Choose a number\r\n"
};

void sendDataBuff (const char *buff, uint32_t size){
    while(size){
        while(!U1STAbits.TRMT);
        U1TXREG = *buff;
        buff++;
        size--;
    }
    while(!U1STAbits.TRMT);
}

uint32_t getMenuChoice(void){
    uint8_t menuItem;
    while(!U1STAbits.URXDA);
    menuItem = U1RXREG;
    menuItem -= '0';
    return (uint32_t)menuItem;
}

uint32_t getDataBuff (char *buff, uint32_t maxSize){
    uint32_t numChar;
    numChar = 0;
    while(numChar < maxSize)
     {
        uint8_t  character;
        while(!U1STAbits.URXDA);
         character = U1RXREG;
         if(character == '\r')
         break;
         *buff = character;
         buff++;
         numChar++;
        }
    return numChar;
}

int main(void) {
    CLKDIVbits.RCDIV = 0;
    TRISB = 0xFF;
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
    uint8_t menuChoice;
    sendDataBuff(Txdata, sizeof(Txdata));
    
    while(1){
        menuChoice = getMenuChoice();
        switch(menuChoice){
            case 1:
                sprintf(Rxdata, "\r\n Welcome to BME538 Fall 2024. Our names are BLAG and BLAH\r\n\r\n");
                sendDataBuff(Rxdata, strlen(Rxdata));
                sendDataBuff(Txdata, sizeof(Txdata));
                break;
            case 2:
                _RE9 = !_RE9;
                sprintf(Rxdata, "\r\nChose 2\r\n\r\n");
                sendDataBuff(Rxdata, strlen(Rxdata));
                sendDataBuff(Txdata, sizeof(Txdata));
                break;
            case 3:
                _RE0=_RB0;
                _RE1=_RB1;
                _RE2=_RB2;
                _RE3=_RB3;
                _RE4=_RB4;
                _RE5=_RB5;
                _RE6=_RB6;
                _RE7=_RB7;
                sprintf(Rxdata, "\r\nChose 3\r\n\r\n");
                sendDataBuff(Rxdata, strlen(Rxdata));
                sendDataBuff(Txdata, sizeof(Txdata));
                break;
            case 4:{
                uint32_t rx_size;
                sendDataBuff("Type a message (less than 100 characters) and press return\r\n", strlen("Type a message (less than 100 characters) and press return\r\n"));
                rx_size = getDataBuff(Rxdata, 1024);
                sendDataBuff("You Typed:\r\n\r\n", strlen("You Typed:\r\n\r\n"));
                sendDataBuff(Rxdata, rx_size);
                sendDataBuff("\r\n\r\nPress any key to continue", strlen("\r\n\r\nPress any key to continue"));
                sendDataBuff(Txdata, sizeof(Txdata));
                break;
            }
            default:
                sprintf(Rxdata, "Invalid Selection\r\n\r\n");
                sendDataBuff(Rxdata, strlen(Rxdata));
                sendDataBuff(Txdata, sizeof(Txdata));
                break;
        }
    }
    U1MODEbits.UARTEN = 0;
    return 0;
}
