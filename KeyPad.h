


#ifndef KEYPAD_H_
#define KeyPAD_PORT

#include "DIO.h"

#define KeyPad_D1  PIN_0
#define KeyPad_D2  PIN_1
#define KeyPad_D3  PIN_2
#define KeyPad_D4  PIN_3
#define KeyPad_D5  PIN_4
#define KeyPad_D6  PIN_5
#define KeyPad_D7  PIN_6
#define KeyPad_D8  PIN_7

#define KeyPad_PORT  PD





void KeyPad_Init(void);
U8_t KeyPad_F_GET_VAL(void);





#endif /* KEYPAD_H_ */