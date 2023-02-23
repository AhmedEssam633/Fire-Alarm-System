/*
 * ADC.c
 *
 * Created: 2/22/2023 9:46:33 PM
 *  Author: Ahmed Essam
 */ 
#include "STDTYPES.h"
#include "MemMap.h"
#include "UTILS.h"
#include "ADC.h"

#define  F_CPU 8000000
#include <util/delay.h>
 
 
u16 volt_ref;
void ADC_Init(ADC_Vref_type vref,ADC_Prescaler_type scaler)
{
	/*clock*/
	scaler=scaler&0x07;//00000111
	ADCSRA=ADCSRA&0XF8;//11111000
	ADCSRA=ADCSRA|scaler;
	/*volt ref*/
	switch(vref)
	{
		case VREF_AREF:
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		volt_ref=AREF;
		break;
		case VREF_AVCC:
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		volt_ref=5000;
		break;
		case VREF_256:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		volt_ref=2560;
		break;
	}
	/* ADC ENABLE */
	SET_BIT(ADCSRA,ADEN);  
}
u16 ADC_Read(ADC_Channel_type ch)
{
// 	u16 adc;
// 	u8 adcl,adch;
	/* select channel */
	ADMUX = ADMUX & 0XE0;//1110 0000
	ADMUX = ADMUX | ch; 
	/* start conversion */
	SET_BIT(ADCSRA,ADSC);
	/* w8 until finish */
	while(READ_BIT(ADCSRA,ADSC));
	/* get read */
	/*adcl-ADCL;
	  adch=ADCH;
	  adc=adch<<8 |adcl;*/
	  return ADC;
}
u16 ADC_ReadVolt(ADC_Channel_type ch)
{
	u16 adc= ADC_Read(ch);
	u16 volt=(adc*(u32)volt_ref)/1023;//volt_ref depend on AREF 
	return volt;
}