
#include "LCD.h"

#ifndef LCD_MODE
#define LCD_MODE _8_BIT 
#endif


#if(LCD_MODE == _8_BIT) 

void LCD_WriteCommand (u8 command)
{
		DIO_WritePin(RW,LOW) ;
		DIO_WritePin(RS,LOW) ;
		DIO_WritePort(LCD_PORT,command) ;
		DIO_WritePin(EN,HIGH) ;
		_delay_ms(1) ;
		DIO_WritePin(EN,LOW) ;
		_delay_ms(1) ;
}


void LCD_WriteData  (u8 data)
{
		DIO_WritePin(RW,LOW) ;
		DIO_WritePin(RS,HIGH) ;
		DIO_WritePort(LCD_PORT, data) ;
		DIO_WritePin(EN,HIGH) ;
		_delay_ms(1) ;
		DIO_WritePin(EN,LOW) ;
		_delay_ms(1) ;
}




void LCD_Init(void)
{
		_delay_ms(50) ;
		LCD_WriteCommand(0x38) ;  //8 bit mode , 2 lines , 5*7 font 
		_delay_ms(1) ;
		LCD_WriteCommand(0x0c) ;  // screen , cursor , 0x0e ,0x0c 0x0f
		_delay_ms(1) ;
		LCD_WriteCommand(0x01) ;  // clear dispaly
		_delay_ms(2) ;
		LCD_WriteCommand(0x06) ;  // increase DDRAM adress
		_delay_ms(1) ;
}

#elif(LCD_MODE == _4_BIT)

 void LCD_WriteCommand (u8 command)
{
		DIO_WritePin(RW,LOW) ;
		DIO_WritePin(RS,LOW) ;
		
		DIO_WritePin(D4 , READ_BIT(command,4)) ;
		DIO_WritePin(D5 , READ_BIT(command,5)) ;
		DIO_WritePin(D6 , READ_BIT(command,6)) ;
		DIO_WritePin(D7 , READ_BIT(command,7)) ;
		
		DIO_WritePin(EN,HIGH) ;
		_delay_ms(1) ;
		DIO_WritePin(EN,LOW) ;
		_delay_ms(1) ;
		
		DIO_WritePin(D4 , READ_BIT(command,0)) ;
		DIO_WritePin(D5 , READ_BIT(command,1)) ;
		DIO_WritePin(D6 , READ_BIT(command,2)) ;
		DIO_WritePin(D7 , READ_BIT(command,3)) ;
		
		DIO_WritePin(EN,HIGH) ;
		_delay_ms(1) ;
		DIO_WritePin(EN,LOW) ;
		_delay_ms(1) ;
}



void LCD_WriteData  (u8 data)
{
		DIO_WritePin(RW,LOW) ;
		DIO_WritePin(RS,HIGH) ;
		
		
		DIO_WritePin(D4 , READ_BIT(data,4)) ;
		DIO_WritePin(D5 , READ_BIT(data,5)) ;
		DIO_WritePin(D6 , READ_BIT(data,6)) ;
		DIO_WritePin(D7 , READ_BIT(data,7)) ;
		
		DIO_WritePin(EN,HIGH) ;
		_delay_ms(1) ;
		DIO_WritePin(EN,LOW) ;
		_delay_ms(1) ;
		
		DIO_WritePin(D4 , READ_BIT(data,0)) ;
		DIO_WritePin(D5 , READ_BIT(data,1)) ;
		DIO_WritePin(D6 , READ_BIT(data,2)) ;
		DIO_WritePin(D7 , READ_BIT(data,3)) ;
		
		DIO_WritePin(EN,HIGH) ;
		_delay_ms(1) ;
		DIO_WritePin(EN,LOW) ;
		_delay_ms(1) ;
}

void LCD_Init(void)
{
		_delay_ms(50) ;
		LCD_WriteCommand(0x02) ;
		_delay_ms(1) ;
		LCD_WriteCommand(0x28) ;  // data connection type(4 OR 8 ) & number of lines & size of Font
		_delay_ms(1) ;
		LCD_WriteCommand(0x0c) ;
		_delay_ms(1) ;
		LCD_WriteCommand(0x01) ;
		_delay_ms(2) ;
		LCD_WriteCommand(0x06) ;
		_delay_ms(1) ;
}
#endif
/*************************************************************************************************/


void LCD_WriteChar (u8 ch)  
{
	LCD_WriteData(ch) ;
}



void LCD_WriteString  (u8*str)  
{
	u8 i = 0 ;
	for (i=0 ; str[i]!='\0' ;i++)
	{
		LCD_WriteData(str[i]) ;
	}
}





void LCD_WriteNumber  (s64 num) 
{
	u8 str [16] = {0} ;
	u8 i = 0 , j  ,rem ;
	
	if (num==0)
	{
		LCD_WriteChar('0') ;
	}
	else
	{
		if (num<0)
		{
			num = num*(-1) ;
			LCD_WriteChar('-') ;
		}
		while(num>0)
		{
			rem = num%10;
			str[i] = rem +'0' ;
			num = num/10 ;
			i++;
		}
		for(j=i ; j>0 ; j--)
		{
			LCD_WriteChar(str[j-1]) ;
		}
	}
}





void LCD_Clear (void)
{
	LCD_WriteCommand(0x01) ;
}




void LCD_GoTo(u8 line , u8 x)
{
	if (line==1)
	{
		LCD_WriteCommand(0x80+x) ;
	}
	else if (line==2)
	{
		LCD_WriteCommand(0x80+x+0x40) ;
	}
}





void LCD_CreateChracret (  u8*pattern ,u8 location )
{
	u8 i ;
	
		LCD_WriteCommand(0x40+(location*8));
		for(i=0 ; i<8 ;i++)
		{
			LCD_WriteChar(pattern[i]) ;
		}
}





void LCD_WriteNumberInBinary(u8 num)
{
	s8 i ;
	for (i=7 ; i>=0 ;i--)
	{
		LCD_WriteChar(((num>>i)&1)+'0') ;
	}
}




void LCD_WriteNumberInBinary2(u8 num)
{
	s8 i , flag=0;
	for (i=7 ; i>=0 ;i--)
	{
		if (((num>>i)&1))
		{
			flag=1 ;
		}
		if (flag==1)
		{
			LCD_WriteChar(((num>>i)&1)+'0') ;
		}
	}
}




void LCD_WriteNumber_GoTo (u8 line , u8 x , s64 num)
{
	LCD_GoTo(line , x) ;
	LCD_WriteNumber(num) ;
}




void LCD_WriteNumber_4Digits (u16 num)
{
	LCD_WriteChar(((num%10000)/1000)+'0') ;
	LCD_WriteChar(((num%1000)/100)+'0') ;
	LCD_WriteChar(((num%100)/10)+'0') ;
	LCD_WriteChar(((num%10)/1)+'0') ;
}


static u8 lcd_hex [16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
void LCD_WriteNumberInHex (u8 num) 
{
	s8 rem  ,j, i=0;
	u8 arr [2] = {0} ;
	if (num==0)
	{
		LCD_WriteChar('0') ;
		LCD_WriteChar('0') ;
	}
	else
	{
		while(num>0)
		{
			rem = num%16 ;
			arr[i] = lcd_hex[rem] ;
			num = num/16 ;
			i++ ;
		}
		
	   for(j=i-1 ;j>=0 ;j--)
	   {
		LCD_WriteChar(arr[j]) ;
	   }
	}
}