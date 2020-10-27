/* ========================================
 * Luca Andriotto, Assignment #4
 * ========================================
*/

#ifndef __INTERRUPT_H
    #define __INTERRUPT_H
    #include "cytypes.h"
    #include "project.h"
    
    CY_ISR_PROTO(Custom_isr_ADC);
    CY_ISR_PROTO(Custom_isr_UART);
#endif
