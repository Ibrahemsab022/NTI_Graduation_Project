/******************************************************************************
 *
 * Module: led
 *
 * File Name: led.h
 *
 * Description: Header file for the ARM LED driver
 *
 * Author: Toka Refaat
 *
 *******************************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#include "STD_TYPES.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define EXTI_INPUT_PIN		GPIOA,0
#define RED_LED_PIN			GPIOA,1
#define BLUE_LED_PIN		GPIOA,2
#define GREEN_LED_PIN		GPIOA,3

#define HIGH		1
#define LOW			0

#define EXTI_INPUT_PIN		GPIOA,0
#define RED_LED			1
#define BLUE_LED		2
#define GREEN_LED		3

/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/
void LED_init(void);
void LED_On(u8 LED);
void LED_Off(u8 LED);


#endif /* LED_INTERFACE_H_ */
