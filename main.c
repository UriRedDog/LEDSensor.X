/*
 * Construct the objects at compile time which will place them in
 * FLASH rather than RAM.  This will save valuable RAM space at the expense
 * of a little more code space.
 */
 //#define FCY 32000000UL

#include "p24fxxxx.h"
#include "libpic30.h"
#include "device_fcy.h"
#include "BitDefines.h"
#include "Array.h"
#include "Power.h"

#define __UNIT_TEST 0
#include "UnitTest.h"

void PowerUpTests();
void SampleLedSensors();
void SaveSensorSamples();   
void Initialize();



// JTAG/Code Protect/Write Protect/Clip-on Emulation mode/
// Watchdog Timer/ICD pins select
_CONFIG1(JTAGEN_OFF & GCP_OFF & GWRP_OFF & FWDTEN_OFF & ICS_PGx1)

// Enable CLK switch, Disable CLK monitor, OSCO or Fosc/2, 
// Primary Oscillator Mode: Disabled, Internal Fast RC oscillator
_CONFIG2(FCKSM_CSECMD & OSCIOFNC_ON & POSCMOD_NONE & FNOSC_FRC)

_CONFIG3(SOSCSEL_IO &  WPDIS_WPDIS)

_CONFIG4(RTCOSC_LPRC & DSWDTOSC_LPRC & DSBOREN_OFF & DSWDTEN_OFF)


unsigned int SensorSampleArray[64];


void Initialize(void)
{
    unsigned int i;
    for(i=0;i<64;i++)
        SensorSampleArray[i] = 0;
}

void Execute(void)
{
#if UNIT_TESTS == 1
  RunUnitTests();  
#else
    PowerUpTests();
    while (1)
    {
        SampleLedSensors();
        SaveSensorSamples();   
    }
#endif
}


/*
 * main must set the power switch FET to maintain power after the power button is released.
 */
int main()
{
    //  preset all AN pins as digital.  An ADC object (if used) will reset individual bits 
    AD1PCFG = 0xFFFF;

    // Disable Watch Dog Timer
    RCONbits.SWDTEN = 0;

    // Clock switch to incorporate PLL
    // Initiate Clock Switch to FRC with PLL (NOSC=0b001)
    __builtin_write_OSCCONH(0x01);
    __builtin_write_OSCCONL(0x01); // Start clock switching

    // Wait for Clock switch to occur
    while (OSCCONbits.COSC != 0b001) ;

    // Wait for PLL to lock
    while (OSCCONbits.LOCK != 1) ;

 	PowerManager(POWER_ON);
 
     // Timers defined in ocTimer.h
    //	Timer1.Set(&Timer1, TxCON, 0);
    //	Timer1.Set(&Timer1, TxPERIOD, TIMER1_PERIOD);

    Initialize();
    Execute();

	// just in case we return from execute(), power down
    PowerManager(POWER_OFF);
	while(1)
		;
    return 0;
}

void SaveSensorSamples()
{
    unsigned int row;
    unsigned int column;
    LED const * eachLed;
    for(row=0;row<8;row++)
    {
        for(column=0;column<8;column++)
        {
            eachLed = RedLedArray[row][column];
            SensorSampleArray[(row *8) + column] = eachLed->GetCount(eachLed);
        }
    }
}

// set up all LEDs as light emitters and cycle through all
void PowerUpTests()
{
    unsigned int row;
    unsigned int column;
    LED const * eachLed;
    for(row=0;row<8;row++)
    {
        for(column=0;column<8;column++)
        {
            eachLed = RedLedArray[row][column];
            eachLed->SetMode(eachLed, LED_LIGHT);
            __delay32(30000L);
            eachLed->SetMode(eachLed, LED_NOP);
        }
    }
    for(row=0;row<8;row++)
    {
        for(column=0;column<8;column++)
        {
            eachLed = GreenLedArray[row][column];
            eachLed->SetMode(eachLed, LED_LIGHT);
            __delay32(30000L);
            eachLed->SetMode(eachLed, LED_NOP);
        }
    }
}

// we can sample a column at a time since the column is connected to a common anode
void SampleLedSensors()
{
    unsigned int row;
    unsigned int column;
    LED const * eachLed;
    unsigned int value;
    unsigned int count = 0;

    for(row=0;row<8;row++)
    {
        for(column=0;column<8;column++)
        {
            eachLed = RedLedArray[row][column];
            eachLed->SetMode(eachLed, LED_SENSOR);
        }
        for(column=0;column<8;column++)
        {
            eachLed = RedLedArray[row][column];
            eachLed->SetMode(eachLed, LED_SAMPLE);
        }
/*
        while(count++ < 0x4000)
        {
            value = 0;
            for(column=0;column<8;column++)
            {
                eachLed = RedLedArray[row][column];
                value += eachLed->Sample(eachLed, count);
            }
            if (value == 0)
                break;
        }
*/
    }
}
