/******************************************************************************
 *
 * Module: dc_motor
 *
 * File Name: dc_motor.h
 *
 * Description: Header file for the ARM DC Motor driver
 *
 * Author: Toka Refaat
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include"STD_TYPES.h"

/*******************************************************************************
 *                                Configurations                               *
 *******************************************************************************/
/*configure the frequency of driving the DC motors*/
#define Motor_Frequency			(u32)50

/*configure L298 Ena, ENb timer channels*/
#define L298_EnaChannel         Channel_1
#define L298_EnbChannel         Channel_2

/*configure L298 Ena, ENb pins*/
#define L298_EnaPin             PIN6
#define L298_EnbPin             PIN7

/*configure L298 In1, In2, In3, In4 port*/
#define L298_InPort            	GPIOB
#define L298_InPortClk          AHB1_GPIOB
#define peripheral_numberClock  1

/*configure L298 In1, In2, In3, In4 pins*/
#define L298_In1Pin             PIN5
#define L298_In2Pin             PIN6
#define L298_In3Pin             PIN7
#define L298_In4Pin             PIN8

/*******************************************************************************
 *                                  Definitions                               *
 *******************************************************************************/
#define Stop                   (u8)0
#define Forward                (u8)1
#define Backward               (u8)2
#define Right                  (u8)3
#define Left                   (u8)4

/*******************************************************************************
 *                               Function Prototypes                           *
 *******************************************************************************/

/*
 * Description: Function for initialize DC_Motor:
 * 1- Clock
 * 2- Pins
 * 3- Timer
 */
void Motor_Init(void);

/*
 * Description: Function for the DC_Motor movement:
 * 1- Stop
 * 2- Forward
 * 3- Backward
 * 4- Right
 * 5- Left
*/
void Motor_Move(u8 Direction, u16 Speed);

#endif /*DC_MOTOR_H_*/


