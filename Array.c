/*
* array.c
*
* If a sensor needs reflective light, then we need to make some contiguous LEDs as light emitters
* The nearby light will reflect off a finger and shine onto the sensor.
*/

#include "p24fxxxx.h"
#include <stdlib.h>
#include "BitDefines.h"
#include "Array.h"

// C supports multi dim arrays as row major order
// array[ROW][COLUMN]
LED const * const RedLedArray[8][8] = {
{&RedLED_R1C1, &RedLED_R1C2, &RedLED_R1C3, &RedLED_R1C4, &RedLED_R1C5, &RedLED_R1C6, &RedLED_R1C7, &RedLED_R1C8},
{&RedLED_R2C1, &RedLED_R2C2, &RedLED_R2C3, &RedLED_R2C4, &RedLED_R2C5, &RedLED_R2C6, &RedLED_R2C7, &RedLED_R2C8},
{&RedLED_R3C1, &RedLED_R3C2, &RedLED_R3C3, &RedLED_R3C4, &RedLED_R3C5, &RedLED_R3C6, &RedLED_R3C7, &RedLED_R3C8},
{&RedLED_R4C1, &RedLED_R4C2, &RedLED_R4C3, &RedLED_R4C4, &RedLED_R4C5, &RedLED_R4C6, &RedLED_R4C7, &RedLED_R4C8},
{&RedLED_R5C1, &RedLED_R5C2, &RedLED_R5C3, &RedLED_R5C4, &RedLED_R5C5, &RedLED_R5C6, &RedLED_R5C7, &RedLED_R5C8},
{&RedLED_R6C1, &RedLED_R6C2, &RedLED_R6C3, &RedLED_R6C4, &RedLED_R6C5, &RedLED_R6C6, &RedLED_R6C7, &RedLED_R6C8},
{&RedLED_R7C1, &RedLED_R7C2, &RedLED_R7C3, &RedLED_R7C4, &RedLED_R7C5, &RedLED_R7C6, &RedLED_R7C7, &RedLED_R7C8},
{&RedLED_R8C1, &RedLED_R8C2, &RedLED_R8C3, &RedLED_R8C4, &RedLED_R8C5, &RedLED_R8C6, &RedLED_R8C7, &RedLED_R8C8}
};

LED const * const GreenLedArray[8][8] = {
{&GreenLED_R1C1, &GreenLED_R1C2, &GreenLED_R1C3, &GreenLED_R1C4, &GreenLED_R1C5, &GreenLED_R1C6, &GreenLED_R1C7, &GreenLED_R1C8},
{&GreenLED_R2C1, &GreenLED_R2C2, &GreenLED_R2C3, &GreenLED_R2C4, &GreenLED_R2C5, &GreenLED_R2C6, &GreenLED_R2C7, &GreenLED_R2C8},
{&GreenLED_R3C1, &GreenLED_R3C2, &GreenLED_R3C3, &GreenLED_R3C4, &GreenLED_R3C5, &GreenLED_R3C6, &GreenLED_R3C7, &GreenLED_R3C8},
{&GreenLED_R4C1, &GreenLED_R4C2, &GreenLED_R4C3, &GreenLED_R4C4, &GreenLED_R4C5, &GreenLED_R4C6, &GreenLED_R4C7, &GreenLED_R4C8},
{&GreenLED_R5C1, &GreenLED_R5C2, &GreenLED_R5C3, &GreenLED_R5C4, &GreenLED_R5C5, &GreenLED_R5C6, &GreenLED_R5C7, &GreenLED_R5C8},
{&GreenLED_R6C1, &GreenLED_R6C2, &GreenLED_R6C3, &GreenLED_R6C4, &GreenLED_R6C5, &GreenLED_R6C6, &GreenLED_R6C7, &GreenLED_R6C8},
{&GreenLED_R7C1, &GreenLED_R7C2, &GreenLED_R7C3, &GreenLED_R7C4, &GreenLED_R7C5, &GreenLED_R7C6, &GreenLED_R7C7, &GreenLED_R7C8},
{&GreenLED_R8C1, &GreenLED_R8C2, &GreenLED_R8C3, &GreenLED_R8C4, &GreenLED_R8C5, &GreenLED_R8C6, &GreenLED_R8C7, &GreenLED_R8C8}
};