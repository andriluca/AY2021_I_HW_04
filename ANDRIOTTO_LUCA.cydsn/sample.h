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
#ifndef __SAMPLE_H
    #define __SAMPLE_H
    #include "cytypes.h"
    
    #define CHANNEL_PHOTO   0
    #define CHANNEL_POT     1
    
    void doInit();
    void doSample(int32 value);

    
    volatile uint8 channel;
    int32 sensorData[2];
    uint8 ch;
#endif


/* [] END OF FILE */
