#include "DIO_Interface.h"


void DIO_InitPin(DIO_Pin_Type pin , DIO_PinStatus_Type status)
{
	u8 pin_num = pin % 8 ;
	DIO_Port_Type port = pin / 8 ;
	
	switch(status)
	{
		case OUTPUT :
		switch(port)
		{
			case PA : 
			SET_BIT(DDRA,pin_num) ;
			break;
			case PB :
			SET_BIT(DDRB,pin_num) ;
			break;
			case PC :
			SET_BIT(DDRC,pin_num) ;
			break;
			case PD :
			SET_BIT(DDRD,pin_num) ;
			break;
		}
		break ;
		
		case INFREE :
		switch(port)
		{
			case PA :
			CLR_BIT(DDRA,pin_num) ;
			break;
			case PB :
			CLR_BIT(DDRB,pin_num) ;
			break;
			case PC :
			CLR_BIT(DDRC,pin_num) ;
			break;
			case PD :
			CLR_BIT(DDRD,pin_num) ;
			break;
		}
		break ;
		
		case INPULLUP :
		switch(port)
		{
			case PA :
			CLR_BIT(DDRA ,pin_num) ;
			SET_BIT(PORTA,pin_num) ;
			break;
			case PB :
			CLR_BIT(DDRB ,pin_num) ;
			SET_BIT(PORTB,pin_num) ;
			break;
			case PC :
			CLR_BIT(DDRC ,pin_num) ;
			SET_BIT(PORTC,pin_num) ;
			break;
			case PD :
			CLR_BIT(DDRD ,pin_num) ;
			SET_BIT(PORTD,pin_num) ;
			break;
		}
		break;
	}
}


void DIO_WritePin(DIO_Pin_Type pin , DIO_Voltage_Type volt)
{
	u8 pin_num = pin % 8 ;
	DIO_Port_Type port = pin / 8 ;
	
	switch(volt)
	{
		case LOW :
		switch(port)
		{
			case PA :
			CLR_BIT(PORTA,pin_num) ;
			break;
			case PB :
			CLR_BIT(PORTB,pin_num) ;
			break;
			case PC :
			CLR_BIT(PORTC,pin_num) ;
			break;
			case PD :
			CLR_BIT(PORTD,pin_num) ;
			break;
		}
		break;
		
		case HIGH :
		switch(port)
		{
			case PA :
			SET_BIT(PORTA,pin_num) ;
			break;
			case PB :
			SET_BIT(PORTB,pin_num) ;
			break; 
			case PC :
			SET_BIT(PORTC,pin_num) ;
			break;
			case PD :
			SET_BIT(PORTD,pin_num) ;
			break;
		}
		break;
	}
}


DIO_Voltage_Type DIO_ReadPin(DIO_Pin_Type pin)
{
	DIO_Voltage_Type volt =0 ;
	
	u8 pin_num = pin % 8 ;
	DIO_Port_Type port = pin / 8 ;
	
	switch(port)
	{
		case PA :
		volt = READ_BIT(PINA,pin_num) ;
		break ;
		case PB :
		volt = READ_BIT(PINB,pin_num) ;
		break ;
		case PC :
		volt = READ_BIT(PINC,pin_num) ;
		break ;
		case PD :
		volt = READ_BIT(PIND,pin_num) ;
		break ;
	}
	return volt ;
}


void DIO_TogglePin(DIO_Pin_Type pin) 
{
	u8 pin_num = pin % 8 ;
	DIO_Port_Type port = pin / 8 ;
	
	switch(port)
	{
		case PA:
		TOG_BIT(PORTA,pin_num) ;
		break; 
		case PB:
		TOG_BIT(PORTB,pin_num) ;
		break;
		case PC:
		TOG_BIT(PORTC,pin_num) ;
		break;
		case PD:
		TOG_BIT(PORTD,pin_num) ;
		break;
	}
}


void DIO_WritePort(DIO_Port_Type port , u8 value) 
{
	switch(port)
	{
		case PA :
		PORTA = value ;
		break; 
		case PB :
		PORTB = value ;
		break;
		case PC :
		PORTC = value ;
		break;
		case PD :
		PORTD = value ;
		break;
	}
}


u8   DIO_ReadPort (DIO_Port_Type port)
{
	u8 value=0 ;
	switch(port)
	{
		case PA :
		value = PORTA ;
		break; 
		case PB :
		value = PORTB ;
		break;
		case PC :
		value = PORTC ;
		break;
		case PD :
		value = PORTD ;
		break;
	}
	return value ;
}




void DIO_Init(void)
{
	DIO_Pin_Type pin ;
	for(pin=PINA0 ; pin < TOTAL_PINS ; pin++)
	{
		DIO_InitPin(pin,PinsStatus[pin]) ;
	}
}
