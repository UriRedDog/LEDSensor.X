/*
* LED.h
* defines the const LED object structure and member methods
* and LED has an Anode PIN and a Cathode PIN
* the LED can be set as a light emitter,
* or a NOP where both pins are inputs
* or reversed biased to charge the internal capacitance
* or a light sensor which detects the rate of discharge.
*  If set as a sensor, one should call the member function GetCount();
* The sparkfun device is a common cathode and normal light emiting is anode +V to cathode ground.
*/

#ifndef __LED_OBJECT_H_
#define __LED_OBJECT_H_
#include "Pin.h"

typedef enum _LEDSTATE { LED_SENSOR = 0, LED_SAMPLE, LED_LIGHT, LED_NOP } LEDSTATE;
struct _LED;
typedef struct _LED LED;
typedef void (*L_SetMode)(LED const * This, LEDSTATE newState);
typedef unsigned int (*L_GetCount)(LED const * This);
typedef unsigned int (*L_Sample)(LED const * This, unsigned int count);

struct _LED
{
    PIN const *cathode;
    PIN const *anode;
    L_SetMode SetMode;
    L_GetCount GetCount;
    L_Sample Sample;
    unsigned int * count;
};


extern LED const RedLED_R1C1;
extern LED const RedLED_R1C2;
extern LED const RedLED_R1C3;
extern LED const RedLED_R1C4;
extern LED const RedLED_R1C5;
extern LED const RedLED_R1C6;
extern LED const RedLED_R1C7;
extern LED const RedLED_R1C8;

extern LED const RedLED_R2C1;
extern LED const RedLED_R2C2;
extern LED const RedLED_R2C3;
extern LED const RedLED_R2C4;
extern LED const RedLED_R2C5;
extern LED const RedLED_R2C6;
extern LED const RedLED_R2C7;
extern LED const RedLED_R2C8;

extern LED const RedLED_R3C1;
extern LED const RedLED_R3C2;
extern LED const RedLED_R3C3;
extern LED const RedLED_R3C4;
extern LED const RedLED_R3C5;
extern LED const RedLED_R3C6;
extern LED const RedLED_R3C7;
extern LED const RedLED_R3C8;

extern LED const RedLED_R4C1;
extern LED const RedLED_R4C2;
extern LED const RedLED_R4C3;
extern LED const RedLED_R4C4;
extern LED const RedLED_R4C5;
extern LED const RedLED_R4C6;
extern LED const RedLED_R4C7;
extern LED const RedLED_R4C8;

extern LED const RedLED_R5C1;
extern LED const RedLED_R5C2;
extern LED const RedLED_R5C3;
extern LED const RedLED_R5C4;
extern LED const RedLED_R5C5;
extern LED const RedLED_R5C6;
extern LED const RedLED_R5C7;
extern LED const RedLED_R5C8;

extern LED const RedLED_R6C1;
extern LED const RedLED_R6C2;
extern LED const RedLED_R6C3;
extern LED const RedLED_R6C4;
extern LED const RedLED_R6C5;
extern LED const RedLED_R6C6;
extern LED const RedLED_R6C7;
extern LED const RedLED_R6C8;

extern LED const RedLED_R7C1;
extern LED const RedLED_R7C2;
extern LED const RedLED_R7C3;
extern LED const RedLED_R7C4;
extern LED const RedLED_R7C5;
extern LED const RedLED_R7C6;
extern LED const RedLED_R7C7;
extern LED const RedLED_R7C8;

extern LED const RedLED_R8C1;
extern LED const RedLED_R8C2;
extern LED const RedLED_R8C3;
extern LED const RedLED_R8C4;
extern LED const RedLED_R8C5;
extern LED const RedLED_R8C6;
extern LED const RedLED_R8C7;
extern LED const RedLED_R8C8;

extern LED const GreenLED_R1C1;
extern LED const GreenLED_R1C2;
extern LED const GreenLED_R1C3;
extern LED const GreenLED_R1C4;
extern LED const GreenLED_R1C5;
extern LED const GreenLED_R1C6;
extern LED const GreenLED_R1C7;
extern LED const GreenLED_R1C8;

extern LED const GreenLED_R2C1;
extern LED const GreenLED_R2C2;
extern LED const GreenLED_R2C3;
extern LED const GreenLED_R2C4;
extern LED const GreenLED_R2C5;
extern LED const GreenLED_R2C6;
extern LED const GreenLED_R2C7;
extern LED const GreenLED_R2C8;

extern LED const GreenLED_R3C1;
extern LED const GreenLED_R3C2;
extern LED const GreenLED_R3C3;
extern LED const GreenLED_R3C4;
extern LED const GreenLED_R3C5;
extern LED const GreenLED_R3C6;
extern LED const GreenLED_R3C7;
extern LED const GreenLED_R3C8;

extern LED const GreenLED_R4C1;
extern LED const GreenLED_R4C2;
extern LED const GreenLED_R4C3;
extern LED const GreenLED_R4C4;
extern LED const GreenLED_R4C5;
extern LED const GreenLED_R4C6;
extern LED const GreenLED_R4C7;
extern LED const GreenLED_R4C8;

extern LED const GreenLED_R5C1;
extern LED const GreenLED_R5C2;
extern LED const GreenLED_R5C3;
extern LED const GreenLED_R5C4;
extern LED const GreenLED_R5C5;
extern LED const GreenLED_R5C6;
extern LED const GreenLED_R5C7;
extern LED const GreenLED_R5C8;

extern LED const GreenLED_R6C1;
extern LED const GreenLED_R6C2;
extern LED const GreenLED_R6C3;
extern LED const GreenLED_R6C4;
extern LED const GreenLED_R6C5;
extern LED const GreenLED_R6C6;
extern LED const GreenLED_R6C7;
extern LED const GreenLED_R6C8;

extern LED const GreenLED_R7C1;
extern LED const GreenLED_R7C2;
extern LED const GreenLED_R7C3;
extern LED const GreenLED_R7C4;
extern LED const GreenLED_R7C5;
extern LED const GreenLED_R7C6;
extern LED const GreenLED_R7C7;
extern LED const GreenLED_R7C8;

extern LED const GreenLED_R8C1;
extern LED const GreenLED_R8C2;
extern LED const GreenLED_R8C3;
extern LED const GreenLED_R8C4;
extern LED const GreenLED_R8C5;
extern LED const GreenLED_R8C6;
extern LED const GreenLED_R8C7;
extern LED const GreenLED_R8C8;
#endif

