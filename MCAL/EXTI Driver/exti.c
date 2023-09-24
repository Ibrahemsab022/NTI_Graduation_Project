/******************************************************************************
 *
 * Module: exti
 *
 * File Name: exti.c
 *
 * Description: Source file for the ARM EXTI driver
 *
 * Author: Toka Refaat
 *
 *******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "exti.h"

void EXTI_init()
{
	#if		EXTI_SENSE_CONTROL	== FALLING_EDGE
			SET_BIT(EXTI -> FTSR, EXTI_LINE);
			CLR_BIT(EXTI -> RTSR, EXTI_LINE);
	#elif	EXTI_SENSE_CONTROL	== RISING_EDGE
			CLR_BIT(EXTI -> FTSR, EXTI_LINE);
			SET_BIT(EXTI -> RTSR, EXTI_LINE);
	#elif	EXTI_SENSE_CONTROL	== ON_CHANGE
			SET_BIT(EXTI -> FTSR, EXTI_LINE);
			SET_BIT(EXTI -> RTSR, EXTI_LINE);
	#else
			#error "Not a valid Configuration!"
	#endif
}

/*Copy_u8LineId Options: EXTI_LINE_0 --> EXTI_LINE_15*/
void EXTI_setExtiLineEnable(u8 lineId)
{
	SET_BIT(EXTI -> IMR, lineId);
}

/*Copy_u8LineId Options: EXTI_LINE_0 --> EXTI_LINE_15*/
void EXTI_setExtiLineDisable(u8 lineId)
{
	CLR_BIT(EXTI -> IMR, lineId);
}

/*Copy_u8SenseControl: FALLING_EDGE, RISING_EDGE, ON_CHANGE*/
/*Copy_u8LineId Options: EXTI_LINE_0 --> EXTI_LINE_15*/
void EXTI_setSenseControl(u8 senseControl, u8 lineId)
{
	switch(senseControl)
	{
		case FALLING_EDGE:	SET_BIT(EXTI -> FTSR, lineId);
							CLR_BIT(EXTI -> RTSR, lineId);
							break;
		case RISING_EDGE:	CLR_BIT(EXTI -> FTSR, lineId);
							SET_BIT(EXTI -> RTSR, lineId);
							break;
		case ON_CHANGE:		SET_BIT(EXTI -> FTSR, lineId);
							SET_BIT(EXTI -> RTSR, lineId);
							break;
		default:			break;
	}
}

/*Copy_u8PortId Options: EXTI_PA, EXTI_PB, EXTI_PC*/
/*Copy_u8LineId Options: EXTI_LINE_0 --> EXTI_LINE_15*/
void EXTI_setEXTIpinConfig(u8 portId, u8 lineId)
{
	if(lineId <= EXTI_LINE_3)
	{
		switch(portId)
		{
			case EXTI_PA:	SYSCFG->EXTICR1 = ((0b0000) << (lineId*4));
							break;
			case EXTI_PB:	SYSCFG->EXTICR1 = ((0b0001) << (lineId*4));
							break;
			case EXTI_PC:	SYSCFG->EXTICR1 = ((0b0010) << (lineId*4));
							break;
			default:		break;
		}
	}
	else if (lineId <= EXTI_LINE_7)
	{
		switch(portId)
		{
			case EXTI_PA:	SYSCFG->EXTICR2 = ((0b0000) << ((lineId-4)*4));
							break;
			case EXTI_PB:	SYSCFG->EXTICR2 = ((0b0001) << ((lineId-4)*4));
							break;
			case EXTI_PC:	SYSCFG->EXTICR2 = ((0b0010) << ((lineId-4)*4));
							break;
			default:		break;
		}
	}
	else if (lineId <= EXTI_LINE_11)
	{
		switch(portId)
		{
			case EXTI_PA:	SYSCFG->EXTICR3 = ((0b0000) << ((lineId-8)*4));
							break;
			case EXTI_PB:	SYSCFG->EXTICR3 = ((0b0001) << ((lineId-8)*4));
							break;
			case EXTI_PC:	SYSCFG->EXTICR3 = ((0b0010) << ((lineId-8)*4));
							break;
			default:		break;
		}
	}
	else
	{
		switch(portId)
		{
			case EXTI_PA:	SYSCFG->EXTICR4 = ((0b0000) << ((lineId-12)*4));
							break;
			case EXTI_PB:	SYSCFG->EXTICR4 = ((0b0001) << ((lineId-12)*4));
							break;
			case EXTI_PC:	SYSCFG->EXTICR4 = ((0b0010) << ((lineId-12)*4));
							break;
			default:		break;
		}
	}
}
