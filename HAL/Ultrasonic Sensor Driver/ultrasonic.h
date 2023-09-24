#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

/* Configuration of the using TIMER */
#define ULTRA_TIMER    TIM2

/* Configuration of the using CHNNEL */
#define ULTRA_CHANNEL  CHANNEL4

/*************************************************************************************************************************************
* Function Name         : UltraSonic_voidInit                                                                                        *
* Input Parameters(in)  : None                                                                                                       *
* Output Parameter(out) : None                                                                                                       *
* Return value          : None                                                                                                       *
* Functionality         : Intitiazation of Ultrasonic (Timer-Channel-Trigger and Echo Pins)                                          *
**************************************************************************************************************************************/
void UltraSonic_voidInit(void);
/*************************************************************************************************************************************
* Function Name         : UltraSonic_floatGetDistance                                                                                *
* Input Parameters(in)  : None                                                                                                       *
* Output Parameter(out) : None                                                                                                       *
* Return value          : None                                                                                                       *
* Functionality         : Getting the distance to the object in cm                                                                   *
**************************************************************************************************************************************/
float UltraSonic_floatGetDistance(void);


#endif
