/******************************************************************************
 *
 * Module: tft
 *
 * File Name: tft.h
 *
 * Description: Header file for the ARM TFT driver
 *
 * Author: Toka Refaat
 *
 *******************************************************************************/

#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H

#include "STD_TYPES.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define TFT_RST_PIN			GPIOA, PIN4
#define TFT_A0_PIN			GPIOA, PIN3

#define SLP_OUT_CMD		0x11

/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/
void TFT_init(void);
void TFT_displayImage(u16* ImageArr);


#endif
