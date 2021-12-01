

#ifndef LCD_H_
#define LCD_H_

#define F_CPU 8000000UL

#include "StdTypes.h"
#include "DIO_Interface.h"
#include <util/delay.h> 

#define _4_BIT     0
#define _8_BIT     1

/***********************************LCD_Configration Pins **************************************/

#define LCD_MODE   _4_BIT            // choose 8 bit mode or 4 bit mode

#define EN         PINC0
#define RW         PINC1
#define RS         PINC2

/************** 8 BIT MODE***********************/

#define LCD_PORT   PD

/*************** 4 BIT MODE**********************/

#define D4     PINC4
#define D5     PINC5
#define D6     PINC6
#define D7     PINC7

/***********************************************************************************************/



void LCD_Init(void);

 void LCD_WriteCommand (u8 command) ;
 void LCD_WriteData    (u8 data)    ;

void LCD_WriteChar    (u8 ch)   ;
void LCD_WriteString  (u8*str)  ;
void LCD_WriteNumber  (s64 num) ;
void LCD_WriteNumber_GoTo (u8 line , u8 x , s64 num);
void LCD_WriteNumberInBinary(u8 num) ;
void LCD_WriteNumberInBinary2(u8 num);
void LCD_WriteNumberInHex (u8 num) ;

void LCD_WriteNumber_4Digits (u16 num) ;

void LCD_Clear (void) ;
void LCD_GoTo(u8 line , u8 x) ;

void LCD_CreateChracret (  u8*pattern ,u8 location );

#endif /* LCD_H_ */