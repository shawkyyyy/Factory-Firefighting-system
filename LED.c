


#include "DIO.h"
#include "LED.h"





void LED_F_INIT(void)
{
	DIO_F_Set_Pin_Dir(LED_0_port,LED_0_pin,OUTPUT);
	DIO_F_Set_Pin_Dir(LED_1_port,LED_1_pin,OUTPUT);
	DIO_F_Set_Pin_Dir(LED_2_port,LED_2_pin,OUTPUT);

	
}

void LED_F_SET_STATE(U8_t led_number,U8_t state)
{
	switch(led_number)
	{
		case LED_0:
		DIO_F_Set_Pin_Val(LED_0_port , LED_0_pin , state);
		break;
		
		case LED_1:
		DIO_F_Set_Pin_Val(LED_1_port , LED_1_pin , state);
		break;
		
		case LED_2:
		DIO_F_Set_Pin_Val(LED_2_port , LED_2_pin , state);
		break;
		
		default:
		break;
	}
}