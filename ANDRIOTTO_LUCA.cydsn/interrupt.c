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

#include "interrupt.h"
#include "sample.h"

void doSwitchPhases();

CY_ISR_PROTO(Custom_isr_ADC){
    Timer_ReadStatusRegister();
    PacketReadyFlag=1;
}

CY_ISR_PROTO(Custom_isr_UART){
    doSwitchPhases();
}


/*****************************************************************************\
 * Function:    doSwitchPhases
 * Input:       
 * Returns:     
 * Description: 
 *     Switches the phases of start and stop sending data 
\*****************************************************************************/

void doSwitchPhases(){
    
    switch(UART_GetChar()){
        
        case 'B':
        case 'b':
            PacketReadyFlag = 1;
            Timer_Start();
            PIN_BUILTIN_LED_Write(1);
            break;
        
        case 'S':
        case 's':
            PacketReadyFlag = 0;
            Timer_Stop();
            PIN_BUILTIN_LED_Write(0);            
            break;
        
        default:
            break;
    }
}
