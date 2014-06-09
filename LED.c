/*
* LED.c
*
* create global LED structures using compile time constructors
*
* puting the LED into Sensor mode is a blocking call.
* this may be acceptable given the leakage current of a specific LED package.  
* If not, then perhaps we can use Interrupt on Change
* and a timer for the count.  This may allow all the LEDs to be placed into sensor mode
* at the same time.  Many will have the same value given the large size of the LED array.
*
* Low ambient light conditions are a challange.  We have to provide some light to sense the light.
* One method may be to light adjacent LED while sensing another.
* simplest method may be to light a row or column and sense adjacent row/column
* No more than one LED will be a light source at a time.   
*/
#include "p24fxxxx.h"
#include <stdlib.h>
#include "BitDefines.h"
#include "LED.h"

#define COUNT_LIMIT 0x8000


static void SetMode(LED const *This, LEDSTATE newState)
{
    unsigned int count = 0;
    PIN const * cathode = This->cathode;
    PIN const * anode = This->anode;

    switch(newState)
    {
    case LED_LIGHT :
        anode->Set(anode, PIN_LOW);
        anode->SetMode(anode, PIN_OUTPUT);
        cathode->Set(cathode, PIN_HIGH);
        cathode->SetMode(cathode, PIN_OUTPUT);  
        break;
        
    case LED_NOP :
        anode->SetMode(anode, PIN_INPUT);
        cathode->SetMode(cathode, PIN_INPUT);
        break;
    
    case LED_SAMPLE:
        anode->SetMode(anode, PIN_INPUT);
        while(anode->Get(anode) != PIN_LOW && count < COUNT_LIMIT)
           count++;
        *(This->count) = count;
        break;

    case LED_SENSOR:
        {

            cathode->Set(cathode, PIN_LOW);
            cathode->SetMode(cathode, PIN_OUTPUT);
            anode->Set(anode, PIN_HIGH);
            anode->SetMode(anode, PIN_OUTPUT);
 //           for(count = 0; count < 50; count++)
//            Nop();
//            count = 0;
//            anode->SetMode(anode, PIN_INPUT);
    
//            while(anode->Get(anode) != PIN_LOW && count < COUNT_LIMIT)
//                count++;
//            *(This->count) = count;
        }
        break;
    }
}

static unsigned int Sample(LED const *This, unsigned int count)
{
    PIN const * anode = This->anode;
    if(anode->Get(anode) != PIN_LOW && count < COUNT_LIMIT)
    {
        *(This->count) = count;
        return 0;
    }
    else
        return count;
}

static unsigned int GetCount(LED const *This)
{
  return *(This->count);
}

// the count is stored in one of 64 unsigned ints in this array
// the array is not visable to other compilation units
// one must use the accessor function to get the count
#ifdef __DEBUG
unsigned int RedArrayCount[64];
unsigned int GreenArrayCount[64];
#else
static unsigned int RedArrayCount[64];
static unsigned int GreenArrayCount[64];
#endif

// rows are anodes, columns are cathodes
LED const RedLED_R1C1 = {&RedCathode1, &Anode1, SetMode, GetCount, Sample, &RedArrayCount[0] };
LED const RedLED_R1C2 = {&RedCathode2, &Anode1, SetMode, GetCount, Sample, &RedArrayCount[1] };
LED const RedLED_R1C3 = {&RedCathode3, &Anode1, SetMode, GetCount, Sample, &RedArrayCount[2] };
LED const RedLED_R1C4 = {&RedCathode4, &Anode1, SetMode, GetCount, Sample, &RedArrayCount[3] };
LED const RedLED_R1C5 = {&RedCathode5, &Anode1, SetMode, GetCount, Sample, &RedArrayCount[4] };
LED const RedLED_R1C6 = {&RedCathode6, &Anode1, SetMode, GetCount, Sample, &RedArrayCount[5] };
LED const RedLED_R1C7 = {&RedCathode7, &Anode1, SetMode, GetCount, Sample, &RedArrayCount[6] };
LED const RedLED_R1C8 = {&RedCathode8, &Anode1, SetMode, GetCount, Sample, &RedArrayCount[7] };

