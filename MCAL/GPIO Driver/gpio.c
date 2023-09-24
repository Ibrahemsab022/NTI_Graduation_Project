/******************************************************************************
 *
 * Module: gpio
 *
 * File Name: gpio.c
 *
 * Description: source file for the ARM GPIO driver
 *
 * Author: Toka Refaat
 *
 *******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "gpio.h"

void GPIO_setPinMode(u8 portId, u8 pinId, u8 mode)
{
	/*I/P Validation*/
	if((portId > GPIOC) || (pinId > PIN15) || (mode > ANALOG))
	{
		/*Do Nothing*/
	}
	else
	{
		switch(mode)
		{
		case INPUT:
			switch(portId)
			{
			case GPIOA:
				CLR_BIT(GPIOA_MODER, (pinId*2));
				CLR_BIT(GPIOA_MODER, ((pinId*2)+1));
				break;

			case GPIOB:
				CLR_BIT(GPIOB_MODER, (pinId*2));
				CLR_BIT(GPIOB_MODER, ((pinId*2)+1));
				break;

			case GPIOC:
				CLR_BIT(GPIOC_MODER, (pinId*2));
				CLR_BIT(GPIOC_MODER, ((pinId*2)+1));
				break;

			default:
				break;
			}
			break;

			case OUTPUT:
				switch(portId)
				{
				case GPIOA:
					SET_BIT(GPIOA_MODER, (pinId*2));
					CLR_BIT(GPIOA_MODER, ((pinId*2)+1));
					break;

				case GPIOB:
					SET_BIT(GPIOB_MODER, (pinId*2));
					CLR_BIT(GPIOB_MODER, ((pinId*2)+1));
					break;

				case GPIOC:
					SET_BIT(GPIOC_MODER, (pinId*2));
					CLR_BIT(GPIOC_MODER, ((pinId*2)+1));
					break;

				default:
					break;
				}
				break;

				case AF:
					switch(portId)
					{
					case GPIOA:
						CLR_BIT(GPIOA_MODER, (pinId*2));
						SET_BIT(GPIOA_MODER, ((pinId*2)+1));
						break;

					case GPIOB:
						CLR_BIT(GPIOB_MODER, (pinId*2));
						SET_BIT(GPIOB_MODER, ((pinId*2)+1));
						break;

					case GPIOC: CLR_BIT(GPIOC_MODER, (pinId*2));
					SET_BIT(GPIOC_MODER, ((pinId*2)+1));
					break;

					default:
						break;
					}
					break;

					case
					ANALOG:switch(portId)
					{
					case GPIOA:
						SET_BIT(GPIOA_MODER, (pinId*2));
						SET_BIT(GPIOA_MODER, ((pinId*2)+1));
						break;

					case GPIOB:
						SET_BIT(GPIOB_MODER, (pinId*2));
						SET_BIT(GPIOB_MODER, ((pinId*2)+1));
						break;

					case GPIOC:
						SET_BIT(GPIOC_MODER, (pinId*2));
						SET_BIT(GPIOC_MODER, ((pinId*2)+1));
						break;

					default:
						break;
					}
					break;

					default:
						break;
		}
	}
}

/*Copy_u8Type: OUTPUT_PP, OUTPUT_OD*/
void GPIO_setPinType(u8 portId, u8 pinId, u8 type)
{
	/*I/P Validation*/
	if((portId > GPIOC) || (pinId > PIN15) || (type > OUTPUT_OD))
	{
		/*Do Nothing*/
	}
	else
	{
		switch(type)
		{
		case OUTPUT_PP:
			switch(portId)
			{
			case GPIOA:
				CLR_BIT(GPIOA_TYPER, pinId);
				break;

			case GPIOB:
				CLR_BIT(GPIOB_TYPER, pinId);
				break;

			case GPIOC:
				CLR_BIT(GPIOB_TYPER, pinId);
				break;

			default:
				break;
			}
			break;
			case OUTPUT_OD:
				switch(portId)
				{
				case GPIOA:
					SET_BIT(GPIOA_TYPER, pinId);
					break;

				case GPIOB:
					SET_BIT(GPIOB_TYPER, pinId);
					break;

				case GPIOC:
					SET_BIT(GPIOB_TYPER, pinId);
					break;

				default:
					break;
				}
				break;
				default:
					break;
		}
	}
}

/*Copy_u8Speed: OUTPUT_LS, OUTPUT_MS, OUTPUT_HS*/
void GPIO_setPinSpeed(u8 portId, u8 pinId, u8 speed)
{
	/*I/P Validation*/
	if((portId > GPIOC) || (pinId > PIN15) || (speed > OUTPUT_HS))
	{
		/*Do Nothing*/
	}
	else
	{
		switch(speed)
		{
		case OUTPUT_LS: switch(portId)
		{
		case GPIOA:
			CLR_BIT(GPIOA_SPEEDR, (pinId*2));
			CLR_BIT(GPIOA_SPEEDR, ((pinId*2)+1));
			break;

		case GPIOB:
			CLR_BIT(GPIOB_SPEEDR, (pinId*2));
			CLR_BIT(GPIOB_SPEEDR, ((pinId*2)+1));
			break;

		case GPIOC:
			CLR_BIT(GPIOC_SPEEDR, (pinId*2));
			CLR_BIT(GPIOC_SPEEDR, ((pinId*2)+1));
			break;

		default:
			break;
		}
		break;
		case OUTPUT_MS:
			switch(portId)
			{
			case GPIOA:
				SET_BIT(GPIOA_SPEEDR, (pinId*2));
				CLR_BIT(GPIOA_SPEEDR, ((pinId*2)+1));
				break;

			case GPIOB:
				SET_BIT(GPIOB_SPEEDR, (pinId*2));
				CLR_BIT(GPIOB_SPEEDR, ((pinId*2)+1));
				break;

			case GPIOC:
				SET_BIT(GPIOC_SPEEDR, (pinId*2));
				CLR_BIT(GPIOC_SPEEDR, ((pinId*2)+1));
				break;

			default:
				break;
			}
			break;

			case OUTPUT_HS:
				switch(portId)
				{
				case GPIOA:
					CLR_BIT(GPIOA_SPEEDR, (pinId*2));
					SET_BIT(GPIOA_SPEEDR, ((pinId*2)+1));
					break;

				case GPIOB:
					CLR_BIT(GPIOB_SPEEDR, (pinId*2));
					SET_BIT(GPIOB_SPEEDR, ((pinId*2)+1));
					break;

				case GPIOC:
					CLR_BIT(GPIOC_SPEEDR, (pinId*2));
					SET_BIT(GPIOC_SPEEDR, ((pinId*2)+1));
					break;

				default:
					break;
				}
				break;

				default:
					break;
		}
	}
}

