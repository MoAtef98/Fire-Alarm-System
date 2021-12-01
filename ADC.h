

#ifndef ADC_H_
#define ADC_H_

#include "MemMap.h"
#include "StdTypes.h"
#include "BitMask.h"


#define OK 1 
#define NOT_OK 0 


typedef enum 
{
	VREF_AVCC ,
	VREF_AREF ,
	VREF_256
}ADC_Vref_type;




typedef enum
{
	ADC_SCALER_2 = 1 ,
	ADC_SCALER_4,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128
	
}ADC_Scaler_type;



typedef enum 
{
	CH_0 = 0 ,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7,
}ADC_Chanel_type;



void ADC_Init (ADC_Vref_type vref , ADC_Scaler_type scaler) ;

u16 ADC_Read(ADC_Chanel_type ch) ;

void ADC_StartConversion(ADC_Chanel_type ch) ;

u16 ADC_GetRead(void) ;

u8 ADC_GetReadNoBlock(u16*pdata) ;

#endif /* ADC_H_ */