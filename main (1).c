


#include "LCD.h"
#include "DIO.h"
#include "ADC.h"
#include "KeyPad.h"

#define Buzzer_Port    PA
#define Buzzer_Pin    PIN_3
#define Motor_Port    PC
#define Motor_Pin    PIN_7


extern U32_t G_ADC ; // calling global value in ADC
 
U32_t temp; // int + long = 4*8 = 32

U8_t real_pass[4]={'1','2','3','4'}; // 8 BYTE (CHAR)
U8_t pass[4]; 
U8_t i;   //COUNTER
void passwordrequired()
{
	LCD_F_Go_To(0,0);
	LCD_F_Write_String("Enter Pass :");
	LCD_F_Go_To(1,0);
	LCD_F_Write_String("               ");
	LCD_F_Go_To(1,0);
	
	for(i=0;i<=3;i++)
	{
		pass[i]=KeyPad_F_GET_VAL();
		LCD_F_Write_Char('*');
		LCD_F_Go_To(1,i+1);
		while(pass[i]==KeyPad_F_GET_VAL()); // while is for " as long as im pressing, take value" ;
	}
	
	if(comparepassword(real_pass,pass))
	{
		LCD_F_Go_To(0,0);
		LCD_F_Write_String("               ");
		LCD_F_Go_To(1,0);
		LCD_F_Write_String("               ");
	}
	else
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
}

int comparepassword(int array[],int array2[])
{
	for (int i = 0 ; i < 4 ; i++)
	{
		if(array[i] == array2[i])
		{
			return 1;
			
		}
		else
		{
			return 0;
		}
	}
}


int main(void)
{
	LCD_F_Init();
	ADC_F_Init(ADC_VCC,ADC_PRESCALER_128,ADC_CHANNEL_1); // 128 IS THE RANGE WE'RE USING
	KeyPad_Init();
	ADC_F_Start_Conversion(ADC_CHANNEL_1);
	
	
	

	
	DIO_F_Set_Pin_Dir(Motor_Port,Motor_Pin,OUTPUT);
	DIO_F_Set_Pin_Dir(Buzzer_Port,Buzzer_Pin,OUTPUT);
	
	
	
	
	
	
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
		
			_delay_ms(500);
			
			DIO_F_Set_Pin_Val(Buzzer_Port,Buzzer_Pin,LOW);
			_delay_ms(500);
		}
		

		
		else if (temp >= 95 & temp <= 100)
		{
			LCD_F_Go_To(0,0);
			LCD_F_Write_String("Temp :");
			LCD_F_Go_To(1,0);
			LCD_F_Write_String("Mode :");
			LCD_F_Go_To(1,8);
			LCD_F_Write_String("Fire     ");
			
			DIO_F_Set_Pin_Val(Buzzer_Port,Buzzer_Pin,HIGH);
			DIO_F_Set_Pin_Val(Motor_Port,Motor_Pin,HIGH);
	
			_delay_ms(2000);
			
			
			
			passwordrequired();
		
		}
		
	}
	
}