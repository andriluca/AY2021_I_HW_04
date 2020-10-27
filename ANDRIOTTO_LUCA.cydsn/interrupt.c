/* ========================================
 * Luca Andriotto, Assignment #4
 * ========================================
*/

#include "interrupt.h"
#include "states.h"


CY_ISR_PROTO(Custom_isr_ADC){
    Timer_ReadStatusRegister();
    PacketReadyFlag=1;
}

CY_ISR_PROTO(Custom_isr_UART){
    doSwitchPhases(UART_GetChar());
}