LED const RedLED_R2C1 = {&RedCathode1, &Anode2, SetMode, GetCount, Sample, &RedArrayCount[8] };
LED const RedLED_R2C2 = {&RedCathode2, &Anode2, SetMode, GetCount, Sample, &RedArrayCount[9] };
LED const RedLED_R2C3 = {&RedCathode3, &Anode2, SetMode, GetCount, Sample, &RedArrayCount[10] };
LED const RedLED_R2C4 = {&RedCathode4, &Anode2, SetMode, GetCount, Sample, &RedArrayCount[11] };
LED const RedLED_R2C5 = {&RedCathode5, &Anode2, SetMode, GetCount, Sample, &RedArrayCount[12] };
LED const RedLED_R2C6 = {&RedCathode6, &Anode2, SetMode, GetCount, Sample, &RedArrayCount[13] };
LED const RedLED_R2C7 = {&RedCathode7, &Anode2, SetMode, GetCount, Sample, &RedArrayCount[14] };
LED const RedLED_R2C8 = {&RedCathode8, &Anode2, SetMode, GetCount, Sample, &RedArrayCount[15] };

LED const RedLED_R3C1 = {&RedCathode1, &Anode3, SetMode, GetCount, Sample, &RedArrayCount[16] };
LED const RedLED_R3C2 = {&RedCathode2, &Anode3, SetMode, GetCount, Sample, &RedArrayCount[17] };
LED const RedLED_R3C3 = {&RedCathode3, &Anode3, SetMode, GetCount, Sample, &RedArrayCount[18] };
LED const RedLED_R3C4 = {&RedCathode4, &Anode3, SetMode, GetCount, Sample, &RedArrayCount[19] };
LED const RedLED_R3C5 = {&RedCathode5, &Anode3, SetMode, GetCount, Sample, &RedArrayCount[20] };
LED const RedLED_R3C6 = {&RedCathode6, &Anode3, SetMode, GetCount, Sample, &RedArrayCount[21] };
LED const RedLED_R3C7 = {&RedCathode7, &Anode3, SetMode, GetCount, Sample, &RedArrayCount[22] };
LED const RedLED_R3C8 = {&RedCathode8, &Anode3, SetMode, GetCount, Sample, &RedArrayCount[23] };

LED const RedLED_R4C1 = {&RedCathode1, &Anode4, SetMode, GetCount, Sample, &RedArrayCount[24] };
LED const RedLED_R4C2 = {&RedCathode2, &Anode4, SetMode, GetCount, Sample, &RedArrayCount[25] };
LED const RedLED_R4C3 = {&RedCathode3, &Anode4, SetMode, GetCount, Sample, &RedArrayCount[26] };
LED const RedLED_R4C4 = {&RedCathode4, &Anode4, SetMode, GetCount, Sample, &RedArrayCount[27] };
LED const RedLED_R4C5 = {&RedCathode5, &Anode4, SetMode, GetCount, Sample, &RedArrayCount[28] };
LED const RedLED_R4C6 = {&RedCathode6, &Anode4, SetMode, GetCount, Sample, &RedArrayCount[29] };
LED const RedLED_R4C7 = {&RedCathode7, &Anode4, SetMode, GetCount, Sample, &RedArrayCount[30] };
LED const RedLED_R4C8 = {&RedCathode8, &Anode4, SetMode, GetCount, Sample, &RedArrayCount[31] };

LED const RedLED_R5C1 = {&RedCathode1, &Anode5, SetMode, GetCount, Sample, &RedArrayCount[32] };
LED const RedLED_R5C2 = {&RedCathode2, &Anode5, SetMode, GetCount, Sample, &RedArrayCount[33] };
LED const RedLED_R5C3 = {&RedCathode3, &Anode5, SetMode, GetCount, Sample, &RedArrayCount[34] };
LED const RedLED_R5C4 = {&RedCathode4, &Anode5, SetMode, GetCount, Sample, &RedArrayCount[35] };
LED const RedLED_R5C5 = {&RedCathode5, &Anode5, SetMode, GetCount, Sample, &RedArrayCount[36] };
LED const RedLED_R5C6 = {&RedCathode6, &Anode5, SetMode, GetCount, Sample, &RedArrayCount[37] };
LED const RedLED_R5C7 = {&RedCathode7, &Anode5, SetMode, GetCount, Sample, &RedArrayCount[38] };
LED const RedLED_R5C8 = {&RedCathode8, &Anode5, SetMode, GetCount, Sample, &RedArrayCount[39] };

