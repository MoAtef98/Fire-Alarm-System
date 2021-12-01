

#ifndef SENSORS_H_
#define SENSORS_H_


#include "StdTypes.h"
#include "ADC.h"


#define POT_CH  CH_0
#define LM35_CH CH_1
#define MPX4115_CH CH_1
#define DC_Max  500
#define DC_Pin   PINC2

u16 POT_VoltRead(void)  ;
u16 TEMP_Read(void);
u16 POT_PercRead(void);
u16 Pressure_Read(void);
u16 TEMP_Read2(void);
#endif /* SENSORS_H_ */