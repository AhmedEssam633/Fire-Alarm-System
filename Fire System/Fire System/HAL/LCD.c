/*
 * LCD.c
 *
 * Created: 2/22/2023 10:08:25 PM
 *  Author: Ahmed Essam
 */ 
#include "LCD_interface.h"
#include "UTILS.h"
#if LCD_MODE==_8_BIT

static void LCD_writeCommand(u8 command)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCD_PORT,command);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

static void writeData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
void LCD_Init(void)
{
	LCD_writeCommand(0x38);// screen on 8 bit mode 
	LCD_writeCommand(0x0c);// cursor off 0x0e,0x0f
	LCD_writeCommand(0x01);// clear screen
	_delay_ms(1);
	LCD_writeCommand(0x06);// increase DDRAM address no shift
}

#elif LCD_MODE==_4_BIT

static void LCD_writeCommand(u8 command)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D7,READ_BIT(command,7));
	DIO_WritePin(D6,READ_BIT(command,6));
	DIO_WritePin(D5,READ_BIT(command,5));
	DIO_WritePin(D4,READ_BIT(command,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(command,3));
	DIO_WritePin(D6,READ_BIT(command,2));
	DIO_WritePin(D5,READ_BIT(command,1));
	DIO_WritePin(D4,READ_BIT(command,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

static void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(D7,READ_BIT(data,7));
	DIO_WritePin(D6,READ_BIT(data,6));
	DIO_WritePin(D5,READ_BIT(data,5));
	DIO_WritePin(D4,READ_BIT(data,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(data,3));
	DIO_WritePin(D6,READ_BIT(data,2));
	DIO_WritePin(D5,READ_BIT(data,1));
	DIO_WritePin(D4,READ_BIT(data,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
void LCD_Init(void)
{
	_delay_ms(50);
	LCD_writeCommand(0x02);
	LCD_writeCommand(0x28);// screen on 8 bit mode
	LCD_writeCommand(0x0c);// cursor off 0x0e,0x0f
	LCD_writeCommand(0x01);// clear screen
	_delay_ms(1);
	LCD_writeCommand(0x06);// increase DDRAM address no shift
}
#endif

/**************************************************************************************/
void LCD_WriteChar(u8 ch)
{
	LCD_WriteData(ch);
}
void LCD_Clear()
{
	LCD_writeCommand(0X01);
	_delay_ms(1);
}
void LCD_WriteNumber(s32 num)
{
	u8 i=0,rem,str[20];
	s8 j;
	if(num==0)
	{
		LCD_WriteChar('0');
		return; 
	}
	if(num<0)
	{
		num=num*-1;
		LCD_WriteChar('-');
	}
	while(num>0)
	{
		rem=num%10 ;
		str[i]=rem+'0';
		num=num/10;
		i++;
	}
	for (j=i-1;j>=0;j--)
	{
		LCD_WriteChar(str[j]);//or str[j-1]
	}
	
}


void LCD_WriteStirng(u8* str)
{
	u8 i=0;
	for (i=0;str[i];i++)
	{
		LCD_WriteChar(str[i]);
	}
}

void LCD_GoTo(u8 line, u8 cell)
{
	if (line==0)
	{
		LCD_writeCommand(0X80+cell);
	}
	else if (line==1)
	{
		LCD_writeCommand(0X80+0x40+cell);
	}
}

void LCD_WriteNumber_4D(u16 num)//8542
{
	LCD_WriteChar(((num%10000)/1000)+'0');
	LCD_WriteChar(((num%1000)/100)+'0');
	LCD_WriteChar(((num%100)/10)+'0');
	LCD_WriteChar(((num%10)/1)+'0');
}