LED const RedLED_R6C1 = {&RedCathode1, &Anode6, SetMode, GetCount, Sample, &RedArrayCount[40] };
LED const RedLED_R6C2 = {&RedCathode3, &Anode6, SetMode, GetCount, Sample, &RedArrayCount[41] };
LED const RedLED_R6C3 = {&RedCathode3, &Anode6, SetMode, GetCount, Sample, &RedArrayCount[42] };
LED const RedLED_R6C4 = {&RedCathode4, &Anode6, SetMode, GetCount, Sample, &RedArrayCount[43] };
LED const RedLED_R6C5 = {&RedCathode5, &Anode6, SetMode, GetCount, Sample, &RedArrayCount[44] };
LED const RedLED_R6C6 = {&RedCathode6, &Anode6, SetMode, GetCount, Sample, &RedArrayCount[45] };
LED const RedLED_R6C7 = {&RedCathode7, &Anode6, SetMode, GetCount, Sample, &RedArrayCount[46] };
LED const RedLED_R6C8 = {&RedCathode8, &Anode6, SetMode, GetCount, Sample, &RedArrayCount[47] };

LED const RedLED_R7C1 = {&RedCathode1, &Anode7, SetMode, GetCount, Sample, &RedArrayCount[48] };
LED const RedLED_R7C2 = {&RedCathode2, &Anode7, SetMode, GetCount, Sample, &RedArrayCount[49] };
LED const RedLED_R7C3 = {&RedCathode3, &Anode7, SetMode, GetCount, Sample, &RedArrayCount[50] };
LED const RedLED_R7C4 = {&RedCathode4, &Anode7, SetMode, GetCount, Sample, &RedArrayCount[51] };
LED const RedLED_R7C5 = {&RedCathode5, &Anode7, SetMode, GetCount, Sample, &RedArrayCount[52] };
LED const RedLED_R7C6 = {&RedCathode6, &Anode7, SetMode, GetCount, Sample, &RedArrayCount[53] };
LED const RedLED_R7C7 = {&RedCathode7, &Anode7, SetMode, GetCount, Sample, &RedArrayCount[54] };
LED const RedLED_R7C8 = {&RedCathode8, &Anode7, SetMode, GetCount, Sample, &RedArrayCount[55] };

LED const RedLED_R8C1 = {&RedCathode1, &Anode8, SetMode, GetCount, Sample, &RedArrayCount[56] };
LED const RedLED_R8C2 = {&RedCathode2, &Anode8, SetMode, GetCount, Sample, &RedArrayCount[57] };
LED const RedLED_R8C3 = {&RedCathode3, &Anode8, SetMode, GetCount, Sample, &RedArrayCount[58] };
LED const RedLED_R8C4 = {&RedCathode4, &Anode8, SetMode, GetCount, Sample, &RedArrayCount[59] };
LED const RedLED_R8C5 = {&RedCathode5, &Anode8, SetMode, GetCount, Sample, &RedArrayCount[60] };
LED const RedLED_R8C6 = {&RedCathode6, &Anode8, SetMode, GetCount, Sample, &RedArrayCount[61] };
LED const RedLED_R8C7 = {&RedCathode7, &Anode8, SetMode, GetCount, Sample, &RedArrayCount[62] };
LED const RedLED_R8C8 = {&RedCathode8, &Anode8, SetMode, GetCount, Sample, &RedArrayCount[63] };




LED const GreenLED_R1C1 = {&GreenCathode1, &Anode1, SetMode, GetCount, Sample, &GreenArrayCount[0] };
LED const GreenLED_R1C2 = {&GreenCathode2, &Anode1, SetMode, GetCount, Sample, &GreenArrayCount[1] };
LED const GreenLED_R1C3 = {&GreenCathode3, &Anode1, SetMode, GetCount, Sample, &GreenArrayCount[2] };
LED const GreenLED_R1C4 = {&GreenCathode4, &Anode1, SetMode, GetCount, Sample, &GreenArrayCount[3] };
LED const GreenLED_R1C5 = {&GreenCathode5, &Anode1, SetMode, GetCount, Sample, &GreenArrayCount[4] };
LED const GreenLED_R1C6 = {&GreenCathode6, &Anode1, SetMode, GetCount, Sample, &GreenArrayCount[5] };
LED const GreenLED_R1C7 = {&GreenCathode7, &Anode1, SetMode, GetCount, Sample, &GreenArrayCount[6] };
LED const GreenLED_R1C8 = {&GreenCathode8, &Anode1, SetMode, GetCount, Sample, &GreenArrayCount[7] };

