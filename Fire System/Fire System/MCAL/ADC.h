/*
 * ADC.h
 *
 * Created: 2/22/2023 9:46:50 PM
 *  Author: Ahmed Essam
 */ 


#ifndef ADC_H_
#define ADC_H_

typedef enum{
	VREF_AREF,
	VREF_AVCC,
	VREF_256
}ADC_Vref_type;//Name of driver _ Name of describtion_ type

typedef enum{
	CH_0=0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7
}ADC_Channel_type;

typedef enum{
	ADC_SCALER_2=1,
	ADC_SCALER_4,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128
}ADC_Prescaler_type;

#define AREF   ((u16)3000)

void ADC_Init(ADC_Vref_type vref,ADC_Prescaler_type scaler);
u16 ADC_Read(ADC_Channel_type ch);
u16 ADC_ReadVolt(ADC_Channel_type ch);




#endif /* ADC_H_ */