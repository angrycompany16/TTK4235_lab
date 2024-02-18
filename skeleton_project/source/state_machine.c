#include "state_machine.h"

void behaviour(State* p_current_state){
    
    switch(*p_current_state) {
        case UP_EMPTY: // eller tall?
            elevio_motorDirection(DIRN_UP);
            break;
        case UP_UNEMPTY:
            elevio_motorDirection(DIRN_UP);
            break;
        case DOWN_EMPTY:
            printf("State: %d\n",*p_current_state);
            elevio_motorDirection(DIRN_DOWN);
            break;
        case DOWN_UNEMPTY:
            elevio_motorDirection(DIRN_DOWN);
            break;
        case STATIONARY_EMPTY:
            // do something
            break;
        case STATIONARY_UNEMPTY: 
            // do something
            break;
    }

}


void transition(State* p_current_state, Trigger trigger){
    // variable = (condition) ? expressionTrue : expressionFalse;
    switch(*p_current_state) {
        case UP_EMPTY: 
            switch(trigger){
                case 0:
                    // do something
                    break;
                case 1: 
                    // do something
                    break;
                case 2: 
                    // do something
                    break;
            }
            break;
        case UP_UNEMPTY: 
            switch(trigger){
                case 0:
                    // do something
                    break;
                case 1: 
                    // do something
                    break;
                case 2: 
                    // do something
                    break;
            }
            break;
        case DOWN_EMPTY: 
            switch(trigger){
                case 0:
                    // do something
                    break;
                case 1: 
                    // do something
                    break;
                case 2: 
                    printf("State: %d \nTrigger: %d",*p_current_state, trigger);
                    break;
            }
            break;
        case DOWN_UNEMPTY: 
            switch(trigger){
                case 0:
                    // do something
                    break;
                case 1: 
                    // do something
                    break;
                case 2: 
                    // do something
                    break;
            }
            break;
        case STATIONARY_EMPTY: 
            switch(trigger){
                case 0:
                    // do something
                    break;
                case 1: 
                    // do something
                    break;
                case 2: 
                    // do something
                    break;
            }
            break;
        case STATIONARY_UNEMPTY: 
            switch(trigger){
                case 0:
                    // do something
                    break;
                case 1: 
                    // do something
                    break;
                case 2: 
                    // do something
                    break;
            }
            break;
    }
    
}