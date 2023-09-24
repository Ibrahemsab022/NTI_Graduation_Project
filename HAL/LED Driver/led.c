/******************************************************************************
 *
 * Module: led
 *
 * File Name: led.c
 *
 * Description: Source file for the ARM LED driver
 *
 * Author: Toka Refaat
 *
 *******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "led.h"
#include "gpio.h"

void LED_init(void)
{
	GPIO_setPinMode(RED_LED_PIN,OUTPUT) ;
	GPIO_setPinMode(BLUE_LED_PIN,OUTPUT) ;
	GPIO_setPinMode(GREEN_LED_PIN,OUTPUT) ;

	GPIO_setPinType(RED_LED_PIN,  OUTPUT_PP) ;
	GPIO_setPinType(BLUE_LED_PIN, OUTPUT_PP) ;
	GPIO_setPinType(GREEN_LED_PIN,OUTPUT_PP) ;

	GPIO_setPinSpeed(RED_LED_PIN,  OUTPUT_LS) ;
	GPIO_setPinSpeed(BLUE_LED_PIN, OUTPUT_LS) ;
	GPIO_setPinSpeed(GREEN_LED_PIN,OUTPUT_LS) ;
}

void LED_On(u8 LED)
{
	switch (LED)
	{
	case RED_LED:
		GPIO_setPinValueDirectAccess(RED_LED_PIN, HIGH);
		break;

	case BLUE_LED:
		GPIO_setPinValueDirectAccess(BLUE_LED_PIN, HIGH);
		break;

	case GREEN_LED:
		GPIO_setPinValueDirectAccess(GREEN_LED_PIN, HIGH);
		break;

	default:
		break;
	}
}

void LED_Off(u8 LED)
{
	switch (LED)
	{
	case RED_LED:
		GPIO_setPinValueDirectAccess(RED_LED_PIN, LOW);
		break;
	case BLUE_LED:
		GPIO_setPinValueDirectAccess(BLUE_LED_PIN, LOW);
		break;
	case GREEN_LED:
		GPIO_setPinValueDirectAccess(GREEN_LED_PIN, LOW);
		break;

	default:
		break;
	}

}
