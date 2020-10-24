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

#include "interrupt.h"

CY_ISR_PROTO(Custom_isr_ADC){
    Timer_ReadStatusRegister();
    PacketReadyFlag=1;
}

/* [] END OF FILE */
