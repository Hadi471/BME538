#include "xc.h"
#include "lcd.h"

void delay (int m){
    int i,j;
    for(i=0 ; i<m ; i++){
        for (j=0 ; j<50 ; j++){
        }
    }
}

void LCD_Initialize()
{
    LCD_PWR = 1; // power up the LCD
    delay(LCD_Startup); //Short delay required to allow power to stabilize
    LCDPutCmd(0x32);  // required by display initialization
    LCDPutCmd(FUNCTION_SET); // Set interface size, # of lines and font
    LCDPutCmd(DISPLAY_SETUP); // Turn on display and sets up cursor
    DisplayClr(); 
    LCDPutCmd(ENTRY_MODE); // set cursor movement direction
}

void LCDPutCmd(char ch)
{
    delay(LCD_delay); //Shot delay for busy flag 
    LCDWriteNibble(ch,instr); //Send the higher nibble (Most Significant 4 bits)
    ch = (ch << 4); //Get the lower nibble (Lowest Significant 4 bits)
    delay(1); //Shot delay for busy flag 
    LCDWriteNibble(ch,instr); //Now send the lower nibble
}

void LCDWriteNibble(char ch, char rs)
{
    ch = (ch >> 4); // Always send the upper nibble
    ch = (ch & 0x0F); // Mask off the nibble to be transmitted
    LCD_PORT = (LCD_PORT & 0xF0); // clear the lower half of LCD_PORT
    LCD_PORT = (LCD_PORT | ch); // move the nibble onto LCD_PORT
    LCD_RS = rs; // Set data/instr bit to 0 = insructions; 1 = data
    LCD_RW = 0; // RW - set write mode
    LCD_EN = 1; // Set up enable before writing nibble
    LCD_EN = 0; // Turn off enable after write of nibble
}

void LCDPutStr(const char *str){
    char i=0;
    while (str[i]) // While string has not been fully traveresed
    {
    LCDPutChar(str[i++]); // Go display current char
    }
}

void LCDPutChar(char ch)
{
    delay(LCD_delay);
    LCDWriteNibble(ch,data); //Send higher nibble first
    ch = (ch << 4); //Get the lower nibble
    LCDWriteNibble(ch,data); // Now send the low nibble
}

void LCDGoto(char pos,char ln)
{
    if ((ln > (NB_LINES-1)) || (pos > (NB_COL-1))) // If incorrect line or column
    {
        return; // Just do nothing
    }
    LCDPutCmd((ln == 1) ? (0xC0 | pos) : (0x80 | pos)); // LCD_Goto command
    delay(LCD_delay); // Wait for the LCD to finish
}
