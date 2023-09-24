#include "icu.h"
#include "ultrasonic.h"

#include "gpio.h"
#include "rcc.h"

#define SPEED_OF_SOUND 343.0f

/*Timer choices*/
#define TIM2       0
#define TIM3       1
#define TIM4       2
#define TIM5       3

/*Channel choices*/
#define CHANNEL1   0
#define CHANNEL2   1
#define CHANNEL3   2
#define CHANNEL4   3

float Distance = 0;
u32 Captutre_1, Capture_2;


static float GetDistance(u32 time);
static void GetCaptureValues(u32* x1,u32* y1);


void UltraSonic_voidInit(void)
{

	// Enable clock for GPIOA
	RCC_enablePeripheralClk(AHB1, 0);
	// Enable clock for TIM2 AND TIM4
	RCC_enablePeripheralClk(APB1, 0);
	RCC_enablePeripheralClk(APB1, 2);
	    // Set trigger pin as output

	 GPIO_setPinMode(GPIOA, PIN4, OUTPUT);
	 GPIO_setPinType(GPIOA, PIN4, OUTPUT_PP);
	 GPIO_setPinSpeed(GPIOA, PIN4, OUTPUT_HS);

	 TIM_Error_tSetPrescaler(TIM_2,15);
	TIM_Error_tSetPreloadValue(TIM_2,0xffffffff);


#if ULTRA_CHANNEL==CHANNEL1
	// Set echo pin as input capture channel
	GPIO_setPinMode(GPIOA, PIN0, AF1);
	GPIO_setPinAlternativeFunNo(GPIOA, PIN0, AF1);
	TIM_Error_tSetChannelState(TIM_2,CHANNEL_1,CHANNEL_STATE_INPUT_CAPTURE);
	TIM_Error_tSetCapture_CompareState(TIM_2,CHANNEL_1,CAPTURE_COMPARE_STATE_ENABLE);

#elif ULTRA_CHANNEL==CHANNEL2
	GPIO_setPinMode(GPIOA, PIN1, AF1);
  GPIO_setPinAlternativeFunNo(GPIOA, PIN1, AF1);
	TIM_Error_tSetChannelState(TIM_2,CHANNEL_2,CHANNEL_STATE_INPUT_CAPTURE);
	TIM_Error_tSetCapture_CompareState(TIM_2,CHANNEL_2,CAPTURE_COMPARE_STATE_ENABLE);

#elif ULTRA_CHANNEL==CHANNEL3
	GPIO_setPinMode(GPIOA, PIN2, AF1);
		GPIO_setPinAlternativeFunNo(GPIOA, PIN2, AF1);
	TIM_Error_tSetChannelState(TIM_2,CHANNEL_3,CHANNEL_STATE_INPUT_CAPTURE);
	TIM_Error_tSetCapture_CompareState(TIM_2,CHANNEL_3,CAPTURE_COMPARE_STATE_ENABLE);

#elif ULTRA_CHANNEL==CHANNEL4
	GPIO_setPinMode(GPIOA, PIN3, AF1);
	GPIO_setPinAlternativeFunNo(GPIOA, PIN3, AF1);
	TIM_Error_tSetChannelState(TIM_2,CHANNEL_4,CHANNEL_STATE_INPUT_CAPTURE);
	TIM_Error_tSetCapture_CompareState(TIM_2,CHANNEL_4,CAPTURE_COMPARE_STATE_ENABLE);
#endif
}

float UltraSonic_floatGetDistance(void)
{
    // Send trigger pulse
	 GPIO_setPinValueDirectAccess(GPIOA, PIN4, PIN_SET);
	    delay15us();
	 GPIO_setPinValueDirectAccess(GPIOA, PIN4, PIN_RST);
	 // Get capture values
	GetCaptureValues(&Captutre_1,&Capture_2);

    // Calculate distance in centimeters
	Distance = GetDistance(Capture_2 - Captutre_1);

	return Distance;
}




static float GetDistance(u32 time)
{
    return (SPEED_OF_SOUND * time) / (20000.0f);
}

