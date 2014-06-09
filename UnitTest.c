/*
* UnitTest.c
*
* unit tests for all the components
* normally one would place each component unit test into an individual file, but
* this application is small enough that all the componenets can be tested in
* a single file.
*
* the unit test is only run in the simulator.  It should not be run on hardware since
* Pin constructors are different
*
* we could use assert.h but it needs a heap and we would rather not have to change
* the build configuration.  We will just stay in a tight loop if a test fails.
*/

#include "p24fxxxx.h"
#include <stdlib.h>
#include "BitDefines.h"
#include "Array.h"

#if __UNIT_TEST == 1

// these are global so we can see them in a Watch Window
// Well that is a big fail.  The debugger totally barfs on the variables.
// the code works as expected, but the debugger is clueless.
int row, column;
PIN const * testAnode;
PIN const * testRedCathode;
LED const * testLed;




void SetAllAnodesAsInputs()
{
    TRISB = 0;
    Anode1.SetMode(&Anode1, PIN_INPUT);
    Anode2.SetMode(&Anode2, PIN_INPUT);
    Anode3.SetMode(&Anode3, PIN_INPUT);
    Anode4.SetMode(&Anode4, PIN_INPUT);
    Anode5.SetMode(&Anode5, PIN_INPUT);
    Anode6.SetMode(&Anode6, PIN_INPUT);
    Anode7.SetMode(&Anode7, PIN_INPUT);
    Anode8.SetMode(&Anode8, PIN_INPUT);
    if( TRISB == 0xFF)
        return;
    while(1)
        ;
}
        
void SetAllRedCathodesAsInputs()
{
    TRISB = 0;
    RedCathode1.SetMode(&RedCathode1, PIN_INPUT);
    RedCathode2.SetMode(&RedCathode2, PIN_INPUT);
    RedCathode3.SetMode(&RedCathode3, PIN_INPUT);
    RedCathode4.SetMode(&RedCathode4, PIN_INPUT);
    RedCathode5.SetMode(&RedCathode5, PIN_INPUT);
    RedCathode6.SetMode(&RedCathode6, PIN_INPUT);
    RedCathode7.SetMode(&RedCathode7, PIN_INPUT);
    RedCathode8.SetMode(&RedCathode8, PIN_INPUT);
    if (TRISB == 0xFF00)
        return;
    while(1)
        ;
}
    
void SetAllAnodesLow()
{
    LATB = 0xffff;
    Anode1.Set(&Anode1, PIN_LOW);
    Anode2.Set(&Anode2, PIN_LOW);
    Anode3.Set(&Anode3, PIN_LOW);
    Anode4.Set(&Anode4, PIN_LOW);
    Anode5.Set(&Anode5, PIN_LOW);
    Anode6.Set(&Anode6, PIN_LOW);
    Anode7.Set(&Anode7, PIN_LOW);
    Anode8.Set(&Anode8, PIN_LOW);
    if(LATB == 0xff00)
        return;
    while(1)
        ;
}

void SetAllAnodesHigh()
{
    LATB = 0;
    Anode1.Set(&Anode1, PIN_HIGH);
    Anode2.Set(&Anode2, PIN_HIGH);
    Anode3.Set(&Anode3, PIN_HIGH);
    Anode4.Set(&Anode4, PIN_HIGH);
    Anode5.Set(&Anode5, PIN_HIGH);
    Anode6.Set(&Anode6, PIN_HIGH);
    Anode7.Set(&Anode7, PIN_HIGH);
    Anode8.Set(&Anode8, PIN_HIGH);
    if(LATB == 0xff)
        return;
    while(1)
        ;
}

void SetAllRedCathodesLow()
{
    LATB = 0xffff;
    RedCathode1.Set(&RedCathode1, PIN_LOW);
    RedCathode2.Set(&RedCathode2, PIN_LOW);
    RedCathode3.Set(&RedCathode3, PIN_LOW);
    RedCathode4.Set(&RedCathode4, PIN_LOW);
    RedCathode5.Set(&RedCathode5, PIN_LOW);
    RedCathode6.Set(&RedCathode6, PIN_LOW);
    RedCathode7.Set(&RedCathode7, PIN_LOW);
    RedCathode8.Set(&RedCathode8, PIN_LOW);
    if(LATB == 0x00FF)
        return;
    while(1)
        ;
}

