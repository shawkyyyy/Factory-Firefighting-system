

#include "KeyPad.h"


void KeyPad_Init(void)
{
	
	DIO_F_Set_Pin_Dir(KeyPad_PORT,KeyPad_D1,OUTPUT);
	DIO_F_Set_Pin_Dir(KeyPad_PORT,KeyPad_D2,OUTPUT);
	DIO_F_Set_Pin_Dir(KeyPad_PORT,KeyPad_D3,OUTPUT);
	DIO_F_Set_Pin_Dir(KeyPad_PORT,KeyPad_D4,OUTPUT);
	

	DIO_F_Set_Pin_Dir(KeyPad_PORT,KeyPad_D5,INPUT);
	DIO_F_Set_Pin_Dir(KeyPad_PORT,KeyPad_D6,INPUT);
	DIO_F_Set_Pin_Dir(KeyPad_PORT,KeyPad_D7,INPUT);
	DIO_F_Set_Pin_Dir(KeyPad_PORT,KeyPad_D8,INPUT);
	
	DIO_F_Set_Pin_Val(KeyPad_PORT,KeyPad_D5,HIGH);
	DIO_F_Set_Pin_Val(KeyPad_PORT,KeyPad_D6,HIGH);
	DIO_F_Set_Pin_Val(KeyPad_PORT,KeyPad_D7,HIGH);
	DIO_F_Set_Pin_Val(KeyPad_PORT,KeyPad_D8,HIGH);
	
	
}


/*************************************************/





U8_t KeyPad_F_GET_VAL(void)
{
	
	while(1)
	{				
		DIO_F_Set_Pin_Val(KeyPad_PORT,KeyPad_D1,LOW);
		DIO_F_Set_Pin_Val(KeyPad_PORT,KeyPad_D2,HIGH);
		DIO_F_Set_Pin_Val(KeyPad_PORT,KeyPad_D3,HIGH);
		DIO_F_Set_Pin_Val(KeyPad_PORT,KeyPad_D4,HIGH);
		
		if (DIO_F_Get_Pin_Val(KeyPad_PORT ,KeyPad_D5)==0)
		{
			return '7';
		}
		else if (DIO_F_Get_Pin_Val(KeyPad_PORT,KeyPad_D6)==0)
		{
			return '8';
		}
		else if (DIO_F_Get_Pin_Val(KeyPad_PORT,KeyPad_D7)==0)
		{
			return '9';
		}
		else if (DIO_F_Get_Pin_Val(KeyPad_PORT,KeyPad_D8)==0)
		{
			return 'C';
		}
		DIO_F_Set_Pin_Val(KeyPad_PORT,KeyPad_D1,HIGH);
		DIO_F_Set_Pin_Val(KeyPad_PORT,KeyPad_D2,LOW);
		DIO_F_Set_Pin_Val(KeyPad_PORT,KeyPad_D3,HIGH);
		DIO_F_Set_Pin_Val(KeyPad_PORT,KeyPad_D4,HIGH);
		if (DIO_F_Get_Pin_Val(KeyPad_PORT,KeyPad_D5)==0)
		{
			return '4';
		}
		else if (DIO_F_Get_Pin_Val(KeyPad_PORT,KeyPad_D6)==0)
		{
			return '5';
		}
		else if (DIO_F_Get_Pin_Val(KeyPad_PORT,KeyPad_D7)==0)
		{
			return '6';
		}
		else if (DIO_F_Get_Pin_Val(KeyPad_PORT,KeyPad_D8)==0)
		{
			return 'B';
		}
		DIO_F_Set_Pin_Val(KeyPad_PORT,KeyPad_D1,HIGH);
		DIO_F_Set_Pin_Val(KeyPad_PORT,KeyPad_D2,HIGH);
		DIO_F_Set_Pin_Val(KeyPad_PORT,KeyPad_D3,LOW);
		DIO_F_Set_Pin_Val(KeyPad_PORT,KeyPad_D4,HIGH);
		if (DIO_F_Get_Pin_Val(KeyPad_PORT,KeyPad_D5)==0)
		{
			return '1';
		}
		else if (DIO_F_Get_Pin_Val(KeyPad_PORT,KeyPad_D6)==0)
		{
			return '2';
		}
		else if (DIO_F_Get_Pin_Val(KeyPad_PORT,KeyPad_D7)==0)
		{
			return '3';
		}
		else if (DIO_F_Get_Pin_Val(KeyPad_PORT,KeyPad_D8)==0)
		{
			return 'A';
		}
		DIO_F_Set_Pin_Val(KeyPad_PORT,KeyPad_D1,HIGH);
		DIO_F_Set_Pin_Val(KeyPad_PORT,KeyPad_D2,HIGH);
		DIO_F_Set_Pin_Val(KeyPad_PORT,KeyPad_D3,HIGH);
		DIO_F_Set_Pin_Val(KeyPad_PORT,KeyPad_D4,LOW);
		if (DIO_F_Get_Pin_Val(KeyPad_PORT,KeyPad_D5)==0)
		{
			return '*';
		}
		else if (DIO_F_Get_Pin_Val(KeyPad_PORT,KeyPad_D6)==0)
		{
			return '0';
		}
		else if (DIO_F_Get_Pin_Val(KeyPad_PORT,KeyPad_D7)==0)
		{
			return '#';
		}
		else if (DIO_F_Get_Pin_Val(KeyPad_PORT,KeyPad_D8)==0)
		
		{
			return 'D';
		}		
	}
}

