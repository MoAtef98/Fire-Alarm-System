#define F_CPU 8000000UL 
#include <util/delay.h>
#include"MemMap.h"
#include"ADC.h"
#include"DIO_Interface.h"
#include"StdTypes.h"
#include"LCD.h"
#include"Sensors.h"
#include"BitMask.h"

int main(void)
{
	u16  temp=0 , Smoke=0;
	DIO_Init();
	LCD_Init();
	ADC_Init(VREF_AVCC , ADC_SCALER_64);
	
	LCD_GoTo(1,5);
	LCD_WriteString("Fine");
	
	LCD_GoTo(2,0);
	LCD_WriteString("Temp : ");
	
	
	while(1)
	{
		
		temp = TEMP_Read();
		LCD_GoTo(2,8);
		LCD_WriteNumber_4Digits(temp);
		
		if (temp>50)
		{
			smoke=POT_PercRead();
			if (smoke > 50)
			{
				DIO_WritePin(PIND2,LOW);  //turn off led
				
				LCD_GoTo(1,5);
				LCD_WriteString("Fire");
				DIO_WritePin(PIND0,HIGH);  //turn on pump
				DIO_WritePin(PIND1,HIGH);  //turn on buzzer
			}
			else
			{
				DIO_WritePin(PIND0,LOW);  //turn on pump
				DIO_WritePin(PIND1,LOW);  //turn on buzzer
				
				LCD_GoTo(1,5);
				LCD_WriteString("Heat");
				DIO_WritePin(PIND2,HIGH);//turn on led
			}
		}
		else
		{
			DIO_WritePin(PIND0,LOW);  //turn off pump
			DIO_WritePin(PIND1,LOW);  //turn off buzzer
			DIO_WritePin(PIND2,LOW);  //turn off led
			LCD_GoTo(1,5);
			LCD_WriteString("Fine");
			
		}
	}
	return  0 ;
}

