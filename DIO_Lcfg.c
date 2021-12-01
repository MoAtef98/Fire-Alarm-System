#include "DIO_Interface.h"


const DIO_PinStatus_Type PinsStatus[TOTAL_PINS] = 
{
	INFREE ,          /* PORT A PIN 0  */
	INFREE ,          /* PORT A PIN 1  */
	OUTPUT ,          /* PORT A PIN 2  */
	OUTPUT ,          /* PORT A PIN 3  */
	OUTPUT ,          /* PORT A PIN 4  */
	INFREE ,          /* PORT A PIN 5  */
	OUTPUT ,          /* PORT A PIN 6  */
	INFREE ,          /* PORT A PIN 7  */
	
	OUTPUT ,          /* PORT B PIN 0  */
	OUTPUT ,          /* PORT B PIN 1  */
	OUTPUT ,          /* PORT B PIN 2  */
	OUTPUT ,          /* PORT B PIN 3  */ //OC0
	OUTPUT ,           /* PORT B PIN 4  */
	OUTPUT ,          /* PORT B PIN 5  */
	OUTPUT ,          /* PORT B PIN 6  */
	OUTPUT ,          /* PORT B PIN 7  */
	
	OUTPUT ,          /* PORT C PIN 0  */
	OUTPUT ,          /* PORT C PIN 1  */
	OUTPUT ,          /* PORT C PIN 2  */
	OUTPUT ,          /* PORT C PIN 3  */
	OUTPUT ,          /* PORT C PIN 4  */
	OUTPUT ,          /* PORT C PIN 5  */
	OUTPUT ,          /* PORT C PIN 6  */
	OUTPUT ,          /* PORT C PIN 7  */
	
	OUTPUT ,          /* PORT D PIN 0  */
	OUTPUT ,          /* PORT D PIN 1  INT0*/
	OUTPUT ,          /* PORT D PIN 2  INT0*/
	INPULLUP ,        /* PORT D PIN 3 INT1 */
	OUTPUT ,          /* PORT D PIN 4  */
	OUTPUT ,          /* PORT D PIN 5  */
	INFREE ,          /* PORT D PIN 6  */
	OUTPUT            /* PORT D PIN 7  */
} ;