LED const GreenLED_R2C1 = {&GreenCathode1, &Anode2, SetMode, GetCount, Sample, &GreenArrayCount[8] };
LED const GreenLED_R2C2 = {&GreenCathode2, &Anode2, SetMode, GetCount, Sample, &GreenArrayCount[9] };
LED const GreenLED_R2C3 = {&GreenCathode3, &Anode2, SetMode, GetCount, Sample, &GreenArrayCount[10] };
LED const GreenLED_R2C4 = {&GreenCathode4, &Anode2, SetMode, GetCount, Sample, &GreenArrayCount[11] };
LED const GreenLED_R2C5 = {&GreenCathode5, &Anode2, SetMode, GetCount, Sample, &GreenArrayCount[12] };
LED const GreenLED_R2C6 = {&GreenCathode6, &Anode2, SetMode, GetCount, Sample, &GreenArrayCount[13] };
LED const GreenLED_R2C7 = {&GreenCathode7, &Anode2, SetMode, GetCount, Sample, &GreenArrayCount[14] };
LED const GreenLED_R2C8 = {&GreenCathode8, &Anode2, SetMode, GetCount, Sample, &GreenArrayCount[15] };

LED const GreenLED_R3C1 = {&GreenCathode1, &Anode3, SetMode, GetCount, Sample, &GreenArrayCount[16] };
LED const GreenLED_R3C2 = {&GreenCathode2, &Anode3, SetMode, GetCount, Sample, &GreenArrayCount[17] };
LED const GreenLED_R3C3 = {&GreenCathode3, &Anode3, SetMode, GetCount, Sample, &GreenArrayCount[18] };
LED const GreenLED_R3C4 = {&GreenCathode4, &Anode3, SetMode, GetCount, Sample, &GreenArrayCount[19] };
LED const GreenLED_R3C5 = {&GreenCathode5, &Anode3, SetMode, GetCount, Sample, &GreenArrayCount[20] };
LED const GreenLED_R3C6 = {&GreenCathode6, &Anode3, SetMode, GetCount, Sample, &GreenArrayCount[21] };
LED const GreenLED_R3C7 = {&GreenCathode7, &Anode3, SetMode, GetCount, Sample, &GreenArrayCount[22] };
LED const GreenLED_R3C8 = {&GreenCathode8, &Anode3, SetMode, GetCount, Sample, &GreenArrayCount[23] };

LED const GreenLED_R4C1 = {&GreenCathode1, &Anode4, SetMode, GetCount, Sample, &GreenArrayCount[24] };
LED const GreenLED_R4C2 = {&GreenCathode2, &Anode4, SetMode, GetCount, Sample, &GreenArrayCount[25] };
LED const GreenLED_R4C3 = {&GreenCathode3, &Anode4, SetMode, GetCount, Sample, &GreenArrayCount[26] };
LED const GreenLED_R4C4 = {&GreenCathode4, &Anode4, SetMode, GetCount, Sample, &GreenArrayCount[27] };
LED const GreenLED_R4C5 = {&GreenCathode5, &Anode4, SetMode, GetCount, Sample, &GreenArrayCount[28] };
LED const GreenLED_R4C6 = {&GreenCathode6, &Anode4, SetMode, GetCount, Sample, &GreenArrayCount[29] };
LED const GreenLED_R4C7 = {&GreenCathode7, &Anode4, SetMode, GetCount, Sample, &GreenArrayCount[30] };
LED const GreenLED_R4C8 = {&GreenCathode8, &Anode4, SetMode, GetCount, Sample, &GreenArrayCount[31] };

