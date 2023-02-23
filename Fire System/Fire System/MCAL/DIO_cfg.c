/*
 * DIO_cfg.c
 *
 * Created: 2/22/2023 9:55:05 PM
 *  Author: Ahmed Essam
 */ 
#include "DIO_interface.h"
//#include "DIO_private.h"
#include "STDTYPES.h"


const DIO_PinStatus_type PinStatusArray[TOTAL_PINS]={
	INFREE,     /* Port A Pin 0 ADC0*/
	INFREE,     /* Port A Pin 1 ADC1*/
	INFREE,     /* Port A Pin 2 */
	OUTPUT,     /* Port A Pin 3 */
	OUTPUT,     /* Port A Pin 4 */
	OUTPUT,     /* Port A Pin 5 */
	INFREE,     /* Port A Pin 6 */
	OUTPUT,     /* Port A Pin 7 ADC7*/
	OUTPUT,     /* Port B Pin 0 /   */
	OUTPUT,     /* Port B Pin 1 /   */
	OUTPUT,     /* Port B Pin 2 /INT2*/
	OUTPUT,     /* Port B Pin 3 / OCO*/
	OUTPUT,     /* Port B Pin 4 /ss*/
	OUTPUT,     /* Port B Pin 5 //mosi*/
	OUTPUT,     /* Port B Pin 6 /miso*/
	OUTPUT,     /* Port B Pin 7 clk*/
	OUTPUT,     /* Port C Pin 0 */
	OUTPUT,     /* Port C Pin 1 */
	OUTPUT,     /* Port C Pin 2 */
	OUTPUT,     /* Port C Pin 3 */
	OUTPUT,     /* Port C Pin 4 */
	OUTPUT,     /* Port C Pin 5 */
	OUTPUT,     /* Port C Pin 6 */
	OUTPUT,     /* Port C Pin 7 */
	OUTPUT,     /* Port D Pin 0 */
	OUTPUT,     /* Port D Pin 1 */
	OUTPUT,     /* Port D Pin 2 */
	OUTPUT,     /* Port D Pin 3 /INT0*/
	INPULL,     /* Port D Pin 4 /INT1*/
	INPULL,     /* Port D Pin 5 /OC1A*/
	INPULL,     /* Port D Pin 6 / ICP*/
	INPULL,     /* Port D Pin 7 */
};