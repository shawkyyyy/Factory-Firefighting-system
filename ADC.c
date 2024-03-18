
#include "ADC.h"





U32_t volatile G_ADC = 0; // We put in it the value of ADC READ [Volatile sets the value in the memory] Its not static that it can be changed due to several conditions like sensor]

void ADC_F_Init(ENUM_ADC_Vref_Type vref, ENUM_ADC_Prescaler_Type prescaler, ENUM_ADC_Channel_Type channel)
{
	DIO_F_Set_Pin_Dir(CHANNEL_PORT, channel, INPUT); // input floating
	
	/*setting the reference voltage*/
	switch (vref)
	{
		case ADC_AREF:
		CLR_BIT(ADMUX, REFS1);
		CLR_BIT(ADMUX, REFS0);
		break;
		case ADC_VCC:
		CLR_BIT(ADMUX, REFS1);
		SET_BIT(ADMUX, REFS0);
		break;
		case ADC_V256:
		SET_BIT(ADMUX, REFS1);
		SET_BIT(ADMUX, REFS0);
		break;
		
		default:
		break;
	}


	/*setting the prescaler*/
	ADCSRA &= 0xF8; //3 bits must be cleared before setting the wanted value
	ADCSRA |= prescaler; // very true if we use here switch of if condition

	/*adjust the read to the right*/
	CLR_BIT(ADMUX, ADLAR);

	/*enable the ADC*/ // must be at the end of the peripheral configuration
	SET_BIT(ADCSRA, ADEN);
	
	/*enable the interrupt*/
	SET_BIT(ADCSRA, ADIE);
	
	/*enable the global interrupt*/
	SET_BIT(SREG, 7);

}


U16_t ADC_F_Read(ENUM_ADC_Channel_Type channel )
{
	U16_t adc = 0;
	
	/*select the input channel channel*/
	ADMUX &= 0b11100000;
	ADMUX |= channel;
	
	/*start the conversion*/
	SET_BIT(ADCSRA, ADSC); // busy wait
	while(GET_BIT(ADCSRA, ADSC)); //busy flag
	
	adc = ADCL | ((U16_t)ADCH<<8);
	return adc;
}


void ADC_F_Start_Conversion(ENUM_ADC_Channel_Type channel )
{
	
	/*select the input channel channel*/
	ADMUX &= 0b11100000;
	ADMUX |= channel;
	
	/*start the conversion*/
	SET_BIT(ADCSRA, ADSC); // busy wait
}


ISR(ADC_vect)
{
	G_ADC = ADCL | (U16_t)ADCH<<8;
	ADC_F_Start_Conversion(ADC_CHANNEL_1);
}



