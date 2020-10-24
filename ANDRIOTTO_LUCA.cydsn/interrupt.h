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
#ifndef __INTERRUPT_H
    #define __INTERRUPT_H
    #define BYTE_TO_SEND 2
    #define TRANSMIT_BUFFER_SIZE 1 + BYTE_TO_SEND + 1
    #include "cytypes.h"
    #include "Timer.h"
    volatile uint8 PacketReadyFlag;
    
    CY_ISR_PROTO(Custom_isr_ADC);
    CY_ISR_PROTO(Custom_isr_UART);
    uint8 DataBuffer[TRANSMIT_BUFFER_SIZE];
#endif


/* [] END OF FILE */