void SetAllRedCathodesHigh()
{
    LATB = 0;
    RedCathode1.Set(&RedCathode1, PIN_HIGH);
    RedCathode2.Set(&RedCathode2, PIN_HIGH);
    RedCathode3.Set(&RedCathode3, PIN_HIGH);
    RedCathode4.Set(&RedCathode4, PIN_HIGH);
    RedCathode5.Set(&RedCathode5, PIN_HIGH);
    RedCathode6.Set(&RedCathode6, PIN_HIGH);
    RedCathode7.Set(&RedCathode7, PIN_HIGH);
    RedCathode8.Set(&RedCathode8, PIN_HIGH);
    if(LATB == 0xFF00)
        return;
    while(1)
        ;
}
    

void SetAllAnodesAsOutputs()
{
    TRISB = 0xffff;
    Anode1.SetMode(&Anode1, PIN_OUTPUT);
    Anode2.SetMode(&Anode2, PIN_OUTPUT);
    Anode3.SetMode(&Anode3, PIN_OUTPUT);
    Anode4.SetMode(&Anode4, PIN_OUTPUT);
    Anode5.SetMode(&Anode5, PIN_OUTPUT);
    Anode6.SetMode(&Anode6, PIN_OUTPUT);
    Anode7.SetMode(&Anode7, PIN_OUTPUT);
    Anode8.SetMode(&Anode8, PIN_OUTPUT);
    if(TRISB == 0xFF00)
        return;
    while(1)
        ;
}

void SetAllRedCathodesAsOutputs()
{
    TRISB = 0xffff;
    RedCathode1.SetMode(&RedCathode1, PIN_OUTPUT);
    RedCathode2.SetMode(&RedCathode2, PIN_OUTPUT);
    RedCathode3.SetMode(&RedCathode3, PIN_OUTPUT);
    RedCathode4.SetMode(&RedCathode4, PIN_OUTPUT);
    RedCathode5.SetMode(&RedCathode5, PIN_OUTPUT);
    RedCathode6.SetMode(&RedCathode6, PIN_OUTPUT);
    RedCathode7.SetMode(&RedCathode7, PIN_OUTPUT);
    RedCathode8.SetMode(&RedCathode8, PIN_OUTPUT);
    if(TRISB == 0x00FF)
        return;
    while(1)
        ;
}

void TestAllPins()
{
    SetAllAnodesAsInputs();
    SetAllRedCathodesAsInputs();
    SetAllAnodesLow();
    SetAllRedCathodesLow();
    SetAllAnodesHigh();
    SetAllRedCathodesHigh();
    SetAllAnodesAsOutputs();
    SetAllRedCathodesAsOutputs();
}

void TestLedAsNops()
{
    TRISB = 0;
    LATB = 0;
    for(row=0;row<8;row++)
    {    
        for(column=0;column<8;column++)
        {
            testLed = LedArray[row][column];
            testLed->SetMode(testLed, LED_NOP);
        }
    }    
}

void TestLedAsSensor()
{
    TRISB = 0;
    LATB = 0;
    const LED * testLed;
    for(row=0;row<8;row++)
    {    
        for(column=0;column<8;column++)
        {
            testLed = LedArray[row][column];
            testLed->SetMode(testLed, LED_SENSOR);
        }
    }    
}

void TestLedAsLights()
{
    TRISB = 0;
    LATB = 0;
    for(row=0;row<8;row++)
    {
        for(column=0;column<8;column++)
        {
            testLed = LedArray[row][column];
            testLed->SetMode(testLed, LED_LIGHT);
        }
    }           
}

void RunUnitTests()
{
  TestAllPins();
  TestLedAsLights();
  TestLedAsNops();
  TestLedAsSensor();
}

#endif
