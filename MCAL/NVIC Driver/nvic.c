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

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "nvic.h"

/*******************************************************************************
 *                                  Global Variables                           *
 *******************************************************************************/

static u8 StaticGlobal_u8PriorityConfig;


/*******************************************************************************
 *                                 Function Definitions                        *
 *******************************************************************************/
void NVIC_enablePerInt(u8 IntId)
{
    NVIC -> ISER[IntId / 32] = (1 << (IntId % 32));
}

void NVIC_disablePerInt(u8 IntId)
{
    NVIC -> ICER[IntId / 32] = (1 << (IntId % 32));
}

void NVIC_setPendingFlag(u8 IntId)
{
    NVIC -> ISPR[IntId / 32] = (1 << (IntId % 32));
}
void NVIC_clrPendingFlag(u8 IntId)
{
    NVIC -> ICPR[IntId / 32] = (1 << (IntId % 32));
}

/*Copy_u8PriprityOption: GROUP4BITS_SUBGROUP0BITS, GROUP3BITS_SUBGROUP1BITS, GROUP2BITS_SUBGROUP2BITS, GROUP1BITS_SUBGROUP3BITS, GROUP0BITS_SUBGROUP4BITS*/
void NVIC_setPriorityConfig(u8 priprityOption)
{
    StaticGlobal_u8PriorityConfig = VECT_KEY | (priprityOption << 8);
    SCB -> AIRCR = StaticGlobal_u8PriorityConfig;
}

/*18, 1, 2*/
void NVIC_setIntPriority(u8 IntId, u8 GroupId, u8 SubGroupId)
{
    u8 Local_u8Priority;

	Local_u8Priority = SubGroupId | (GroupId << ((StaticGlobal_u8PriorityConfig - 0x05FA0300)/256)); //0x05FA0400
    NVIC ->IPR[IntId] = (Local_u8Priority << 4);
}
