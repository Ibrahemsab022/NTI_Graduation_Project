/******************************************************************************
 *
 * Module: exti
 *
 * File Name: exti.h
 *
 * Description: Header file for the ARM EXTI driver
 *
 * Author: Toka Refaat
 *
 *******************************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include "STD_TYPES.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define EXTI_SENSE_CONTROL      FALLING_EDGE
#define EXTI_LINE               EXTI_LINE_0

#define FALLING_EDGE            0
#define RISING_EDGE             1
#define ON_CHANGE               2

#define EXTI_LINE_0             0
#define EXTI_LINE_1             1
#define EXTI_LINE_2             2
#define EXTI_LINE_3             3
#define EXTI_LINE_4             4
#define EXTI_LINE_5             5
#define EXTI_LINE_6             6
#define EXTI_LINE_7             7
#define EXTI_LINE_8             8
#define EXTI_LINE_9             9
#define EXTI_LINE_10            10
#define EXTI_LINE_11            11
#define EXTI_LINE_12            12
#define EXTI_LINE_13            13
#define EXTI_LINE_14            14
#define EXTI_LINE_15            15

/*Source Input for EXTIx*/
#define EXTI_PA                 0
#define EXTI_PB                 1
#define EXTI_PC                 2

/*******************************************************************************
 *                               Registers Definitions                         *
 *******************************************************************************/
//EXTI BASEADDRESS --> 0x40013C00
typedef struct
{
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;
}EXTI_t;

#define EXTI        ((volatile EXTI_t*)0x40013C00)

typedef struct
{
    volatile u32 MEMRMP;
    volatile u32 PMC;
    volatile u32 EXTICR1;
    volatile u32 EXTICR2;
    volatile u32 EXTICR3;
    volatile u32 EXTICR4;
    volatile u32 CMPCR;
}SYSCFG_t;

#define SYSCFG      ((volatile SYSCFG_t*)0x40013800)

/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/
void EXTI_init();
void EXTI_setExtiLineEnable(u8 lineId);
void EXTI_setExtiLineDisable(u8 lineId);
void EXTI_setSenseControl(u8 senseControl, u8 lineId);
void EXTI_setEXTIpinConfig(u8 portId, u8 lineId);

#endif
