/******************************************************************************
 *
 * Module: rcc
 *
 * File Name: rcc.c
 *
 * Description: Source file for the ARM RCC driver
 *
 * Author: Toka Refaat
 *
 *******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "rcc.h"


void RCC_initSystemClk(void)
{
	/*HSI is ON*/
	SET_BIT(RCC_CR, 0);
	/*HSE is ON*/
	SET_BIT(RCC_CR, 16);

	/*if HSE Config: RCC_HSE_CRYSTAL --> Clr bit 18 in CR*/
#if RCC_HSE_SRC == RCC_HSE_CRYSTAL
	CLR_BIT(RCC_CR, 18);

#elif  RCC_HSE_SRC == RCC_HSE_RC
	SET_BIT(RCC_CR, 18);

#endif
	/*PLL is ON*/
	SET_BIT(RCC_CR, 24);

	/*Select Clock Source*/
#if RCC_SYS_CLK_SRC == HSI
	CLR_BIT(RCC_CFGR, 0);
	CLR_BIT(RCC_CFGR, 1);

#elif RCC_SYS_CLK_SRC == HSE
	SET_BIT(RCC_CFGR, 0);
	CLR_BIT(RCC_CFGR, 1);

#elif RCC_SYS_CLK_SRC == PLL
	CLR_BIT(RCC_CFGR, 0);
	SET_BIT(RCC_CFGR, 1);

#else
#error "Invalid Configurations!"

#endif
	/*select AHB prescaler*/
	SET_BIT(RCC_CFGR,7);
}

/*GPIOA --> AHB1*/
/*Copy_u8BusId: AHB1, AHB2, APB1, APB2*/
/*Copy_u8PerId: 0 --> 31*/
void RCC_enablePeripheralClk(u8 busId, u8 peripheralId)
{
	/*Input Validation*/
	if((busId > APB2) || (peripheralId > 31))
	{
		/*Do Nothing*/
	}
	else
	{
		switch(busId)
		{
		case AHB1:
			SET_BIT(RCC_AHB1ENR, peripheralId);
			break;

		case AHB2:
			SET_BIT(RCC_AHB2ENR, peripheralId);
			break;

		case APB1:
			SET_BIT(RCC_APB1ENR, peripheralId);
			break;

		case APB2:
			SET_BIT(RCC_APB2ENR, peripheralId);
			break;

		default:
			break;
		}
	}

}

void RCC_disablePeripheralClk(u8 busId, u8 peripheralId)
{
	/*Input Validation*/
	if((busId > APB2) || (peripheralId > 31))
	{
		/*Do Nothing*/
	}
	else
	{
		switch(busId)
		{
		case AHB1:
			CLR_BIT(RCC_AHB1ENR, peripheralId);
			break;

		case AHB2:
			CLR_BIT(RCC_AHB2ENR, peripheralId);
			break;

		case APB1:
			CLR_BIT(RCC_APB1ENR, peripheralId);
			break;

		case APB2:
			CLR_BIT(RCC_APB2ENR, peripheralId);
			break;

		default:
			break;
		}
	}
}
