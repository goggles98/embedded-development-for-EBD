/******************************************************************************
* File Name: system.c
* Description: This file contains API definitions for GPIO functionality
* Tool-Chain: AVR GCC
*
* Created by: 2005557_Viraj 16/Feb/21
******************************************************************************/

/******************************************************************************
* Includes
******************************************************************************/
#include "system.h"

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
* Name: Init_GPIO()
* Description: Configures all the GPIO pins to be used as inputs or outputs
* Arguments: None
* Returns: None
  ------------------------------------------------------------------------  */
void Init_GPIO()
{
    GPIO_config(PD0, OUTPUT);       // brake pedal light
    GPIO_config(PD1, OUTPUT);       // EBD on light
    GPIO_config(PD2, OUTPUT);       // ABS on light
    GPIO_config(PD4, INPUT);        // brake pedal input pin
}

/* ---------------------------------------------------------------------------
* Name: Init_PWM()
* Description: Configures the PWM module as phase correct PWM and the compare pins as output
* Arguments: None
* Returns: None
  ------------------------------------------------------------------------  */
void Init_PWM()
{
    Timer0_Config();        // configures timer0
    Timer2_Config();        // configures timer2
}

/* ---------------------------------------------------------------------------
* Name: Init_ADC()
* Description: Configures the ADC module in free running mode
* Arguments: None
* Returns: None
  ------------------------------------------------------------------------  */
void Init_ADC()
{
    ADC_Config();
}

/* ---------------------------------------------------------------------------
* Name: System_Init()
* Description: Calls all the Init functions written above
* Arguments: None
* Returns: None
  ------------------------------------------------------------------------  */
void System_Init()
{
    Init_GPIO();
    Init_PWM();
    Init_ADC();
}

/* ---------------------------------------------------------------------------
* Name: Pedal_Pressed()
* Description: Checks if the brake pedal is pressed or no
* Arguments: None
* Returns: uint8_t pressed
  ------------------------------------------------------------------------  */
uint8_t Pedal_Pressed()
{
    uint8_t pressed = GPIO_pin_read(4);
    return pressed;
}

/* ---------------------------------------------------------------------------
* Name: Activate_EBD_Indicator()
* Description: Turn on EBD light
* Arguments: None
* Returns: None
  ------------------------------------------------------------------------  */
void Activate_ABS_Indicator()
{
    SET_BIT(DDRC, 6);
    SET_BIT(PORTC, 6);
    //GPIO_pin_write(PD1, HIGH);
}

/* ---------------------------------------------------------------------------
* Name: Deactivate_EBD_Indicator()
* Description: Turn off EBD light
* Arguments: None
* Returns: None
  ------------------------------------------------------------------------  */
void Deactivate_ABS_Indicator()
{
    CLR_BIT(PORTC, 6);
}

/* ---------------------------------------------------------------------------
* Name: Get_Slip_Ratio()
* Description: Read Slip Ratio Value from ABS Algo, in the code, turn the ADC knob at ADC0
* Arguments: None
* Returns: uint16_t Slip value in 10-bit resolution
  ------------------------------------------------------------------------  */
uint16_t Get_Slip_Ratio()
{
    uint16_t slip_ratio = ADC_Convert_Channel0();
    return slip_ratio;
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
