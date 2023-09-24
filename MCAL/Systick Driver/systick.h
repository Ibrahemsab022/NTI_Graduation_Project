/******************************************************************************
 *
 * Module: systick
 *
 * File Name: systick.h
 *
 * Description: Header file for the ARM Systick driver
 *
 * Author: Toka Refaat
 *
 *******************************************************************************/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

#include"STD_TYPES.h"

/*******************************************************************************
 *                                Configurations                               *
 *******************************************************************************/
#define AHB_Div_8   0
#define AHB         1
#define CLKSOURCE AHB_Div_8

/*******************************************************************************
 *                               Registers Definitions                         *
 *******************************************************************************/
#define STK_CTRL  *((volatile u32*)0xE000E010)
#define STK_LOAD  *((volatile u32*)0xE000E014)
#define STK_VAL   *((volatile u32*)0xE000E018)
#define STK_CALIB *((volatile u32*)0xE000E01C)

/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/
void STK_init();
void STK_setBusyWait(u32 no_of_Counts);
void STK_setIntervalSingle(u32 no_of_Counts,void(*pointerTofunction)(void));
void STK_voidSetIntervalPeriodic(u32 no_of_Counts,void(*pointerTofunction)(void));
void STK_getElapsedTime(u32 * elapsedTime);
void STK_getRemainingTime(u32 remainingTime);
void STK_disableTimer(void);

#endif
