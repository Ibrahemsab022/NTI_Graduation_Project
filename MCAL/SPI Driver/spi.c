/******************************************************************************
 *
 * Module: spi
 *
 * File Name: spi.c
 *
 * Description: Source file for the ARM SPI driver
 *
 * Author: Toka Refaat
 *
 *******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "gpio.h"

#include "spi.h"

void SPI_init()
{
	/* CHPA =1
	 * CHPOL = 1
	 * MSTR
	 * SPI Enable
	 * MSB First
	 * Slave Select By Sw
	 * */
	SPI1->CR1 = 0x00000347;
}

void SPI_Tranceive(u8 dataToBeTransmitted, u8* dataToBeRecieved)
{
	//Select slave
	GPIO_setPinValueDirectAccess(TFT_CS_PIN, PIN_RST);
	//Send Data
	SPI1->DR = dataToBeTransmitted;
	//Poll until SPI isn't busy
	while(GET_BIT(SPI1->SR, 7) == 0);
	//Deselect slave
	GPIO_setPinValueDirectAccess(TFT_CS_PIN, PIN_SET);
	//Return Data
	*dataToBeRecieved = (u8) (SPI1->DR);
}
