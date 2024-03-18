#include "LCD.h"
#include "DIO.h"
#include "ADC.h"
#include "KeyBad.h"



extern U32_t G_ADC ;


int main(void)
{
	LCD_F_Init();
	ADC_F_Init(ADC_VCC,ADC_PRESCALER_128,ADC_CHANNEL_1);
	KeyBad_Init();
	ADC_F_Start_Conversion(ADC_CHANNEL_1);
	
	
	

	
	DIO_F_Set_Pin_Dir(Motor_Port,Motor_Pin,OUTPUT);
	DIO_F_Set_Pin_Dir(Buzzer_Port,Buzzer_Pin,OUTPUT);
	DIO_F_Set_Pin_Dir(LED_0_port,LED_0_pin,OUTPUT);
	
	U32_t temp;
	
	U8_t true_pass[4]={'9','8','9','8'};
	U8_t pass[4];
	U8_t i;   //COUNTER
	
	
	
	while (1)
	{
		
		
		temp = G_ADC*100/1023;
		LCD_F_Go_To(0,8);
		LCD_F_Write_Number(temp);
		LCD_F_Write_String("   ");
		
		if (temp < 45)
		{
			LCD_F_Go_To(0,0);
			LCD_F_Write_String("Temp :");
			LCD_F_Go_To(1,0);
			LCD_F_Write_String("Mode :");
			LCD_F_Go_To(1,8);
			LCD_F_Write_String("Normal");
			DIO_F_Set_Pin_Val(Motor_Port,Motor_Pin,LOW);
			DIO_F_Set_Pin_Val(Buzzer_Port,Buzzer_Pin,LOW);
			DIO_F_Set_Pin_Val(LED_0_port,LED_0_pin,LOW);
		}
		
		
		
		
		else if(temp >= 47  & temp <= 85)
		{
			LCD_F_Go_To(0,0);
			LCD_F_Write_String("Temp :");
			LCD_F_Go_To(1,0);
			LCD_F_Write_String("Mode :");
			LCD_F_Go_To(1,8);
			LCD_F_Write_String("Hot     ");
			
			DIO_F_Set_Pin_Val(Motor_Port,Motor_Pin,LOW);
			DIO_F_Set_Pin_Val(Buzzer_Port,Buzzer_Pin,HIGH);
			DIO_F_Set_Pin_Val(LED_0_port,LED_0_pin,HIGH);
			_delay_ms(500);
			DIO_F_Set_Pin_Val(LED_0_port,LED_0_pin,LOW);
			DIO_F_Set_Pin_Val(Buzzer_Port,Buzzer_Pin,LOW);
			_delay_ms(500);
		}
		

		
		else if (temp >= 87 & temp <= 100)
		{
			LCD_F_Go_To(0,0);
			LCD_F_Write_String("Temp :");
			LCD_F_Go_To(1,0);
			LCD_F_Write_String("Mode :");
			LCD_F_Go_To(1,8);
			LCD_F_Write_String("Fire     ");
			
			DIO_F_Set_Pin_Val(Buzzer_Port,Buzzer_Pin,HIGH);
			DIO_F_Set_Pin_Val(Motor_Port,Motor_Pin,HIGH);
			DIO_F_Set_Pin_Val(LED_0_port,LED_0_pin,HIGH);
			_delay_ms(2000);
			
			
			
			
			
			while (pass[0]!=true_pass[0] |  pass[1]!=true_pass[1]  |  pass[2]!=true_pass[2] |  pass[3]!=true_pass[3])
			{
				LCD_F_Go_To(0,0);
				LCD_F_Write_String("Enter Pass :");
				LCD_F_Go_To(1,0);
				LCD_F_Write_String("               ");
				LCD_F_Go_To(1,0);
				
				
				
				for(i=0;i<=3;i++)
				{
					pass[i]=KeyBad_F_GET_VAL();
					LCD_F_Write_Char('*');
					LCD_F_Go_To(1,i+1);
					while(pass[i]==KeyBad_F_GET_VAL());
				}
				if (pass[0]!=true_pass[0] |  pass[1]!=true_pass[1]  |  pass[2]!=true_pass[2] |  pass[3]!=true_pass[3])
				{
					LCD_F_Go_To_Clear(1,0);
					LCD_F_Go_To_Clear(1,1);
					LCD_F_Go_To_Clear(1,2);
					LCD_F_Go_To_Clear(1,3);
					LCD_F_Go_To(1,0);
					LCD_F_Write_String("wrong");
					_delay_ms(1000);
					LCD_F_Go_To_Clear(1,0);
					LCD_F_Go_To_Clear(1,1);
					LCD_F_Go_To_Clear(1,2);
					LCD_F_Go_To_Clear(1,3);
					LCD_F_Go_To_Clear(1,4);
				}
				
				LCD_F_Go_To(0,0);
				LCD_F_Write_String("               ");
				LCD_F_Go_To(1,0);
				LCD_F_Write_String("               ");
				
				
			}
			pass[0]='0';
			pass[1]='0';
			pass[2]='0';
			pass[3]='0';
		}
		
	}
	
}