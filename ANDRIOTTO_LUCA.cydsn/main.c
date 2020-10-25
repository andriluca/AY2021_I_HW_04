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
#include "sample.h"


int main(void)
{

    doInit();

    for(;;){
        if(PacketReadyFlag){
            for (ch = 0; ch <= CHANNEL_PHOTO; ch++) doSample(ADC_Read16());
            UART_PutArray(DataBuffer,TRANSMIT_BUFFER_SIZE);
            PacketReadyFlag = 0;
        }
            
        if(PacketReadyFlag && DataBuffer[BYTE_PHOTO] < THRESHOLD_PHOTO) PWM_WriteCompare(DataBuffer[BYTE_POT]);
        if(PacketReadyFlag && !(DataBuffer[BYTE_PHOTO] < THRESHOLD_PHOTO)) PWM_WriteCompare(0);
    }
}