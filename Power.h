/*
* Power manager include
*/


typedef enum _POWERSTATE
{
  POWER_OFF = 0,
	POWER_ON
} POWERSTATE;


extern void PowerManager(POWERSTATE state);
