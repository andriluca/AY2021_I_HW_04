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
 *     Initialization of peripherals
\*****************************************************************************/

void doInit(){
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    AMux_Init();
    ADC_Start();
    Timer_Start();
    UART_Start();
    isr_ADC_StartEx(Custom_isr_ADC);
    
    PacketReadyFlag=0;
    channel = CHANNEL_POT;

}


/*****************************************************************************\
 * Function:    doSample
 * Input:       value (ADC sampling value)
 * Description: 
 *     Storing data from the two sensors
\*****************************************************************************/

void doSample(int32 value){
    
    // setting the analogic multiplexer channel
    AMux_FastSelect(channel);
    // if ADC is out of bound --> resizing
    if (value < 0) value = 0;
    if (value > 65535) value = 65535;

    // populating the array
    sensorData[channel]=value;

    PacketReadyFlag = 0;
    channel = (channel+1)%2;

}