LED const GreenLED_R5C1 = {&GreenCathode1, &Anode5, SetMode, GetCount, Sample, &GreenArrayCount[32] };
LED const GreenLED_R5C2 = {&GreenCathode2, &Anode5, SetMode, GetCount, Sample, &GreenArrayCount[33] };
LED const GreenLED_R5C3 = {&GreenCathode3, &Anode5, SetMode, GetCount, Sample, &GreenArrayCount[34] };
LED const GreenLED_R5C4 = {&GreenCathode4, &Anode5, SetMode, GetCount, Sample, &GreenArrayCount[35] };
LED const GreenLED_R5C5 = {&GreenCathode5, &Anode5, SetMode, GetCount, Sample, &GreenArrayCount[36] };
LED const GreenLED_R5C6 = {&GreenCathode6, &Anode5, SetMode, GetCount, Sample, &GreenArrayCount[37] };
LED const GreenLED_R5C7 = {&GreenCathode7, &Anode5, SetMode, GetCount, Sample, &GreenArrayCount[38] };
LED const GreenLED_R5C8 = {&GreenCathode8, &Anode5, SetMode, GetCount, Sample, &GreenArrayCount[39] };

LED const GreenLED_R6C1 = {&GreenCathode1, &Anode6, SetMode, GetCount, Sample, &GreenArrayCount[40] };
LED const GreenLED_R6C2 = {&GreenCathode3, &Anode6, SetMode, GetCount, Sample, &GreenArrayCount[41] };
LED const GreenLED_R6C3 = {&GreenCathode3, &Anode6, SetMode, GetCount, Sample, &GreenArrayCount[42] };
LED const GreenLED_R6C4 = {&GreenCathode4, &Anode6, SetMode, GetCount, Sample, &GreenArrayCount[43] };
LED const GreenLED_R6C5 = {&GreenCathode5, &Anode6, SetMode, GetCount, Sample, &GreenArrayCount[44] };
LED const GreenLED_R6C6 = {&GreenCathode6, &Anode6, SetMode, GetCount, Sample, &GreenArrayCount[45] };
LED const GreenLED_R6C7 = {&GreenCathode7, &Anode6, SetMode, GetCount, Sample, &GreenArrayCount[46] };
LED const GreenLED_R6C8 = {&GreenCathode8, &Anode6, SetMode, GetCount, Sample, &GreenArrayCount[47] };

LED const GreenLED_R7C1 = {&GreenCathode1, &Anode7, SetMode, GetCount, Sample, &GreenArrayCount[48] };
LED const GreenLED_R7C2 = {&GreenCathode2, &Anode7, SetMode, GetCount, Sample, &GreenArrayCount[49] };
LED const GreenLED_R7C3 = {&GreenCathode3, &Anode7, SetMode, GetCount, Sample, &GreenArrayCount[50] };
LED const GreenLED_R7C4 = {&GreenCathode4, &Anode7, SetMode, GetCount, Sample, &GreenArrayCount[51] };
LED const GreenLED_R7C5 = {&GreenCathode5, &Anode7, SetMode, GetCount, Sample, &GreenArrayCount[52] };
LED const GreenLED_R7C6 = {&GreenCathode6, &Anode7, SetMode, GetCount, Sample, &GreenArrayCount[53] };
LED const GreenLED_R7C7 = {&GreenCathode7, &Anode7, SetMode, GetCount, Sample, &GreenArrayCount[54] };
LED const GreenLED_R7C8 = {&GreenCathode8, &Anode7, SetMode, GetCount, Sample, &GreenArrayCount[55] };

LED const GreenLED_R8C1 = {&GreenCathode1, &Anode8, SetMode, GetCount, Sample, &GreenArrayCount[56] };
LED const GreenLED_R8C2 = {&GreenCathode2, &Anode8, SetMode, GetCount, Sample, &GreenArrayCount[57] };
LED const GreenLED_R8C3 = {&GreenCathode3, &Anode8, SetMode, GetCount, Sample, &GreenArrayCount[58] };
LED const GreenLED_R8C4 = {&GreenCathode4, &Anode8, SetMode, GetCount, Sample, &GreenArrayCount[59] };
LED const GreenLED_R8C5 = {&GreenCathode5, &Anode8, SetMode, GetCount, Sample, &GreenArrayCount[60] };
LED const GreenLED_R8C6 = {&GreenCathode6, &Anode8, SetMode, GetCount, Sample, &GreenArrayCount[61] };
LED const GreenLED_R8C7 = {&GreenCathode7, &Anode8, SetMode, GetCount, Sample, &GreenArrayCount[62] };
LED const GreenLED_R8C8 = {&GreenCathode8, &Anode8, SetMode, GetCount, Sample, &GreenArrayCount[63] };
