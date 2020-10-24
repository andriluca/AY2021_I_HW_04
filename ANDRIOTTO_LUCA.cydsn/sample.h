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
    #define BYTE_PHOTO      CHANNEL_PHOTO + 1
    #define CHANNEL_POT     1
    #define THRESHOLD_PHOTO 140
    
    void doInit();
    void doSample(int16 value);

    volatile uint8 channel;
    uint8 ch;
    uint8 isTransmission;
#endif
