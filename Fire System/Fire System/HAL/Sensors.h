/*
 * Sensor.h
 *
 * Created: 2/22/2023 10:10:17 PM
 *  Author: Ahmed Essam
 */ 


#ifndef SENSORS_H_
#define SENSORS_H_

#define  LM35_CH   CH_0
/* return temp c*10 */
u16 Temp_Read(void);

/* MPX4115 Sensor*/
#define  MPX_CH    CH_2
u16 Press_Read(void);
#endif /* SENSORS_H_ */