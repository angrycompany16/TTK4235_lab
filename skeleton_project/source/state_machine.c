#include "state_machine.h"

void behaviour(State* p_current_state){
    
    switch(*p_current_state) {
        case 0: 
            // do something
            break;
        case 1: 
            printf("State: %d\n",*p_current_state);
            break;
        case 2: 
            // do something
            break;
        case 3: 
            // do something
            break;
        case 4: 
            // do something
            break;
        case 5: 
            // do something
            break;
    }

}


void transition(State* p_current_state, Trigger trigger){
    
    switch(*p_current_state) {
        case 0: 
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
        case 1: 
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
        case 2: 
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
        case 3: 
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
        case 4: 
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
        case 5: 
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