/*
 * LCD_interface.h
 *
 * Created: 2/22/2023 10:08:56 PM
 *  Author: Ahmed Essam
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "DIO_interface.h"
#define  F_CPU 8000000
#include <util/delay.h>

#define  _4_BIT 1
#define  _8_BIT 2


/************************PIN CONFG**********************/
#define  LCD_MODE _4_BIT
//#define  LCD_MODE _8_BIT

#define  RS   PINB5
#define  EN   PINB4

#define  D7   PINB0
#define  D6   PINB1
#define  D5   PINB2
#define  D4   PINB3

#define  LCD_PORT   PB
/******************************************************/




void LCD_Init(void);//complete

void LCD_WriteNumber(s32 num);//complete
void LCD_WriteNumber_4D(u16 num);//complete
void LCD_WriteChar(u8 ch);//complete
void LCD_WriteStirng(u8* str);//complete&non
void LCD_WriteBinary(u8 num);//complete
void LCD_WriteHex(u8 num);//non
void LCD_GoTo(u8 line, u8 cell);//complete //line1,2 cell 1:16
void LCD_GoToClear(u8 line, u8 cell,u8 numofcells);
void LCD_GoToWriteString(u8 line, u8 cell,u8*str);
void LCD_Create_Character(u8 *Pattern,u8 Location);

void LCD_Clear(void);//Complete



#endif /* LCD_INTERFACE_H_ */