/******************************************************************************
 *
 * Module: servo_motor
 *
 * File Name: servo_motor.h
 *
 * Description: Header file for the ARM Servo Motor driver
 *
 * Author: Toka Refaat
 *
*******************************************************************************/

/*******************************************************************************
 *                                    Includes                                 *
*******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "servo_motor.h"
#include "timer.h"
#include "gpio.h"
#include "rcc.h"

/*******************************************************************************
 *                               Function Definitions                          *
 *******************************************************************************/
/*
 * Description: Function for initialize Servo_Motor
*/
void Servo_Init(void)
{
	/*Initialize the timer channel connected to servo control pin according to the configurations*/
	Timer_Init(Servo_ControlChannel);
}

/*
 * Description: Function for setting the timer mode to generate PWM
*/
void Servo_Rotate(u16 Angle)
{
	/*set the servo control pin to be driven by PWM signal of frequency = Servo_Frequency, and duty cycle corresponding to the desired angle*/
	Timer_GeneratePWM(TIMER3, Servo_ControlChannel, Servo_Frequency, Angle);
}
