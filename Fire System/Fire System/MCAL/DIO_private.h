/*
 * DIO_private.h
 *
 * Created: 2/22/2023 9:58:33 PM
 *  Author: Ahmed Essam
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


extern const DIO_PinStatus_type PinStatusArray[TOTAL_PINS];
static void DIO_InitPin(DIO_Port_type pin, DIO_PinStatus_type status);


#endif /* DIO_PRIVATE_H_ */