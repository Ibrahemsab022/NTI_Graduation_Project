/******************************************************************************
 *
 * Module: nvic
 *
 * File Name: nvic.h
 *
 * Description: Header file for the ARM NVIC driver
 *
 * Author: Toka Refaat
 *
 *******************************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

#include "STD_TYPES.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define GROUP4BITS_SUBGROUP0BITS            0b011
#define GROUP3BITS_SUBGROUP1BITS            0b100
#define GROUP2BITS_SUBGROUP2BITS            0b101
#define GROUP1BITS_SUBGROUP3BITS            0b110
#define GROUP0BITS_SUBGROUP4BITS            0b111

/*******************************************************************************
 *                               Registers Definitions                         *
 *******************************************************************************/
//NVIC Base Address is 0xE000E100
typedef struct
{
    volatile u32 ISER[32];   //volatile u32 ISER[8];
    volatile u32 ICER[32];
    volatile u32 ISPR[32];
    volatile u32 ICPR[32];
    volatile u32 IABR[32];
    volatile u32 RES[32];
    //volatile u32 IPR[60];
    volatile u8 IPR[90];
}NVIC_t;


#define NVIC    ((volatile NVIC_t*)0xE000E100)

//SCB Base Address --> 0xE000ED00
typedef struct
{
    volatile u32 CPUID;
    volatile u32 ICSR;
    volatile u32 VTOR;
    volatile u32 AIRCR;
    volatile u32 SCR;
    volatile u32 CCR;
    volatile u32 SHPR[3];
    volatile u32 SHCSR;
    volatile u32 CFSR;
    volatile u32 HFSR;
    volatile u32 RESERVED;
    volatile u32 MMFAR;
    volatile u32 BFAR;
}SCB_t;

#define SCB		((volatile SCB_t*)0xE000ED00)

#define VECT_KEY    0x05FA0000

/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/
void NVIC_enablePerInt(u8 IntId);
void NVIC_disablePerInt(u8 IntId);
void NVIC_setPendingFlag(u8 IntId);
void NVIC_clrPendingFlag(u8 IntId);
void NVIC_setPriorityConfig(u8 priprityOption);
void NVIC_setIntPriority(u8 IntId, u8 GroupId, u8 SubGroupId);

#endif