static void GetCaptureValues(u32* x1, u32* y1)
{
#if ULTRA_CHANNEL==CHANNEL1

	while(!TIM_u8GetFlag(TIM_2,CHANNEL_1));

	*x1=TIM_u32GetCaptureValueTIM2_TIM5(TIM_2,CHANNEL_1);
	TIM_voidSet_EGR_UG(TIM_2);
	TIM_Error_tSetCounterState(COUNTER_STATE_ENABLE,TIM_2);
	TIM_Error_tSetInputCaptureEdgeTrigger(TIM_2,CHANNEL_1,INPUT_CAPTURE_TRIGGER_FALLING_EDGE);


	while(!TIM_u8GetFlag(TIM_2,CHANNEL_1));
	*y1=TIM_u32GetCaptureValueTIM2_TIM5(TIM_2,CHANNEL_1);
	TIM_Error_tSetInputCaptureEdgeTrigger(TIM_2,CHANNEL_1,INPUT_CAPTURE_TRIGGER_RISING_EDGE);
	TIM_Error_tSetCounterState(COUNTER_STATE_DISABLE,TIM_2);
	TIM_voidClearCounterFlag(TIM_2);
	TIM_voidSetCounterValue(TIM_2,0);

#elif ULTRA_CHANNEL==CHANNEL2
	while(!TIM_u8GetFlag(TIM_2,CHANNEL_2));

		*x1=TIM_u32GetCaptureValueTIM2_TIM5(TIM_2,CHANNEL_2);
		TIM_voidSet_EGR_UG(TIM_2);
		TIM_Error_tSetCounterState(COUNTER_STATE_ENABLE,TIM_2);
		TIM_Error_tSetInputCaptureEdgeTrigger(TIM_2,CHANNEL_2,INPUT_CAPTURE_TRIGGER_FALLING_EDGE);


		while(!TIM_u8GetFlag(TIM_2,CHANNEL_2));
		*y1=TIM_u32GetCaptureValueTIM2_TIM5(TIM_2,CHANNEL_2);
		TIM_Error_tSetInputCaptureEdgeTrigger(TIM_2,CHANNEL_2,INPUT_CAPTURE_TRIGGER_RISING_EDGE);
		TIM_Error_tSetCounterState(COUNTER_STATE_DISABLE,TIM_2);
		TIM_voidClearCounterFlag(TIM_2);
		TIM_voidSetCounterValue(TIM_2,0);

#elif ULTRA_CHANNEL==CHANNEL3
		while(!TIM_u8GetFlag(TIM_2,CHANNEL_3));

		*x1=TIM_u32GetCaptureValueTIM2_TIM5(TIM_2,CHANNEL_3);
		TIM_voidSet_EGR_UG(TIM_2);
		TIM_Error_tSetCounterState(COUNTER_STATE_ENABLE,TIM_2);
		TIM_Error_tSetInputCaptureEdgeTrigger(TIM_2,CHANNEL_3,INPUT_CAPTURE_TRIGGER_FALLING_EDGE);


		while(!TIM_u8GetFlag(TIM_2,CHANNEL_3));
		*y1=TIM_u32GetCaptureValueTIM2_TIM5(TIM_2,CHANNEL_3);
		TIM_Error_tSetInputCaptureEdgeTrigger(TIM_2,CHANNEL_3,INPUT_CAPTURE_TRIGGER_RISING_EDGE);
		TIM_Error_tSetCounterState(COUNTER_STATE_DISABLE,TIM_2);
		TIM_voidClearCounterFlag(TIM_2);
		TIM_voidSetCounterValue(TIM_2,0);

#elif ULTRA_CHANNEL==CHANNEL4
		
		/*Wait for rising edge*/
		while(!TIM_u8GetFlag(TIM_2,CHANNEL_4));

		/*Store the captured value*/
		*x1 = TIM_u32GetCaptureValueTIM2_TIM5(TIM_2,CHANNEL_4);
		/*Reinitialize the counter*/
		TIM_voidSet_EGR_UG(TIM_2);
		/*Enable the counter again*/
	    TIM_Error_tSetCounterState(COUNTER_STATE_ENABLE,TIM_2);
	    /*Set the input capture unit to to trigger on falling edge*/
		TIM_Error_tSetInputCaptureEdgeTrigger(TIM_2,CHANNEL_4,INPUT_CAPTURE_TRIGGER_FALLING_EDGE);

		/*Wait for falling edge*/
		while(!TIM_u8GetFlag(TIM_2,CHANNEL_4) );
		/*Store the captured value*/
		*y1 = TIM_u32GetCaptureValueTIM2_TIM5(TIM_2,CHANNEL_4);
		/*Set the input capture unit to to trigger on rising edge*/
		TIM_Error_tSetInputCaptureEdgeTrigger(TIM_2,CHANNEL_4,INPUT_CAPTURE_TRIGGER_RISING_EDGE);
		/*Disable the counter*/
		TIM_Error_tSetCounterState(COUNTER_STATE_DISABLE,TIM_2);
		/*Clear the counter flag*/
		TIM_voidClearCounterFlag(TIM_2);
		/*Reinitialize the counter*/
		TIM_voidSetCounterValue(TIM_2,0);

#endif

}
