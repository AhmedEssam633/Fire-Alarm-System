/*
 * KeyPad_cfg.h
 *
 * Created: 2/22/2023 10:06:36 PM
 *  Author: Ahmed Essam
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#define  COLS   4
#define  ROWS   4

#ifdef KEYPAD_C

const static u8 KeysArray[ROWS][COLS]=  {{'7','8','9','/'},
{'4','5','6','*'},
{'1','2','3','-'},
{'c','0','=','+'}};
#endif
#define  NO_KEY   'T'

#define  FIRST_OUTPUT PIND0
#define  FIRST_INPUT  PIND4


#endif /* KEYPAD_CFG_H_ */