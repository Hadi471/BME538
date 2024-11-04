#include "xc.h"
#include <p24fj128ga010.h>
#include "keypad.h"

int keyNum = 99;
uint8_t keyTab[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,0,11}};

int scan (){
    int row = 0;
    int col = 0;
    int ind = 0;
    
    if (key_pressed()){
        if(!C1){
            delay (50);
            col = 1;
        }
        else if(!C2){
            delay(50);
            col = 2;
        }
        else if(!C3){
            delay(50);
            col = 3;
        }
    }
    for (ind=1 ; ind<=4 ; ind++){
        switch(ind){
            case 1:
                R1 = 0;
                R2 = 1;
                R3 = 1;
                R4 = 1;
                if (key_pressed()){
                    delay(50);
                    row = ind;
                }
                break;
            case 2:
                R1 = 1;
                R2 = 0;
                R3 = 1;
                R4 = 1;
                if (key_pressed()){
                    delay(50);
                    row = ind;
                }
                break;
            case 3:
                R1 = 1;
                R2 = 1;
                R3 = 0;
                R4 = 1;
                if (key_pressed()){
                    delay(50);
                    row = ind;
                }
                break;
            case 4:
                R1 = 1;
                R2 = 1;
                R3 = 1;
                R4 = 0;
                if (key_pressed()){
                    delay(50);
                    row = ind;
                }
                break;
        }
        if (row != 0){
            delay(50);
            return (keyTab[row-1][col-1]);
        }      
    }
    return 17;
}
