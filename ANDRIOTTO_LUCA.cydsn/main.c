/* ========================================
 * Luca Andriotto, Assignment #4
 * ========================================
*/

#include "states.h"

int main(void){
    
    // Initialization
    doInit();

    // Executing the state machine
    for(;;) doStateMachine();

}