/******************************************************************************
 *
 * Module: spi
 *
 * File Name: spi.h
 *
 * Description: Header file for the ARM SPI driver
 *
 * Author: Toka Refaat
 *
 *******************************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "STD_TYPES.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define TFT_CS_PIN			GPIOA, PIN2

/*******************************************************************************
 *                               Registers Definitions                         *
 *******************************************************************************/
typedef struct
{
    volatile u32 CR1;
    volatile u32 RES;
    volatile u32 SR;
    volatile u32 DR;
}SPI_t;

#define SPI1         ((volatile SPI_t*)0x40013000)

/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/
void SPI_init();
void SPI_Tranceive(u8 dataToBeTransmitted, u8* dataToBeRecieved);


#endif
