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

#include "sample.h"
#include "project.h"
#include "interrupt.h"


/*****************************************************************************\
 * Function:    doInit
 * Description: 
 *     Initialization of peripherals and variables.
\*****************************************************************************/

void doInit(){
    
    CyGlobalIntEnable;

    AMux_Init();
    ADC_Start();
    UART_Start();
    PWM_Start();
    PIN_BUILTIN_LED_Write(1);
    Timer_Start();
    isr_ADC_StartEx(Custom_isr_ADC);
    isr_UART_StartEx(Custom_isr_UART);
    
    PacketReadyFlag=0;
    channel = CHANNEL_PHOTO;
    DataBuffer[0] = 0xA0;
    DataBuffer[TRANSMIT_BUFFER_SIZE-1] = 0xC0;
    isKeyPressed = 0;
    PIN_LED_Write(0);
}


/*****************************************************************************\
 * Function:    doSample
 * Input:       value (ADC sampling value)
 * Description: 
 *     Storing data from the two sensors
\*****************************************************************************/

void doSample(int16 value){
    
    // if ADC is out of bound --> resizing
    if (value < 0) value = 0;
    if (value > 255) value = 255;

    // populating the array
    DataBuffer[channel+1] = value;
    
    channel = (channel+1)%2;
    // setting the analogic multiplexer channel
    AMux_FastSelect(channel);
    
}
