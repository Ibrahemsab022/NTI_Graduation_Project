
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "pwm.h"
#include "rcc.h"
#include "gpio.h"

void TIMER_Init(u8 Channel)
{
	RCC_initSystemClk();

	switch (Channel)
	{
	case Channel_1:
		GPIO_setPinMode(GPIOA, PIN6, AF);
		GPIO_setPinAlternativeFunNo(GPIOA, PIN6, AF2);
		RCC_enablePeripheralClk(AHB1, AHB1_GPIOA);
		break;

	case Channel_2:
		GPIO_setPinMode(GPIOA, PIN7, AF);
		GPIO_setPinAlternativeFunNo(GPIOA, PIN7, AF2);
		RCC_enablePeripheralClk(AHB1, AHB1_GPIOA);
		break;

	case Channel_3:
		GPIO_setPinMode(GPIOB, PIN0, AF);
		GPIO_setPinAlternativeFunNo(GPIOB, PIN0, AF2);
		RCC_enablePeripheralClk(AHB1, AHB1_GPIOB);
		break;

	case Channel_4:
		GPIO_setPinMode(GPIOB, PIN1, AF);
		GPIO_setPinAlternativeFunNo(GPIOB, PIN1, AF2);
		RCC_enablePeripheralClk(AHB1, AHB1_GPIOB);
		break;
	}

	RCC_enablePeripheralClk(APB1, APB1_TIM3);
}

void Timer_GeneratePWM(TIMER_t* Timer, u8 Channel, u32 Frequency, u16 Duty)
{
	/*Set Capture/Compare 1 as output */
	switch (Channel)
	{
	case Channel_1:
		Timer->CCMR1 &= ~TIMER_CCMR1_CC1S;
		break;

	case Channel_2:
		Timer->CCMR1 &= ~TIMER_CCMR1_CC2S;
		break;

	case Channel_3:
		Timer->CCMR2 &= ~TIMER_CCMR2_CC3S;
		break;

	case Channel_4:
		Timer->CCMR2 &= ~TIMER_CCMR2_CC4S;
		break;
	}


	/*Configure the output compare channel for PWM mode1*/
	switch (Channel)
	{
	case Channel_1:
		Timer->CCMR1 |= TIMER_CCMR1_OC1M_PWM1;
		break;

	case Channel_2:
		Timer->CCMR1 |= TIMER_CCMR1_OC2M_PWM1;
		break;

	case Channel_3:
		Timer->CCMR2 |= TIMER_CCMR2_OC3M_PWM1;
		break;

	case Channel_4:
		Timer->CCMR2 |= TIMER_CCMR2_OC4M_PWM1;
		break;
	}

	/* Output Compare 1 preload enable */
	switch (Channel)
	{
	case Channel_1:
		Timer->CCMR1 |= TIMER_CCMR1_OC1PE;
		break;

	case Channel_2:
		Timer->CCMR1 |= TIMER_CCMR1_OC2PE;
		break;

	case Channel_3:
		Timer->CCMR2 |= TIMER_CCMR2_OC3PE;
		break;

	case Channel_4:
		Timer->CCMR2 |= TIMER_CCMR2_OC4PE;
		break;
	}

	/*Set counter direction as up-counter*/
	Timer->CR1 &= ~(TIMER_CR1_DIR | TIMER_CR1_CMS);

	/*Enable Auto-reload preload */
	Timer->CR1 |= TIMER_CR1_ARPE;

	/*Enable output pin for the selected channel*/
	Timer->CCER |= 1 << (Channel * 4);

	/*Configure the timer prescaler and period to generate the desired frequency*/
	Timer->ARR = ARR_Value;
	Timer->PSC = Timer_Clk / (Frequency * ARR_Value) - 1;

	/*Set the initial duty cycle*/
	switch (Channel)
	{
	case Channel_1:
		Timer->CCR1 = ARR_Value * Duty / Max_Duty;
		break;

	case Channel_2:
		Timer->CCR2 = ARR_Value * Duty / Max_Duty;
		break;

	case Channel_3:
		Timer->CCR3 = ARR_Value * Duty / Max_Duty;
		break;

	case Channel_4:
		Timer->CCR4 = ARR_Value * Duty / Max_Duty;
		break;
	}

	/* Initialize all the registers */
	Timer->EGR |= TIMER_EGR_UG;

	/*Start the counter*/
	Timer->CR1 |= TIMER_CR1_CEN;
}
