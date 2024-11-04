
#include <xc.h>
#include <p32xxxx.h>

#define LED _RF4

void delay (int msec);
void update_state(void);

typedef enum{
    state_released1,
    state_pressed1,
    state_released2,
    state_pressed2,
    state_released3,
    state_pressed3,
    state_released4,
    state_pressed4,
}sw_state;

int main(void) {
    TRISF = 0x0006; //0b0000 0000 0000 0110
    LED = 0;
    while(1){
        update_state();
        delay(10);
    }
    return 0;
}

void delay (int msec){
    int i, j;
    for (i=0 ; i<msec ; i++){
        for (j=0 ; j<50 ; j++){
        }
    }
}

void update_state (void){
    static sw_state state = state_released1;
    static int toggle;
    
    switch (state){
        case state_released1:
            LED = 1;
            if (_RF1 == 1){
                state = state_pressed1;
            }
            break;
        case state_pressed1:
            if (_RF1 == 0){
                state = state_released2;
            }
            break;
        case state_released2:
            LED = 0;
            if (_RF1 == 1){
                state = state_pressed2;
                toggle = 0;
            }
            break;
        case state_pressed2:
            if (toggle < 4){
                _RF4 = ~_RF4;
                toggle ++;
                delay (500);
            }
            else{
                _RF4 = 1;
                if (_RF1 == 0){
                state = state_released3;
                }
            }
            break;
        case state_released3:
            if (_RF1 == 1){
                state = state_pressed3;
            }
            break;
        case state_pressed3:
            if ((_RF1 == 0) && (_RF2 == 0)){
                state = state_released1;
            }
            else if ((_RF1 == 0) && (_RF2 == 1)){
                state = state_released4;
            }
            break;
        case state_released4:
            while (_RF1 == 1){
                _RF4 = ~_RF4;
                delay(500);
                if (_RF1 == 0){
                    state = state_pressed4;
                }
            }
            break;
        case state_pressed4:
            if (_RF1 == 0){
                state = state_released1;
            }
            break;
        default:
            break;
    }
}
