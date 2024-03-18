

#ifndef LED_H_
#define LED_H_

#include "DIO.h"


#define LED_0 0
#define LED_1 1
#define LED_2 2


#define OFF 0
#define ON  1


#define LED_2_port PD
#define LED_2_pin  PIN_3

#define LED_1_port PC
#define LED_1_pin  PIN_7

#define LED_0_port PC
#define LED_0_pin  PIN_2

void LED_F_INIT(void);
void LED_F_SET_STATE(U8_t led_number,U8_t state);



#endif /* LED_H_ */