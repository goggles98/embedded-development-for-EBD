/******************************************************************************
* File Name: PWM.c
* Description: This file contains API definitions for GPIO functionality
* Tool-Chain: AVR GCC
*
* Created by: 2005557_Viraj 16/Feb/21
******************************************************************************/

/******************************************************************************
* Includes
******************************************************************************/
#include "PWM.h"

/******************************************************************************
* Defines and data types
******************************************************************************/

/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Static variables
******************************************************************************/

/******************************************************************************
* Internal function prototypes
******************************************************************************/

/******************************************************************************
* Public functions definitions
******************************************************************************/

/* ---------------------------------------------------------------------------
* Name: Timer0_Config()
* Description: Configures Timer 0 in Phase Correct PWM and inverting mode
* Arguments: None
* Returns: None
  ------------------------------------------------------------------------  */
void Timer0_Config()
{
    SET_BIT(DDRD, PD5);
    SET_BIT(DDRD, PD6);
    SET_BIT(TCCR0A, 0);     // WGM00 = 1
    CLR_BIT(TCCR0A, 1);     // WGM01 = 0
    CLR_BIT(TCCR0B, 3);     // WGM02 = 0 - phase correct PWM

    TCCR0A |= ((1 << 7) | (1 << 6) | (1 << 5) | (1 << 4));  // inverting mode for 0C0A and OC0B
}

/* ---------------------------------------------------------------------------
* Name: Timer2_Config()
* Description: Configures Timer 2 in Phase Correct PWM and inverting mode
* Arguments: None
* Returns: None
  ------------------------------------------------------------------------  */
void Timer2_Config()
{
    SET_BIT(DDRD, PD3);
    SET_BIT(DDRB, PB3);
    SET_BIT(TCCR2A, 0);     // WGM00 = 1
    CLR_BIT(TCCR2A, 1);     // WGM01 = 0
    CLR_BIT(TCCR2B, 3);     // WGM02 = 0 - phase correct PWM

    TCCR2A |= ((1 << 7) | (1 << 6) | (1 << 5) | (1 << 4));  // inverting mode for 0C0A and OC0B
}

/* ---------------------------------------------------------------------------
* Name: Set_OCR0A(uint8_t val)
* Description: Sets the value of 0C0A register
* Arguments: uint8_t value
* Returns: None
  ------------------------------------------------------------------------  */
void Set_OCR0A(uint8_t val)
{
    OCR0A = 255 - (val*255/100);
}

/* ---------------------------------------------------------------------------
* Name: Set_OCR0B(uint8_t val)
* Description: Sets the value of 0C0B register
* Arguments: uint8_t value
* Returns: None
  ------------------------------------------------------------------------  */
void Set_OCR0B(uint8_t val)
{
    OCR0B = 255 - (val*255/100);
}

/* ---------------------------------------------------------------------------
* Name: Set_OCR2A(uint8_t val)
* Description: Sets the value of 0C2A register
* Arguments: uint8_t value
* Returns: None
  ------------------------------------------------------------------------  */
void Set_OCR2A(uint8_t val)
{
    OCR2A = 255 - (val*255/100);
}

/* ---------------------------------------------------------------------------
* Name: Set_OCR2B(uint8_t val)
* Description: Sets the value of 0C2B register
* Arguments: uint8_t value
* Returns: None
  ------------------------------------------------------------------------  */
void Set_OCR2B(uint8_t val)
{
    OCR2B = 255 - (val*255/100);
}

/* ---------------------------------------------------------------------------
* Name: Start_Timer0()
* Description: Sets the timer with prescalar of 1024
* Arguments: None
* Returns: None
  ------------------------------------------------------------------------  */
void Start_Timer0()
{
    SET_BIT(TCCR0B, 2);     // CS02 = 1
    CLR_BIT(TCCR0B, 1);     // CS01 = 0
    SET_BIT(TCCR0B, 0);     // CS00 = 1 - timer prescalar of 1024
}

/* ---------------------------------------------------------------------------
* Name: Stop_Timer0()
* Description: Stops timer 0
* Arguments: None
* Returns: None
  ------------------------------------------------------------------------  */
void Stop_Timer0()
{
    CLR_BIT(TCCR0B, 2);     // CS02 = 0
    CLR_BIT(TCCR0B, 1);     // CS01 = 0
    CLR_BIT(TCCR0B, 0);     // CS00 = 0 - timer stopped
}

/* ---------------------------------------------------------------------------
* Name: Start_Timer2()
* Description: Sets the timer 2 with prescalar of 1024
* Arguments: None
* Returns: None
  ------------------------------------------------------------------------  */
void Start_Timer2()
{
    SET_BIT(TCCR2B, 2);     // CS02 = 1
    SET_BIT(TCCR2B, 1);     // CS01 = 1
    SET_BIT(TCCR2B, 0);     // CS00 = 1 - timer prescalar of 1024
}

/* ---------------------------------------------------------------------------
* Name: Stop_Timer2()
* Description: Stops timer 2
* Arguments: None
* Returns: None
  ------------------------------------------------------------------------  */
void Stop_Timer2()
{
    CLR_BIT(TCCR0B, 2);     // CS02 = 0
    CLR_BIT(TCCR0B, 1);     // CS01 = 0
    CLR_BIT(TCCR0B, 0);     // CS00 = 0 - timer stopped
}
/******************************************************************************
* Internal functions
******************************************************************************/

/* ****************************************************************************
* Name:
* Description:
******************************************************************************/

/******************************************************************************
* End of File
******************************************************************************/
