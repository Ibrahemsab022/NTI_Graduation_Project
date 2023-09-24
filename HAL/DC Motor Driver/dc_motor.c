/******************************************************************************
 *
 * Module: pwm
 *
 * File Name: pwm.c
 *
 * Description: Source file for the ARM PWM driver
 *
 * Author: Toka Refaat
 *
 *******************************************************************************/

/*******************************************************************************
 *                                    Includes                                 *
 *******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "dc_motor.h"
#include "timer.h"
#include "gpio.h"
#include "rcc.h"

/*******************************************************************************
 *                               Function Definitions                          *
 *******************************************************************************/

/*
 * Description: Function for initialize DC_Motor:
 * 1- Clock
 * 2- Pins
 * 3- Timer
*/
void Motor_Init(void)
{
	/*Initialize the clock for In1, In2, In3, In4 port*/
	RCC_initSystemClk();
	RCC_enablePeripheralClk(AHB1, 1);

	/*Initialize the timer channels connected to Ena, Enb pins configurations*/
	Timer_Init(L298_EnaChannel);
	Timer_Init(L298_EnbChannel);

	/*set In1, In2, In3, In4 pins to be general purpose output push pull*/
	GPIO_setPinMode(L298_InPort, L298_In1Pin, OUTPUT);
	GPIO_setPinType(L298_InPort, L298_In1Pin, OUTPUT_PP);
	GPIO_setPinSpeed(L298_InPort, L298_In1Pin, OUTPUT_MS);

	GPIO_setPinMode(L298_InPort, L298_In2Pin, OUTPUT);
	GPIO_setPinType(L298_InPort, L298_In2Pin, OUTPUT_PP);
	GPIO_setPinSpeed(L298_InPort, L298_In2Pin, OUTPUT_MS);

	GPIO_setPinMode(L298_InPort, L298_In3Pin, OUTPUT);
	GPIO_setPinType(L298_InPort, L298_In3Pin, OUTPUT_PP);
	GPIO_setPinSpeed(L298_InPort, L298_In3Pin, OUTPUT_MS);

	GPIO_setPinMode(L298_InPort, L298_In4Pin, OUTPUT);
	GPIO_setPinType(L298_InPort, L298_In4Pin, OUTPUT_PP);
	GPIO_setPinSpeed(L298_InPort, L298_In4Pin, OUTPUT_MS);
}

/*
 * Description: Function for the DC_Motor movement:
 * 1- Stop
 * 2- Forward
 * 3- Backward
 * 4- Right
 * 5- Left
*/
void Motor_Move(u8 Direction, u16 Speed)
{
	/*set Ena, Enb pins to be driven by PWM signals of frequency = Motor_Frequency, and duty cycle corresponding to the desired speed*/
	Timer_GeneratePWM(TIMER3, Channel_1, Motor_Frequency, Speed);
	Timer_GeneratePWM(TIMER3, Channel_2, Motor_Frequency, Speed);

	/*set the direction of rotation of the 4 motors according to the specified motion direction*/
	switch (Direction)
	{
	/*stop the 4 motors to stop the car*/
	case Stop:
		GPIO_setPinValueDirectAccess(L298_InPort, L298_In1Pin, PIN_RST);
		GPIO_setPinValueDirectAccess(L298_InPort, L298_In2Pin, PIN_RST);
		GPIO_setPinValueDirectAccess(L298_InPort, L298_In3Pin, PIN_RST);
		GPIO_setPinValueDirectAccess(L298_InPort, L298_In4Pin, PIN_RST);
		break;
		/*move the 4 motors in the forward direction to move the car forward*/
	case Forward:
		GPIO_setPinValueDirectAccess(L298_InPort, L298_In1Pin, PIN_SET);
		GPIO_setPinValueDirectAccess(L298_InPort, L298_In2Pin, PIN_RST);
		GPIO_setPinValueDirectAccess(L298_InPort, L298_In3Pin, PIN_SET);
		GPIO_setPinValueDirectAccess(L298_InPort, L298_In4Pin, PIN_RST);
		break;
		/*move the 4 motors in the backward direction to move the car backward*/
	case Backward:
		GPIO_setPinValueDirectAccess(L298_InPort, L298_In1Pin, PIN_RST);
		GPIO_setPinValueDirectAccess(L298_InPort, L298_In2Pin, PIN_SET);
		GPIO_setPinValueDirectAccess(L298_InPort, L298_In3Pin, PIN_RST);
		GPIO_setPinValueDirectAccess(L298_InPort, L298_In4Pin, PIN_SET);
		break;
		/*move the left motors in the forward direction and stop the right motors to make the car turn right*/
	case Right:
		GPIO_setPinValueDirectAccess(L298_InPort, L298_In1Pin, PIN_RST);
		GPIO_setPinValueDirectAccess(L298_InPort, L298_In2Pin, PIN_RST);
		GPIO_setPinValueDirectAccess(L298_InPort, L298_In3Pin, PIN_SET);
		GPIO_setPinValueDirectAccess(L298_InPort, L298_In4Pin, PIN_RST);
		break;
		/*move the right motors in the forward direction and stop the left motors to make the car turn left*/
	case Left:
		GPIO_setPinValueDirectAccess(L298_InPort, L298_In1Pin, PIN_SET);
		GPIO_setPinValueDirectAccess(L298_InPort, L298_In2Pin, PIN_RST);
		GPIO_setPinValueDirectAccess(L298_InPort, L298_In3Pin, PIN_RST);
		GPIO_setPinValueDirectAccess(L298_InPort, L298_In4Pin, PIN_RST);
		break;
	}

}
