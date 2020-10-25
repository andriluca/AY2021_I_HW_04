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
    #define BYTE_POT        CHANNEL_POT + 1
    #define THRESHOLD_PHOTO 140
    #define BYTE_TO_SEND 2
    #define TRANSMIT_BUFFER_SIZE 1 + BYTE_TO_SEND + 1
    
    uint8 DataBuffer[TRANSMIT_BUFFER_SIZE];
    
    
    void doInit();
    void doSample(int16 value);

    volatile uint8 channel;
    uint8 ch;
    uint8 isTransmission;
    volatile uint8 PacketReadyFlag;
    volatile uint8 isKeyPressed;

    
#endif
