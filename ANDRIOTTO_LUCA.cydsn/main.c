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

int32 value_digit;

int main(void)
{

    doInit();

    for(;;){
        if(PacketReadyFlag){
            
            for (ch = 0; ch <= CHANNEL_PHOTO; ch++) doSample(ADC_Read32());
            
            sprintf(DataBuffer,"%ld \t %ld\r\n",sensorData[0],sensorData[1]);
            UART_PutString(DataBuffer);
        }
    }
}