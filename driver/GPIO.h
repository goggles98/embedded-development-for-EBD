/******************************************************************************
* File Name: GPIO.h
* Description: This file contains function Prototypes of GPIO.c
* Tool-Chain: AVR GCC
*
* Created by: 2005557_Viraj 16/Feb/21
*
******************************************************************************/
#ifndef GPIO_H
#define GPIO_H

/******************************************************************************
* Includes
******************************************************************************/
#include <avr/io.h>

/******************************************************************************
* Defines and data types
******************************************************************************/
#define INPUT 0
#define OUTPUT 1
#define LOW 0
#define HIGH 1
#define SET_BIT(PORT, BIT) PORT |= (1 << BIT)
#define CLR_BIT(PORT, BIT) PORT &= ~(1 << BIT)

/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Public function prototypes
******************************************************************************/
void GPIO_config(uint8_t PIN, uint8_t STATE);       // configures the state of the pin
void GPIO_pin_write(uint8_t PIN, uint8_t MODE);     // writes to the pin
uint8_t GPIO_pin_read(uint8_t PIN);                 // reads the state of the pin

#endif
/******************************************************************************
* End of File
******************************************************************************/
