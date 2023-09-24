/******************************************************************************
 *
 * Module: rcc
 *
 * File Name: rcc.h
 *
 * Description: Header file for the ARM RCC driver
 *
 * Author: Toka Refaat
 *
 *******************************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#include"STD_TYPES.h"

/*******************************************************************************
 *                                Configurations                               *
 *******************************************************************************/

/*RCC_HSE_SRC Option: RCC_HSE_RC, RCC_HSE_CRYSTAL*/
#define RCC_HSE_SRC             RCC_HSE_CRYSTAL

/*RCC_SYS_CLK_SRC Options: HSI, HSE, PLL*/
#define RCC_SYS_CLK_SRC         HSI

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define RCC_HSE_RC               0
#define RCC_HSE_CRYSTAL          1

#define HSI                      0
#define HSE                      1
#define PLL                      2

#define AHB1                     0
#define AHB2                     1
#define APB1                     2
#define APB2                     3

/*******************************************************************************
 *                               Registers Definitions                         *
 *******************************************************************************/

/*RCC Base Address: 0x40023800*/
#define RCC_BASEADDRESS     0x40023800

#define RCC_CR              *((volatile u32*)0x40023800)
#define RCC_PLLCFGR         *((volatile u32*)0x40023804)
#define RCC_CFGR            *((volatile u32*)0x40023808)

#define RCC_AHB1ENR         *((volatile u32*)0x40023830)
#define RCC_AHB2ENR         *((volatile u32*)0x40023834)
#define RCC_APB1ENR         *((volatile u32*)0x40023840)
#define RCC_APB2ENR         *((volatile u32*)0x40023844)

/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/
void RCC_initSystemClk(void);
void RCC_enablePeripheralClk(u8 busId, u8 peripheralId);
void RCC_disablePeripheralClk(u8 busId, u8 peripheralId);

#endif
