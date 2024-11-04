
#include "xc.h"
#include <p24fj128ga010.h>
#include "keypad.h"
#include "lcd.h"
#include <stdio.h>

int main(void) {
    uint8_t keynum, cNum = 0;
    char key;
    
    AD1PCFG = 0xFFFF;
    TRISB = 0x38; //0b0011 1000
    TRISE = 0;
    TRISD = 0;
    
    LCD_Initialize();
    DisplayClr();
    LCDPutStr("Hadi and Husna");
    LCDGoto(0,1);
    
    while(1){
        PORTE = 0;
        if(key_pressed()){
            keynum = scan();
            switch(keynum){
                case 0x0:
                    cNum = 48;
                    break;
                case 0x1:
                    cNum = 49;
                    break;
                case 0x2:
                    cNum = 50;
                    break;
                case 0x3:
                    cNum = 51;
                    break;
                case 0x4:
                    cNum = 52;
                    break;
                case 0x5:
                    cNum = 53;
                    break;
                case 0x6:
                    cNum = 54;
                    break;
                case 0x7:
                    cNum = 55;
                    break;
                case 0x8:
                    cNum = 56;
                    break;
                case 0x9:
                    cNum = 57;
                    break;
                case 0xA:
                    cNum = 42;
                    break;
                case 0xB:
                    cNum = 35;
                    break;
                default:
                    cNum = 0;
                    break;
            }
            key=cNum;
            LCDPutChar(key);
        }
        delay(150);
    }
    return 0;
}

