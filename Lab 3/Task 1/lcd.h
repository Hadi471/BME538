#ifndef LCD_H
#define	LCD_H

// Macros definition: Command set for Hitachi 44780U LCD display controller
#define LCD_CLEAR 0x01
#define LCD_HOME 0x02
#define LCD_CURSOR_BACK 0x10
#define LCD_CURSOR_FWD 0x14
#define LCD_PAN_LEFT 0x18
#define LCD_PAN_RIGHT 0x1C
#define LCD_CURSOR_OFF 0x0C
#define LCD_CURSOR_ON 0x0E
#define LCD_CURSOR_BLINK 0x0F
#define LCD_CURSOR_LINE2 0xC0

#define LCD_delay 5 // ~5mS
#define LCD_Startup 15 // ~15mS

// LCD  setup commands from page 46 of Hitachi datasheet
#define FUNCTION_SET 0x28 // 4 bit interface, 2 lines, 5x8 font
#define ENTRY_MODE 0x06 // increment mode
#define DISPLAY_SETUP 0x0C // display on, cursor off, blink off
#define DisplayClr() LCDPutCmd(LCD_CLEAR) // Legacy support
#define LCDLine1() LCDPutCmd(LCD_HOME) // legacy support
#define LCDLine2() LCDPutCmd(LCD_CURSOR_LINE2) // legacy support
#define shift_cursor() LCDPutCmd(LCD_CURSOR_FWD) // legacy support
#define cursor_on() LCDPutCmd(LCD_CURSOR_ON) // legacy support

// Single bit for selecting command register or data register
#define instr 0
#define data 1

// These Macros  create the pin connections to the LCD 
#define LCD_PORT  PORTD
#define LCD_PWR PORTDbits.RD11 // LCD power pin
#define LCD_EN  PORTDbits.RD10 // LCD enable
#define LCD_RW  PORTDbits.RD9 // LCD read/write line
#define LCD_RS  PORTDbits.RD8 // LCD register select line

#define NB_LINES 2 // Number of display lines
#define NB_COL 16 // Number of characters per line

//Functions Prototype and Global Variables
void LCD_Initialize(void);
void LCDPutChar(char ch);
void LCDPutCmd(char ch);
void LCDPutStr(const char *); 
void LCDWriteNibble(char ch, char rs);
void LCDGoto(char pos, char ln);

#endif	/* LCD_H */
