
#include "Sensors.h"

u16 POT_VoltRead(void)
{
	u16 adc = ADC_Read(POT_CH) ;
	u16 volt = ((u32)5000*adc)/1024 ;
	return volt ;
}



u16 POT_PercRead(void)
{
	u16 adc  = ADC_Read(POT_CH) ;
	u16 perc = ((f32)adc/1024)*100 ;
	return perc ;
}




u16 TEMP_Read(void)
{
	u16 adc = ADC_Read(LM35_CH) ;
	u16 volt = ((u32)5000*adc)/1024 ;
	u16 temp = volt / 10 ;
	return temp ;
}


u16 TEMP_Read2(void)
{
	u16 adc = ADC_Read(LM35_CH) ;
	//u16 volt = ((u32)5000*adc)/1024 ;
	u16 temp = ADC-47 ;
	return temp ;
}


u16 Pressure_Read(void)
{
	u16 adc = ADC_Read(MPX4115_CH); 
	u16 pressure = (((f32)50/471)*(adc-41))+15 ;
	return pressure ;	
}


void DC_Control_PWM()
{
	
}