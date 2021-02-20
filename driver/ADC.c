/******************************************************************************
* File Name: ADC.c
* Description: This file contains API definitions for GPIO functionality
* Tool-Chain: AVR GCC
*
* Created by: 2005557_Viraj 16/Feb/21
******************************************************************************/

/******************************************************************************
* Includes
******************************************************************************/
#include "ADC.h"

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
* Name: ADC_Config ()
* Description: Configures the ADC in free-running mode, AVcc as ref, prescalar as 128
* Arguments: None
* Returns: None
  ------------------------------------------------------------------------  */
void ADC_Config()
{
    ADMUX = 0x40;       // ADMUX6 = 1 ---- AVcc as reference
    ADCSRB = 0x00;      // free-running mode selected
    ADCSRA = 0x07;      // ADCSRA2:0 = 111 ----- 128 prescalar
}

/* ---------------------------------------------------------------------------
* Name: ADC_Convert_Channel0 ()
* Description: Selects channel 0 and converts it once
* Arguments: None
* Returns: uint8_16 ADC value
  ------------------------------------------------------------------------  */
uint16_t ADC_Convert_Channel0()
{
    CLR_BIT(ADMUX, 2);
    CLR_BIT(ADMUX, 1);
    CLR_BIT(ADMUX, 0);      // channel 0 selected, ADMUX2:0 = 000

    SET_BIT(ADCSRA, 7);     // ADEN set
    SET_BIT(ADCSRA, 6);     // ADSC set

    while(ADCSRA & (1 << ADSC));        // till conversion is on, wait
    uint16_t result = ADC;

    CLR_BIT(ADCSRA, 7);     // clear ADEN, shut the ADC
    return result;
}

/* ---------------------------------------------------------------------------
* Name: ADC_Convert_Channel1 ()
* Description: Selects channel 1 and converts it once
* Arguments: None
* Returns: uint8_16 ADC value
  ------------------------------------------------------------------------  */
uint16_t ADC_Convert_Channel1()
{
    CLR_BIT(ADMUX, 2);
    CLR_BIT(ADMUX, 1);
    SET_BIT(ADMUX, 0);      // channel 1 selected, ADMUX2:0 = 001

    SET_BIT(ADCSRA, 7);     // ADEN set
    SET_BIT(ADCSRA, 6);     // ADSC set

    while(ADCSRA & (1 << ADSC));        // till conversion is on, wait
    uint16_t result = ADC;

    CLR_BIT(ADCSRA, 7);     // clear ADEN, shut the ADC
    return result;
}

/* ---------------------------------------------------------------------------
* Name: ADC_Convert_Channel2 ()
* Description: Selects channel 2 and converts it once
* Arguments: None
* Returns: uint8_16 ADC value
  ------------------------------------------------------------------------  */
uint16_t ADC_Convert_Channel2()
{
    CLR_BIT(ADMUX, 2);
    SET_BIT(ADMUX, 1);
    CLR_BIT(ADMUX, 0);      // channel 1 selected, ADMUX2:0 = 010

    SET_BIT(ADCSRA, 7);     // ADEN set
    SET_BIT(ADCSRA, 6);     // ADSC set

    while(ADCSRA & (1 << ADSC));        // till conversion is on, wait
    uint16_t result = ADC;

    CLR_BIT(ADCSRA, 7);     // clear ADEN, shut the ADC
    return result;
}

/* ---------------------------------------------------------------------------
* Name: ADC_Convert_Channel3 ()
* Description: Selects channel 3 and converts it once
* Arguments: None
* Returns: uint8_16 ADC value
  ------------------------------------------------------------------------  */
uint16_t ADC_Convert_Channel3()
{
    CLR_BIT(ADMUX, 2);
    SET_BIT(ADMUX, 1);
    SET_BIT(ADMUX, 0);      // channel 1 selected, ADMUX2:0 = 011

    SET_BIT(ADCSRA, 7);     // ADEN set
    SET_BIT(ADCSRA, 6);     // ADSC set

    while(ADCSRA & (1 << ADSC));        // till conversion is on, wait
    uint16_t result = ADC;

    CLR_BIT(ADCSRA, 7);     // clear ADEN, shut the ADC
    return result;
}

/* ---------------------------------------------------------------------------
* Name: ADC_Convert_Channel4 ()
* Description: Selects channel 4 and converts it once
* Arguments: None
* Returns: uint8_16 ADC value
  ------------------------------------------------------------------------  */
uint16_t ADC_Convert_Channel4()
{
    SET_BIT(ADMUX, 2);
    CLR_BIT(ADMUX, 1);
    CLR_BIT(ADMUX, 0);      // channel 1 selected, ADMUX2:0 = 100

    SET_BIT(ADCSRA, 7);     // ADEN set
    SET_BIT(ADCSRA, 6);     // ADSC set

    while(ADCSRA & (1 << ADSC));        // till conversion is on, wait
    uint16_t result = ADC;

    CLR_BIT(ADCSRA, 7);     // clear ADEN, shut the ADC
    return result;
}

/* ---------------------------------------------------------------------------
* Name: ADC_Convert_Channel5 ()
* Description: Selects channel 5 and converts it once
* Arguments: None
* Returns: uint8_16 ADC value
  ------------------------------------------------------------------------  */
uint16_t ADC_Convert_Channel5()
{
    SET_BIT(ADMUX, 2);
    CLR_BIT(ADMUX, 1);
    SET_BIT(ADMUX, 0);      // channel 1 selected, ADMUX2:0 = 101

    SET_BIT(ADCSRA, 7);     // ADEN set
    SET_BIT(ADCSRA, 6);     // ADSC set

    while(ADCSRA & (1 << ADSC));        // till conversion is on, wait
    uint16_t result = ADC;

    CLR_BIT(ADCSRA, 7);     // clear ADEN, shut the ADC
    return result;
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
