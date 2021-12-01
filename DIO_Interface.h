
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "StdTypes.h"
#include "MemMap.h"
#include "BitMask.h"


typedef enum 
{
	PINA0=0,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS
}DIO_Pin_Type;


typedef enum
{
	OUTPUT=0 ,
	INFREE ,
	INPULLUP
	
}DIO_PinStatus_Type;

typedef enum 
{
	PA=0 ,
	PB   ,
	PC   ,
	PD
}DIO_Port_Type;

typedef enum 
{
	LOW=0 ,
	HIGH,
}DIO_Voltage_Type;

extern const DIO_PinStatus_Type PinsStatus[TOTAL_PINS] ;

extern void DIO_InitPin  (DIO_Pin_Type pin  , DIO_PinStatus_Type status) ;
extern void DIO_WritePin (DIO_Pin_Type pin  , DIO_Voltage_Type volt)         ;
extern DIO_Voltage_Type DIO_ReadPin(DIO_Pin_Type pin) ;
extern void DIO_TogglePin(DIO_Pin_Type pin) ;
extern void DIO_WritePort(DIO_Port_Type port , u8 value) ;
extern u8   DIO_ReadPort (DIO_Port_Type port);
extern void DIO_Init(void) ;


#endif /* DIO_INTERFACE_H_ */