/*Copy_u8PuPdOption: INPUT_FLOATING, INPUT_PU, INPUT_PD*/
void GPIO_setPinPUPDOption(u8 portId, u8 pinId, u8 PUPD_Option)
{
	if((portId > GPIOC) || (pinId > PIN15) || (PUPD_Option > INPUT_PD))
	{

	}
	else
	{
		switch(PUPD_Option)
		{
		case INPUT_FLOATING:
			switch(portId)
			{
			case GPIOA:
				CLR_BIT(GPIOA_PUPDR, (pinId*2));
				CLR_BIT(GPIOA_PUPDR, ((pinId*2)+1));
				break;

			case GPIOB:
				CLR_BIT(GPIOB_PUPDR, (pinId*2));
				CLR_BIT(GPIOB_PUPDR, ((pinId*2)+1));
				break;

			case GPIOC:
				CLR_BIT(GPIOC_PUPDR, (pinId*2));
				CLR_BIT(GPIOC_PUPDR, ((pinId*2)+1));
				break;

			default:
				break;
			}
			break;
			case INPUT_PU:
				switch(portId)
				{
				case GPIOA:
					SET_BIT(GPIOA_PUPDR, (pinId*2));
					CLR_BIT(GPIOA_PUPDR, ((pinId*2)+1));
					break;

				case GPIOB:
					SET_BIT(GPIOB_PUPDR, (pinId*2));
					CLR_BIT(GPIOB_PUPDR, ((pinId*2)+1));
					break;

				case GPIOC:
					SET_BIT(GPIOC_PUPDR, (pinId*2));
					CLR_BIT(GPIOC_PUPDR, ((pinId*2)+1));
					break;

				default:
					break;
				}
				break;
				case INPUT_PD:
					switch(portId)
					{
					case GPIOA:
						CLR_BIT(GPIOA_PUPDR, (pinId*2));
						SET_BIT(GPIOA_PUPDR, ((pinId*2)+1));
						break;

					case GPIOB:
						CLR_BIT(GPIOB_PUPDR, (pinId*2));
						SET_BIT(GPIOB_PUPDR, ((pinId*2)+1));
						break;

					case GPIOC:
						CLR_BIT(GPIOC_PUPDR, (pinId*2));
						SET_BIT(GPIOC_PUPDR, ((pinId*2)+1));
						break;

					default:
						break;
					}
					break;

					default:
						break;
		}
	}
}

void GPIO_setPortValue(u8 portId, u32 value)
{
	/*I/P Validation*/
	if((portId > GPIOC))
	{

	}
	else
	{
		switch(portId)
		{
		case GPIOA:	GPIOA_ODR = value;
		break;

		case GPIOB:	GPIOB_ODR = value;
		break;

		case GPIOC:	GPIOC_ODR = value;
		break;

		default:
			break;
		}
	}
}

/*Copy_u8Signal: PIN_SET, PIN_RST*/
void GPIO_setPinValueDirectAccess(u8 portId, u8 pinId, u8 signal)
{
	if((portId > GPIOC) || (pinId > PIN15) || (signal > PIN_RST))
	{

	}
	else
	{
		switch(signal)
		{
		case PIN_SET:
			switch(portId)
			{
			case GPIOA:
				GPIOA_BSRR = (1 << pinId);
				break;

			case GPIOB:
				GPIOB_BSRR = (1 << pinId);
				break;

			case GPIOC:	GPIOC_BSRR = (1 << pinId);
			break;
			}

			break;
			case PIN_RST:
				switch(portId)
				{
				case GPIOA:
					GPIOA_BSRR = (1 << (pinId+16));
					break;

				case GPIOB:
					GPIOB_BSRR = (1 << (pinId+16));
					break;

				case GPIOC:
					GPIOC_BSRR = (1 << (pinId+16));
					break;
				}
				break;
		}
	}
}

u8 GPIO_getPinValue(u8 portId, u8 pinId)
{
	u8 pinValue = 0;

	if((portId > GPIOC) || (pinId > PIN15))
	{

	}
	else
	{
		switch(portId)
		{
		case GPIOA:	pinValue = GET_BIT(GPIOA_IDR,pinId);
		break;
		case GPIOB: pinValue = GET_BIT(GPIOB_IDR,pinId);
		break;
		case GPIOC:	pinValue = GET_BIT(GPIOC_IDR,pinId);
		break;
		}
	}
	return pinValue;
}
