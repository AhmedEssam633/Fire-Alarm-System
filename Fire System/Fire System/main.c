/*
 * Fire System.c
 *
 * Created: 2/22/2023 9:42:14 PM
 * Author : Ahmed Essam
 */ 


#define  F_CPU 8000000
#include <util/delay.h>
#include "MemMap.h"
#include "UTILS.h"
#include "STDTYPES.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KeyPad_interface.h"
#include "ADC.h"
#include "Sensors.h"

int main(void)
{
 	DIO_Init();
	LCD_Init();
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	KEYPAD_Init();
	DDRC=0XFF;
	LCD_GoTo(0,0);
	LCD_WriteStirng("  System Start  ");
	_delay_ms(250);
	
	u16 temp=0,press=0,pass=0;
	u8 C=0,i=0,flag=0,k=0;
	while (1) 
    {
		if (flag==0)
		{
			C=0;
			temp= Temp_Read();
			LCD_GoTo(0,0);
			LCD_WriteStirng("Temp:");
			LCD_GoTo(0,7);
			LCD_WriteNumber(temp/10);
			LCD_WriteChar('.');
			LCD_WriteNumber(temp%10);
			if (temp/10<=35)
			{
				LCD_GoTo(0,12);
				LCD_WriteStirng("FINE");
				CLR_BIT(PORTC,0);
				CLR_BIT(PORTC,1);
				CLR_BIT(PORTC,2);
				CLR_BIT(PORTC,3);
			}
			else if (temp/10>35&&temp/10<50)
			{
				LCD_GoTo(0,12);
				LCD_WriteStirng("FINE");
				LCD_GoTo(1,0);
				LCD_WriteStirng("                ");
				CLR_BIT(PORTC,0);
				CLR_BIT(PORTC,1);
				CLR_BIT(PORTC,2);
				CLR_BIT(PORTC,3);
			}
			else if (temp/10>=50)
			{
				press=Press_Read();
				LCD_GoTo(1,0);
				LCD_WriteStirng("Smoke:");
				LCD_GoTo(1,6);
				LCD_WriteNumber(press/10);
				LCD_WriteChar('.');
				LCD_WriteNumber(press%10);
				if (press/10<65)
				{
					SET_BIT(PORTC,0);
					CLR_BIT(PORTC,1);
					CLR_BIT(PORTC,2);
					CLR_BIT(PORTC,3);
					LCD_GoTo(0,12);
					LCD_WriteStirng("    ");
					LCD_GoTo(1,12);
					LCD_WriteStirng("HEAT");
					press=Press_Read();
					LCD_GoTo(1,0);
					LCD_WriteStirng("Smoke:");
					LCD_GoTo(1,6);
					LCD_WriteNumber(press/10);
					LCD_WriteChar('.');
					LCD_WriteNumber(press%10);
				}
				else if (press/10>=65)
				{
					CLR_BIT(PORTC,0);
					SET_BIT(PORTC,1);
					SET_BIT(PORTC,2);
					LCD_GoTo(0,12);
					LCD_WriteStirng("    ");
					LCD_GoTo(1,12);
					LCD_WriteStirng("FAIR");
					press=Press_Read();
					LCD_GoTo(1,0);
					LCD_WriteStirng("Smoke:");
					LCD_GoTo(1,6);
					LCD_WriteNumber(press/10);
					LCD_WriteChar('.');
					LCD_WriteNumber(press%10);
					flag=1;
				}
			}
		}
		if (flag==1)
		{
			if (C==0)
			{
				LCD_Clear();
				C++;
				SET_BIT(PORTC,3);
				LCD_GoTo(0,0);
				LCD_WriteStirng("......FIRE......");
				LCD_GoTo(1,0);
				LCD_WriteStirng("Pass:");
			}
			k=KEYPAD_GetKey();
			if(k!=NO_KEY)
			{
				LCD_GoTo(1,6+i);
				LCD_WriteChar(k);
				i++;
				if (k>='0'&&k<='9')
				{
					pass=pass*10+(k-'0');
				}
				else if (k=='=')
				{
					if (pass==633)
					{
						LCD_GoTo(1,0);
						LCD_WriteStirng("pass is corr.");
						_delay_ms(250);
						LCD_Clear();
						i=0;
						pass=0;
						flag=0;
					}
					else
					{
						LCD_GoTo(1,0);
						LCD_WriteStirng("pass is wrong");
						_delay_ms(250);
						LCD_GoTo(1,0);
						LCD_WriteStirng("try again....");
						_delay_ms(250);
						LCD_Clear();
						LCD_GoTo(0,0);
						LCD_WriteStirng("......FIRE......");
						LCD_GoTo(1,0);
						LCD_WriteStirng("Pass:");
						i=0;
						pass=0;
					}
					
				}
			}
		}
			
	}
}
			
			
		