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

#ifndef SERVO_MOTOR_H_
#define SERVO_MOTOR_H_

#include"STD_TYPES.h"

/*******************************************************************************
 *                                Configurations                               *
 *******************************************************************************/
#define Servo_Frequency				(u32)50 /*configure the frequency of driving the servo motor*/

#define Servo_ControlChannel	    Channel_3 /*configure servo motor control port*/

#define Servo_ControlPin			PIN9 /*configure servo motor control pin*/

/*******************************************************************************
 *                                  Definitions                               *
 *******************************************************************************/
/*Angles definition for servo motor rotation*/
#define Angle_0 			(u16)50
#define Angle_90			(u16)75
#define Angle_180			(u16)100

/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/
/*
 * Description: Function for initialize Servo_Motor
*/
void Servo_Init(void);

/*
 * Description: Function for setting the timer mode to generate PWM
*/
void Servo_Rotate(u16 Angle);

#endif /*SERVO_MOTOR_H_*/
