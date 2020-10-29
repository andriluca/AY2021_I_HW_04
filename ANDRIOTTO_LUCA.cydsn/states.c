/* ========================================
 * Luca Andriotto, Assignment #4
 * ========================================
*/

#include "states.h"
#include "project.h"
#include "interrupt.h"

void doSample(int16 value);

/*****************************************************************************\
 * Function:    doInit
 * Description: 
 *     Initialization of peripherals and variables.
\*****************************************************************************/

void doInit(){
    
    // Initializing peripherals
    AMux_Init();
    ADC_Start();
    UART_Start();
    PWM_Start();
    
    // Initializing ISRs
    CyGlobalIntEnable;
    isr_ADC_StartEx(Custom_isr_ADC);
    isr_UART_StartEx(Custom_isr_UART);
    
    // Initializing the packet
    DataBuffer[0] = 0xA0;
    DataBuffer[TRANSMIT_BUFFER_SIZE-1] = 0xC0;
    
    // Initializing the variables
    channel = CHANNEL_PHOTO;
    isKeyPressed = 0;
    PIN_LED_Write(0);
    
    // Initial State
    doSwitchPhases(INITIAL_STATE);
}

/*****************************************************************************\
 * Function:    doStateMachine
 * Description: 
 *     Executes the procedures required in the states machine.
\*****************************************************************************/

void doStateMachine(){
    
    // When timeout has occurred
    if(PacketReadyFlag){
        // Sampling all the channels
        for (ch = 0; ch < BYTE_TO_SEND; ch++) doSample(ADC_Read16());
        // Transmitting the results through UART
        UART_PutArray(DataBuffer,TRANSMIT_BUFFER_SIZE);
    }
    
    // When light intensity triggers the Photoresistor.
    if(PacketReadyFlag && DataBuffer[BYTE_PHOTO] < THRESHOLD_PHOTO){
        // Writing the PWM compare with the value of the Potentiometer.
        PWM_WriteCompare(DataBuffer[BYTE_POT]);
        // Resetting the flag to zero.
        PacketReadyFlag = 0;
    }
    
    // When light intensity is not triggering the Photoresistor.
    if(PacketReadyFlag && !(DataBuffer[BYTE_PHOTO] < THRESHOLD_PHOTO)){
        PWM_WriteCompare(0);
        PacketReadyFlag = 0;
    }
}

/*****************************************************************************\
 * Function:    doSample
 * Input:       value (ADC sampling value)
 * Description: 
 *     Storing data from the two sensors.
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

/*****************************************************************************\
 * Function:    doSwitchPhases
 * Input:       phase (uint8 representing an UART transmitted byte)
 * Description: 
 *     Switches the phases of start and stop sending data 
\*****************************************************************************/

void doSwitchPhases(uint8 phase){
    
    // Controlling the phase
    switch(phase){
        
        case 'B':
        case 'b':
            PacketReadyFlag = 1;
            Timer_Start();
            PWM_Start();
            PIN_BUILTIN_LED_Write(1);
            break;
        
        case 'S':
        case 's':
            PacketReadyFlag = 0;
            Timer_Stop();
            PWM_Stop();
            PIN_BUILTIN_LED_Write(0);            
            break;
        
        default:
            break;
    }
}
