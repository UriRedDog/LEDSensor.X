/*
* PIN.c
*
* create global PIN structures using compile time constructors
* The InitNewPIN is called to set TRIS and ADPCFG registers since
* this cannot be accomplished in the compile time constructors.
*/
#include "p24fxxxx.h"
#include <stdlib.h>
#include "BitDefines.h"
#include "Pin.h"
#include "UnitTest.h"

static PIN_STATE Get(PIN const *This)
{
  return (*(This->mpLat-1) & This->mMask) ? PIN_HIGH : PIN_LOW;
}

static void Set(PIN const *This, PIN_STATE newState)
{
  if(newState == PIN_HIGH)
    *This->mpLat |= This->mMask;
  if(newState == PIN_LOW)
    *This->mpLat &= ~This->mMask;
  // we could assert if the newState is not valid, but we will do nothing
}

static void SetMode(PIN const *This, PIN_MODE newMode)
{
  if(newMode == PIN_OUTPUT)
     *(This->mpLat -2) &= ~This->mMask;  // set the TRIS to configure pin as an output
  if(newMode == PIN_INPUT)
      *(This->mpLat -2) |= This->mMask;  // set the TRIS to configure pin as an input
  // we could assert if the newMode is not valid, but we will do nothing
}

// compile time constructors
// in test mode we use PORTB because it is easy to write tests
// B[15-8] are common cathodes
// B[7-0] are anodes

#if __UNIT_TEST == 1
PIN const Cathode1 = {BIT15, &LATB, SetMode, Set, Get};
PIN const Cathode2 = {BIT14, &LATB, SetMode, Set, Get};
PIN const Cathode3 = {BIT13, &LATB, SetMode, Set, Get};
PIN const Cathode4 = {BIT12, &LATB, SetMode, Set, Get};
PIN const Cathode5 = {BIT11, &LATB, SetMode, Set, Get};
PIN const Cathode6 = {BIT10, &LATB, SetMode, Set, Get};
PIN const Cathode7 = {BIT9,  &LATB, SetMode, Set, Get};
PIN const Cathode8 = {BIT8,  &LATB, SetMode, Set, Get};

PIN const Anode1 = {BIT7,  &LATB, SetMode, Set, Get};
PIN const Anode2 = {BIT6,  &LATB, SetMode, Set, Get};
PIN const Anode3 = {BIT5,  &LATB, SetMode, Set, Get};
PIN const Anode4 = {BIT4,  &LATB, SetMode, Set, Get};
PIN const Anode5 = {BIT3,  &LATB, SetMode, Set, Get};
PIN const Anode6 = {BIT2,  &LATB, SetMode, Set, Get};
PIN const Anode7 = {BIT1,  &LATB, SetMode, Set, Get};
PIN const Anode8 = {BIT0,  &LATB, SetMode, Set, Get};

#else  // Real Hardware

PIN const RedCathode1 = {BIT0,  &LATC, SetMode, Set, Get};
PIN const RedCathode2 = {BIT2,  &LATC, SetMode, Set, Get};
PIN const RedCathode3 = {BIT1,  &LATC, SetMode, Set, Get};
PIN const RedCathode4 = {BIT8,  &LATA, SetMode, Set, Get};
PIN const RedCathode5 = {BIT4,  &LATC, SetMode, Set, Get};
PIN const RedCathode6 = {BIT5,  &LATC, SetMode, Set, Get};
PIN const RedCathode7 = {BIT9,  &LATA, SetMode, Set, Get};
PIN const RedCathode8 = {BIT3,  &LATC, SetMode, Set, Get};


PIN const Anode1 = {BIT7,  &LATA, SetMode, Set, Get};
PIN const Anode2 = {BIT10, &LATA, SetMode, Set, Get};
PIN const Anode3 = {BIT12, &LATB, SetMode, Set, Get};
PIN const Anode4 = {BIT8, &LATC, SetMode, Set, Get};
PIN const Anode5 = {BIT2,  &LATB, SetMode, Set, Get};
PIN const Anode6 = {BIT3,  &LATB, SetMode, Set, Get};
PIN const Anode7 = {BIT15, &LATB, SetMode, Set, Get};
PIN const Anode8 = {BIT14, &LATB, SetMode, Set, Get};

PIN const GreenCathode1 = {BIT11,  &LATB, SetMode, Set, Get};
PIN const GreenCathode2 = {BIT10,  &LATB, SetMode, Set, Get};
PIN const GreenCathode3 = {BIT9,  &LATC, SetMode, Set, Get};
PIN const GreenCathode4 = {BIT7,  &LATC, SetMode, Set, Get};
PIN const GreenCathode5 = {BIT9,  &LATB, SetMode, Set, Get};
PIN const GreenCathode6 = {BIT8,  &LATB, SetMode, Set, Get};
PIN const GreenCathode7 = {BIT7,  &LATB, SetMode, Set, Get};
PIN const GreenCathode8 = {BIT6,  &LATB, SetMode, Set, Get};

#endif

PIN const PowerPin = {BIT6, &LATC, SetMode, Set, Get};