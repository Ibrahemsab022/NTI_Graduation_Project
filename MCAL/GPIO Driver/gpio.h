/******************************************************************************
 *
 * Module: gpio
 *
 * File Name: gpio.h
 *
 * Description: Header file for the ARM GPIO driver
 *
 * Author: Toka Refaat
 *
 *******************************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include"STD_TYPES.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define GPIOA           0
#define GPIOB           1
#define GPIOC           2

#define PIN0            0 
#define PIN1            1 
#define PIN2            2 
#define PIN3            3 
#define PIN4            4 
#define PIN5            5 
#define PIN6            6 
#define PIN7            7 
#define PIN8            8 
#define PIN9            9 
#define PIN10           10
#define PIN11           11
#define PIN12           12
#define PIN13           13
#define PIN14           14
#define PIN15           15

#define INPUT           0
#define OUTPUT          1
#define AF              2
#define ANALOG          3

#define OUTPUT_PP       0
#define OUTPUT_OD       1

#define OUTPUT_LS       0
#define OUTPUT_MS       1
#define OUTPUT_HS       2

#define PIN_SET			0
#define PIN_RST			1

#define INPUT_FLOATING	0
#define INPUT_PU		1
#define INPUT_PD		2

/*******************************************************************************
 *                               Registers Definitions                         *
 *******************************************************************************/
/*GPIO Bus: AHB*/
/*GPIOA Base Address: 0x40020000*/
#define GPIOA_MODER         *((volatile u32*)0x40020000)
#define GPIOA_TYPER         *((volatile u32*)0x40020004)
#define GPIOA_SPEEDR        *((volatile u32*)0x40020008)
#define GPIOA_PUPDR         *((volatile u32*)0x4002000C)
#define GPIOA_IDR           *((volatile u32*)0x40020010)
#define GPIOA_ODR           *((volatile u32*)0x40020014)
#define GPIOA_BSRR          *((volatile u32*)0x40020018)
#define GPIOA_AFRL          *((volatile u32*)0x40020020)
#define GPIOA_AFRH          *((volatile u32*)0x40020024)

/*GPIOB Base Address: 0x40020400*/
#define GPIOB_MODER         *((volatile u32*)0x40020400)
#define GPIOB_TYPER         *((volatile u32*)0x40020404)
#define GPIOB_SPEEDR        *((volatile u32*)0x40020408)
#define GPIOB_PUPDR         *((volatile u32*)0x4002040C)
#define GPIOB_IDR           *((volatile u32*)0x40020410)
#define GPIOB_ODR           *((volatile u32*)0x40020414)
#define GPIOB_BSRR          *((volatile u32*)0x40020418)
#define GPIOB_AFRL          *((volatile u32*)0x40020420)
#define GPIOB_AFRH          *((volatile u32*)0x40020424)

/*GPIOC Base Address: 0x40020800*/
#define GPIOC_MODER         *((volatile u32*)0x40020800)
#define GPIOC_TYPER         *((volatile u32*)0x40020804)
#define GPIOC_SPEEDR        *((volatile u32*)0x40020808)
#define GPIOC_PUPDR         *((volatile u32*)0x4002080C)
#define GPIOC_IDR           *((volatile u32*)0x40020810)
#define GPIOC_ODR           *((volatile u32*)0x40020814)
#define GPIOC_BSRR          *((volatile u32*)0x40020818)
#define GPIOC_AFRL          *((volatile u32*)0x40020820)
#define GPIOC_AFRH          *((volatile u32*)0x40020824)

/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/
void GPIO_setPinMode(u8 portId, u8 pinId, u8 mode);
void GPIO_setPinType(u8 portId, u8 pinId, u8 type);
void GPIO_setPinSpeed(u8 portId, u8 pinId, u8 speed);
void GPIO_setPinPUPDOption(u8 portId, u8 pinId, u8 PUPD_Option);
void GPIO_setPortValue(u8 portId, u32 value);
void GPIO_setPinValueDirectAccess(u8 portId, u8 pinId, u8 signal);
u8 GPIO_getPinValue(u8 portId, u8 pinId);


#endif
