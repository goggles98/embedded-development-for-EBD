/******************************************************************************
* File Name: main.c
* Description: This file contains API definitions for GPIO functionality
* Tool-Chain: AVR GCC
*
* Created by: 2005557_Viraj 16/Feb/21
******************************************************************************/

/******************************************************************************
* Includes
******************************************************************************/
#include <avr/io.h>
#include "system.h"
#include "read_wheel_loads.h"

/******************************************************************************
* Defines and data types
******************************************************************************/

/******************************************************************************
* Global variables
******************************************************************************/
uint16_t wheel_load_lf, wheel_load_lr, wheel_load_rf, wheel_load_rr;
uint8_t yaw_left_adjustment, yaw_right_adjustment;
uint8_t duty_cycle_lf, duty_cycle_lr, duty_cycle_rf, duty_cycle_rr;

/******************************************************************************
* Static variables
******************************************************************************/

/******************************************************************************
* Internal function prototypes
******************************************************************************/
void Read_YawRate();
void Adjust_DutyCycles();

/******************************************************************************
* Public functions definitions
******************************************************************************/

/* ---------------------------------------------------------------------------
* Name: main function
* Description: The main function of the PROGRAM
* Arguments: None
* Returns: None
  ------------------------------------------------------------------------  */
void main()
{
    System_Init();

    uint8_t brake_pedal;
    uint16_t slip_ratio;

    while(1)
    {
        brake_pedal = Pedal_Pressed();
        slip_ratio = Get_Slip_Ratio();

        if(brake_pedal == 1) // brake pedal not pressed
        {
            Deactivate_ABS_Indicator();
            Stop_Timer0();
            Stop_Timer2();
        }

        else if(brake_pedal == 0 && slip_ratio > 819)   // brake pedal pressed and wheel slip >= 0.8
        {
            Activate_ABS_Indicator();       // control handed over to ABS
            Stop_Timer0();
            Stop_Timer2();
        }

        else        // pedal pressed and slip < 0.8
        {
            Start_Timer0();
            Start_Timer2();
            Deactivate_ABS_Indicator();

            Read_Load_AllWheels();      // get the loading of all the wheels
            Read_YawRate();
            Adjust_DutyCycles();
        }
    }
}


/******************************************************************************
* Internal functions
******************************************************************************/

/* ****************************************************************************
* Name: Adjust_DutyCycles()
* Description: Adjusts the duty cycles of the PWM outputs
******************************************************************************/
void Adjust_DutyCycles()
{
    duty_cycle_lf = (float)wheel_load_lf / 10.2 + yaw_right_adjustment;
    duty_cycle_lr = (float)wheel_load_lr / 10.2 + yaw_right_adjustment;
    duty_cycle_rf = (float)wheel_load_rf / 10.2 + yaw_left_adjustment;
    duty_cycle_rr = (float)wheel_load_rr / 10.2 + yaw_left_adjustment;

    if(duty_cycle_lf > 100)
    {
        duty_cycle_lf = 100;
    }
    if(duty_cycle_rf > 100)
    {
        duty_cycle_rf = 100;
    }
    if(duty_cycle_lr > 100)
    {
        duty_cycle_lr = 100;
    }
    if(duty_cycle_rr > 100)
    {
        duty_cycle_rr = 100;
    }

    Set_DutyCycle_OCR0A(duty_cycle_lf);
    Set_DutyCycle_OCR0B(duty_cycle_rf);
    Set_DutyCycle_OCR2A(duty_cycle_lr);
    Set_DutyCycle_OCR2B(duty_cycle_rr);
}

/* ****************************************************************************
* Name: Read_YawRate()
* Description: Adjusts the duty cycle based on Yaw rate,
               530 - 500 = no turn
               below 500 - right turn
               above 530 - left turn
******************************************************************************/
void Read_YawRate()
{
    uint16_t absolute_yaw_value = ADC_Convert_Channel5();
    if(absolute_yaw_value > 530)        // indicative of left turn based on potentiometer setting.
    {
        absolute_yaw_value = absolute_yaw_value % 530;
        yaw_left_adjustment = absolute_yaw_value / 30;      // reduce to appreciable levels
    }
    else if(absolute_yaw_value < 500)   // indicative of right turn based on potentiometer setting
    {
        absolute_yaw_value = 500 - absolute_yaw_value;
        yaw_right_adjustment = absolute_yaw_value / 30;
    }
    else
    {
        yaw_left_adjustment = 0;
        yaw_right_adjustment = 0;
    }
}

/******************************************************************************
* End of File
******************************************************************************/
