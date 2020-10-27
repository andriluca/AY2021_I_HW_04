/* ========================================
 * Luca Andriotto, Assignment #4
 * ========================================
*/

#ifndef __STATES_H
    #define __STATES_H
    #include "cytypes.h"
    
    /* All the defines of the project */
    // Channels availables
    #define CHANNEL_PHOTO                              0    // Index referred to the AMUX Photoresistor channel
    #define CHANNEL_POT                                1    // Index referred to the AMUX Potentiometer channel
    // Indexes of the bytes
    #define BYTE_PHOTO                 CHANNEL_PHOTO + 1    // Index of the Photoresistor byte.
    #define BYTE_POT                     CHANNEL_POT + 1    // Index of the Potentiometer byte.
    // Buffer defines
    #define BYTE_TO_SEND                               2    // Number of byte to send
    #define TRANSMIT_BUFFER_SIZE    1 + BYTE_TO_SEND + 1    // Dimension of the packet to transmit
    // State defines
    #define THRESHOLD_PHOTO                          140    // Environment light intensity threshold
    #define INITIAL_STATE                            'S'    // if 'S' -> waiting for App activation
                                                            //    'B' -> already started up

    // Declarations
    void doInit();
    void doStateMachine();
    void doSwitchPhases(uint8 phase);

    // Variables
    uint8 DataBuffer[TRANSMIT_BUFFER_SIZE];
    
    uint8 ch;                                               // Counter used to perform a number of samples equal to the number of channels
    volatile uint8 channel;                                 // Keeps track of the next channel to sample
    volatile uint8 PacketReadyFlag;                         // Keeps track of timeout occurring;
    volatile uint8 isKeyPressed;                            // Keeps track of the event associated to key pressing.

#endif
