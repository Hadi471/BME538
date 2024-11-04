
#include <xc.h>
#include <p24fj128ga010.h>

void delay (int msec){
    int i, j;
    for(i=0 ; i<msec ; i++){
        for(j=0 ; j<msec ; j++){
        }
    }
}

int main(void) {
    AD1PCFG = 0xFFFF;
    TRISB = 0x8082; //0b1000 0000 1000 0010
    TRISG = 0x0000;
    
    while(1){
        if (_RB15 == 1){
            delay(10); //debounce delay
            _RG15 = 1;
            if (_RB1 == 1){
                delay(10);
                _RG0 = 1;
                _RG1 = 0;
            }
            else if (_RB7 == 1){
                delay(10);
                _RG0 = 0;
                _RG1 = 1;
            }
            else{
                delay(10);
                _RG0 = 0;
                _RG1 = 0;
            }
        }
        delay(10);
        _RG15 = 0;
    }
    return 0;
}
