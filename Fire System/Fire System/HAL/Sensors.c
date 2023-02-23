/*
 * Sensor.c
 *
 * Created: 2/22/2023 10:09:32 PM
 *  Author: Ahmed Essam
 */ 
#include "STDTYPES.h"
#include "ADC.h"
#include "Sensors.h"

#define  F_CPU 8000000
#include <util/delay.h>

u16 Temp_Read(void)
{
	u16 volt = ADC_ReadVolt(LM35_CH);
	u16 temp = volt;//i don't divided by 10 because i want result by 0.5degree
	return temp;
}

//*****************************MPX4115**************************
u16 Press_Read(void)
{
	u16 adc,press;
	adc=ADC_Read(MPX_CH);
	press=(((u32)(adc-55)*1000)/921)+150;
	return press;
}