/******************************************************************************
 *
 * Module: systick
 *
 * File Name: systick.c
 *
 * Description: Source file for the ARM Systick driver
 *
 * Author: Toka Refaat
 *
 *******************************************************************************/

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "systick.h"

/*******************************************************************************
 *                               Global Variables                              *
 *******************************************************************************/

void(* Globle_pointerTofunction)(void)= NULL;
u8 Globle_single_Flag=0;

/*******************************************************************************
 *                            Functions Definitions                            *
 *******************************************************************************/
void STK_init()
{
	/*Disable timer*/
	CLR_BIT(STK_CTRL,0);
	/*Disable Init*/
	CLR_BIT(STK_CTRL,1);
	/*Select prescaler*/
#if(CLKSOURCE==AHB_Div_8)
	CLR_BIT(STK_CTRL,2);

#elif(CLKSOURCE==AHB)
	SET_BIT(STK_CTRL,2);

#endif
}

void STK_setBusyWait(u32 no_of_Counts)
{
	/*Disable Init*/
	CLR_BIT(STK_CTRL,1);
	/*LOAD counter value*/
	STK_LOAD = 0x00FFFFFF & no_of_Counts;
	/*Enable Timer*/
	SET_BIT(STK_CTRL,0);
	/*wait on flag*/
	while (!GET_BIT(STK_CTRL,16));
	STK_disableTimer();
}

void STK_setIntervalSingle(u32 no_of_Counts,void(*pointerTofunction)(void))
{
	Globle_pointerTofunction= pointerTofunction;
	/*Enable Init*/
	SET_BIT(STK_CTRL,1);
	/*LOAD counter value*/
	STK_LOAD=0x00FFFFFF & no_of_Counts;
	/*Enable timer*/
	SET_BIT(STK_CTRL,0);
	//set Flag:
	Globle_single_Flag=1;
}

void STK_voidSetIntervalPeriodic(u32 no_of_Counts,void(*pointerTofunction)(void))
{
	Globle_pointerTofunction=pointerTofunction;
	/*Enable Init*/
	SET_BIT(STK_CTRL,1);
	/*LOAD counter value*/
	STK_LOAD = 0x00FFFFFF & no_of_Counts;
	/*Enable timer*/
	SET_BIT(STK_CTRL,0);
	//clear flag:
	Globle_single_Flag=0;
}

void STK_getElapsedTime(u32 * elapsedTime)
{
	elapsedTime = STK_LOAD-STK_VAL;
}

void STK_getRemainingTime(u32 remainingTime)
{
	remainingTime = STK_VAL;
}

void STK_disableTimer(void)
{
	/*Disable timer*/
	CLR_BIT(STK_CTRL,0);
	/*Disable Int*/
	CLR_BIT(STK_CTRL,1);
	/*Clr load*/
	STK_LOAD=0x00000000;
	/*Clr vlue*/
	STK_VAL=0x00000000;
}

SysTick_Handler(){

	u8 temp;

	if(Globle_pointerTofunction!=NULL)
	{
		Globle_pointerTofunction();
	}
	//CLear Interp Flag
	temp = GET_BIT(STK_CTRL,16);

	if(Globle_single_Flag==1)
	{
		STK_disableTimer();
		Globle_single_Flag=0;
	}
}
