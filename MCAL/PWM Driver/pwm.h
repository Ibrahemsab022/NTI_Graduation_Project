/******************************************************************************
 *
 * Module: pwm
 *
 * File Name: pwm.h
 *
 * Description: Header file for the ARM PWM driver
 *
 * Author: Toka Refaat
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

#include "STD_TYPES.h"

/************************************************************************************************************
 *                                                 Definitions                                               *
 ***********************************************************************************************************/
#define  Timer_Clk       		 16000000UL              /*Timer Clock value*/
#define  ARR_Value       		 1000               	 /*ARR register value*/
#define  Max_Duty       		 1000                    /*Duty cycle must be between 0, Max_Duty*/

#define Channel_1				 0
#define Channel_2				 1
#define Channel_3				 2
#define Channel_4				 3

/************************************************************************************************************
 *                                                 Registers                                               *
 ***********************************************************************************************************/

/*********************Base addresses for APB1 BUS Peripherals*********************/
#define TIM1_BASE						0x40010000UL
#define TIM2_BASE						0x40000000UL
#define TIM3_BASE						0x40000400UL
#define TIM4_BASE						0x40000800UL
#define TIM5_BASE						0x40000C00UL

typedef struct
{
	u32 CR1;              /*!< TIM control register 1,              Address offset: 0x00 */
	u32 CR2;              /*!< TIM control register 2,              Address offset: 0x04 */
	u32 SMCR;             /*!< TIM slave mode control register,     Address offset: 0x08 */
	u32 DIER;             /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
	u32 SR;               /*!< TIM status register,                 Address offset: 0x10 */
	u32 EGR;              /*!< TIM event generation register,       Address offset: 0x14 */
	u32 CCMR1;            /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
	u32 CCMR2;            /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
	u32 CCER;             /*!< TIM capture/compare enable register, Address offset: 0x20 */
	u32 CNT;              /*!< TIM counter register,                Address offset: 0x24 */
	u32 PSC;              /*!< TIM prescaler,                       Address offset: 0x28 */
	u32 ARR;              /*!< TIM auto-reload register,            Address offset: 0x2C */
	u32 RESERVED0;		/*!< Reserved,							  Address offset: 0x30 */
	u32 CCR1;             /*!< TIM capture/compare register 1,      Address offset: 0x34 */
	u32 CCR2;             /*!< TIM capture/compare register 2,      Address offset: 0x38 */
	u32 CCR3;             /*!< TIM capture/compare register 3,      Address offset: 0x3C */
	u32 CCR4;             /*!< TIM capture/compare register 4,      Address offset: 0x40 */
	u32 RESERVED1;	    /*!< Reserved,						   	  Address offset: 0x44 */
	u32 DCR;              /*!< TIM DMA control register,            Address offset: 0x48 */
	u32 DMAR;             /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
	u32 OR;               /*!< TIM option register,                 Address offset: 0x50 */
}
TIMER_t;

#define TIMER2		((TIMER_t*)TIM2_BASE)
#define TIMER3		((TIMER_t*)TIM3_BASE)
#define TIMER4		((TIMER_t*)TIM4_BASE)
#define TIMER5		((TIMER_t*)TIM5_BASE)



#define  TIMER_CR1_ARPE          (u32)0x0080             /*Auto-reload preload enable*/
#define  TIMER_CR1_DIR           (u32)0x0010             /*Direction*/
#define  TIMER_CR1_CMS           (u32)0x0060             /*CMS[1:0] bits (Center-aligned mode selection)*/
#define  TIMER_CR2_MMS_2         (u32)0x0040             /*Bit 2*/
#define  TIMER_SMCR_MSM          (u32)0x0080             /*Master/slave mode*/

#define  TIMER_CCMR1_CC1S        (u32)0x0003             /*Capture/Compare 1 Selection*/
#define  TIMER_CCMR1_CC2S        (u32)0x0300             /*Capture/Compare 2 Selection*/
#define  TIMER_CCMR2_CC3S        (u32)0x0003             /*Capture/Compare 3 Selection*/
#define  TIMER_CCMR2_CC4S        (u32)0x0300             /*Capture/Compare 4 Selection*/

#define  TIMER_CCMR1_OC1PE       0x00000008UL               /*Output Compare 1 Preload enable*/
#define  TIMER_CCMR1_OC2PE       0x00000800UL              /*Output Compare 2 Preload enable*/
#define  TIMER_CCMR2_OC3PE       0x00000008UL               /*Output Compare 3 Preload enable*/
#define  TIMER_CCMR2_OC4PE       0x00000800UL              /*Output Compare 4 Preload enable*/

#define  TIMER_CCMR1_OC1M_PWM1   (u32)0x0060             /*Output Compare 1 PWM1 mode*/
#define  TIMER_CCMR1_OC2M_PWM1   (u32)0x6000             /*Output Compare 1 PWM1 mode*/
#define  TIMER_CCMR2_OC3M_PWM1   (u32)0x0060             /*Output Compare 1 PWM1 mode*/
#define  TIMER_CCMR2_OC4M_PWM1   (u32)0x6000             /*Output Compare 1 PWM1 mode*/

#define  TIMER_CCER_CC1P         (u32)0x0002             /*Capture/Compare 1 output Polarity*/
#define  TIMER_EGR_UG            (u32)0x0001             /*Update Generation*/
#define  TIMER_CCER_CC1E         (u32)0x0001             /*Capture/Compare 1 output enable*/
#define  TIMER_BDTR_MOE          (u32)0x8000             /*Main Output enable*/
#define  TIMER_CR1_CEN           (u32)0x0001             /*Counter enable*/
#define  TIMER_CCER_CC1E         (u32)0x0001             /*Counter enable*/


/************************************************************************************************************
 *                                             Function Definition                                          *
 ***********************************************************************************************************/
/*
 * Description :
 * Initialize the timer:
 */
void TIMER_Init(u8 Channel);


/*
 * @Function    - MTimer_GeneratePWM
 * @Brief       - Generates a PWM signal at the given frequency and duty cycle on a specified pin
 * @Arguments   - Timer: the timer instance to be configured in the PWM mode
 * 				- Frequency: the frequency of the output PWM signal
 * 				- Duty: the duty cycle of the output PWM signal
 * 				- GPIOx (x can be from A..H): select the GPIO peripheral instance
 * 				- PinNumber: The number of the pin to be configured as PWM pin
 * @Return      - None
 * @Notes       - The duty cycle must be a number between 0 and Max_Duty
 */
void Timer_GeneratePWM(TIMER_t* Timer, u8 Channel, u32 Frequency, u16 Duty);

#endif /*PWM_H_*/
