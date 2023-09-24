/******************************************************************************
 *
 * Module: tft
 *
 * File Name: tft.c
 *
 * Description: Source file for the ARM TFT driver
 *
 * Author: Toka Refaat
 *
 *******************************************************************************/
/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "gpio.h"
#include "systick.h"

#include "tft.h"
#include "tft.h"

/*******************************************************************************
 *                              Private Functions                              *
 *******************************************************************************/
static void Private_sendCmd(u8 command);
static void Private_sendData(u8 data);
static void Private_sendResetPulse(void);

/*******************************************************************************
 *                              Function Definitions                           *
 *******************************************************************************/
void TFT_init(void)
{
	/*1- Reset Pulse sequence*/
	Private_sendResetPulse();

	/*2- Sleep out Command*/
	Private_sendCmd(SLP_OUT_CMD);

	/*3- Delay 10 ms*/
	STK_setBusyWait(10000);

	/*4.1 - Colored Mode*/
	Private_sendCmd(0x3A);

	/*4.2 - RGB565 selection*/
	Private_sendData(0x05);

	/*5- Display ON*/
	Private_sendCmd(0x29);
}

void TFT_displayImage(u16* ImageArr)
{
	u32 counter;
	u8 low;
	u8 high;

	/*Set x Dimensions Command*/
	Private_sendCmd(0x2A);

	/*Start of x*/
	Private_sendData(0);
	Private_sendData(0);

	/*End of x*/
	Private_sendData(0);
	Private_sendData(127);

	/*Set y Dimensions Command*/
	Private_sendCmd(0x2B);

	/*Start of x*/
	Private_sendData(0);
	Private_sendData(0);

	/*End of x*/
	Private_sendData(0);
	Private_sendData(159);

	/*Ram memory write*/
	Private_sendCmd(0x2C);

	/*Write on TFT Pixel by Pixel - MSB First, each pixel is 2B, at each time --> 1B*/
	for(counter = 0; counter < 20480; counter++)
	{
		low = (u8) ImageArr[counter];
		high =(u8) (ImageArr[counter]>>8);
		Private_sendData(high);
		Private_sendData(low);
	}
}

static void Private_sendCmd(u8 command)
{
	u8 Temp=0;

	/*Select Command mode*/
	GPIO_setPinValueDirectAccess(TFT_A0_PIN, PIN_RST);

	/*Send Command*/
	SPI_Tranceive(command, &Temp);

}

static void Private_sendData(u8 data)
{
	u8 Temp=0;
	/*Select Data mode*/
	GPIO_setPinValueDirectAccess(TFT_A0_PIN, PIN_SET);
	/*Send Data*/
	SPI_Tranceive(data, &Temp);
	//(void)SPI_voidTranceive(Copy_u8Command);
}

static void Private_sendResetPulse(void)
{
	GPIO_setPinValueDirectAccess(TFT_RST_PIN, PIN_SET);
	STK_setBusyWait(1000);

	GPIO_setPinValueDirectAccess(TFT_RST_PIN, PIN_RST);
	STK_setBusyWait(10);

	GPIO_setPinValueDirectAccess(TFT_RST_PIN, PIN_SET);
	STK_setBusyWait(1000);

	GPIO_setPinValueDirectAccess(TFT_RST_PIN, PIN_RST);
	STK_setBusyWait(100000);

	GPIO_setPinValueDirectAccess(TFT_RST_PIN, PIN_SET);
	STK_setBusyWait(120000);
}
