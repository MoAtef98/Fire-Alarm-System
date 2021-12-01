 
#include "ADC.h"

static u8 read_flag = 0 ;

void ADC_Init (ADC_Vref_type vref , ADC_Scaler_type scaler) 
{
	//VREF
	switch(vref)
	{    
		case VREF_AVCC : 
		SET_BIT(ADMUX,REFS0) ;
		CLR_BIT(ADMUX,REFS1) ;
		break;
		case VREF_AREF :
		CLR_BIT(ADMUX,REFS0) ;
		CLR_BIT(ADMUX,REFS1) ;
		break;
		case VREF_256 :
		SET_BIT(ADMUX,REFS0) ;
		SET_BIT(ADMUX,REFS1) ;
		break;
	}
	
	//clock
	
	ADCSRA = ADCSRA & 0xf8   ;
	scaler = scaler & 0x07   ;
	ADCSRA = ADCSRA | scaler ;
	
	//read adjust right 
	CLR_BIT(ADMUX , ADLAR) ;

	//Enable
	SET_BIT(ADCSRA,ADEN) ; // u can make it as function or last thing in init
	
}



u16 ADC_Read(ADC_Chanel_type ch) 
{
	static u16 x ;
	//select channel
	ADMUX = ADMUX & 0XE0 ;
	ADMUX = ADMUX | ch ;
	
	// start conversion 
	SET_BIT(ADCSRA,ADSC) ;
	while(READ_BIT(ADCSRA,ADSC)) ; //polling until adc end conversion 
	
	// u16 adc = ADCL | ((u16)ADCH<<8)
	return ADC ; // another way by MemMap
}




void ADC_StartConversion(ADC_Chanel_type ch)
{
	if (read_flag = 0 )
	{
		//select channel
		ADMUX = ADMUX & 0XE0 ;
		ADMUX = ADMUX | ch ;
		
		// start conversion
		SET_BIT(ADCSRA,ADSC) ;
		read_flag =1 ;
	}
}


u16 ADC_GetRead(void)
{
	while(READ_BIT(ADCSRA,ADSC)) ; //polling (busy wait) until adc end conversion
	// u16 adc = ADCL | ((u16)ADCH<<8)
	read_flag = 0 ;
	return ADC ; // another way by MemMap	
}




u8 ADC_GetReadNoBlock(u16*pdata)
{
	if(!READ_BIT(ADCSRA,ADSC))  //polling (periodic check) until adc end conversion
	{
		*pdata = ADC ;
		read_flag = 0 ;
		return OK ;
	}
	else
	{
		return NOT_OK ;
	}
	
}