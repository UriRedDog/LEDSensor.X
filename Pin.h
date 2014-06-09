/*
* Pin.h
* defines the const Pin object structure and member methods
*/
#ifndef __PIN_OBJECT_H_
#define __PIN_OBJECT_H_

typedef enum _PIN_MODE { PIN_OUTPUT = 0, PIN_INPUT } PIN_MODE;
typedef enum _PIN_STATE { PIN_LOW = 0, PIN_HIGH } PIN_STATE;
struct _PIN;
typedef struct _PIN PIN; 
typedef void (*P_SetMode)(PIN const * This, PIN_MODE newMode);
typedef PIN_STATE (*P_Get)(PIN const * This);
typedef void (*P_Set)(PIN const * This, PIN_STATE newState);

struct _PIN {
  unsigned int mMask;
  volatile unsigned int *mpLat;
  P_SetMode SetMode;
  P_Set Set;
  P_Get Get;
};




extern PIN const Anode1;
extern PIN const Anode2 ;
extern PIN const Anode3;
extern PIN const Anode4;
extern PIN const Anode5;
extern PIN const Anode6;
extern PIN const Anode7;
extern PIN const Anode8;

extern PIN const RedCathode1;
extern PIN const RedCathode2;
extern PIN const RedCathode3;
extern PIN const RedCathode4;
extern PIN const RedCathode5;
extern PIN const RedCathode6;
extern PIN const RedCathode7;
extern PIN const RedCathode8;

extern PIN const GreenCathode1;
extern PIN const GreenCathode2;
extern PIN const GreenCathode3;
extern PIN const GreenCathode4;
extern PIN const GreenCathode5;
extern PIN const GreenCathode6;
extern PIN const GreenCathode7;
extern PIN const GreenCathode8;

extern PIN const PowerPin;
#endif

