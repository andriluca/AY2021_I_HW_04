/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "interrupt.h"
#include "stdio.h"

void doInit();

int32 value_digit;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    doInit();

    for(;;){
        if(PacketReadyFlag){
            value_digit = ADC_Read32();
            PacketReadyFlag=0;
            if (value_digit < 0) value_digit = 0;
            if (value_digit > 65535) value_digit = 65535;
            sprintf(DataBuffer,"%ld\r\n",value_digit);
            UART_PutString(DataBuffer);
        }
    }
}

/*****************************************************************************\
 * Function:    doInit
 * Description: 
 *     Initialization of peripherals
\*****************************************************************************/

void doInit(){
    AMux_Init();
    AMux_FastSelect(1);
    ADC_Start();
    Timer_Start();
    UART_Start();
    isr_ADC_StartEx(Custom_isr_ADC);
    
    PacketReadyFlag=0;
}