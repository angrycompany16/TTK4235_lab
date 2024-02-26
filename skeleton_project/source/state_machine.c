#include "state_machine.h"

void behaviour(State* p_current_state){
    
    switch(*p_current_state) {
        // RETNING FULLHET DØR OBSTRUKSJON
        case UP_EMPTY:
            // opp tom lukket false
            elevio_motorDirection(DIRN_UP);
            break;
        case UP_UNEMPTY:
            // opp utom lukket false
            elevio_motorDirection(DIRN_UP);
            break;
        case DOWN_EMPTY:
            printf("State: %d\n",*p_current_state); //test
            // ned tom lukket false
            elevio_motorDirection(DIRN_DOWN);
            break;
        case DOWN_UNEMPTY:
            // ned utom lukket false
            elevio_motorDirection(DIRN_DOWN);
            break;
        case OPEN_EMPTY:
            // stille tom åpen false
            elevio_motorDirection(DIRN_STOP);
            break;
        case OPEN_UNEMPTY: 
            // stille utom åpen false
            elevio_motorDirection(DIRN_STOP);
            break;
        case CLOSED_EMPTY:
            // stille tom lukket false
            elevio_motorDirection(DIRN_STOP);
            break;
        case CLOSED_UNEMPTY:
            // stille utom lukket false
            elevio_motorDirection(DIRN_STOP);
            break;
        case BLOCKED_EMPTY:
            // stille tom åpen true
            elevio_motorDirection(DIRN_STOP);
            break;
        case BLOCKED_UNEMPTY:
            // stille utom åpen true
            elevio_motorDirection(DIRN_STOP);
            break;
    }
}


void transition(State* p_current_state, Trigger trigger){

    switch(*p_current_state) {

        case UP_EMPTY: 
            switch(trigger){
                case STOP:
                    // do something
                    break;
                case ENTERED_FLOOR: 
                    // do something
                    break;
                case OBSTRUCTION:
                    // do something
                    break;
                case TIMER:
                    // do something
                    break;
                case UP:
                    // do something
                    break;
                case DOWN:
                    // do something
                    break;
                case STAY:
                    // do something
                    break;
                default:
                    // do something
                    ;
            }
            break;

        case UP_UNEMPTY: 
            switch(trigger){
                case STOP:
                    // do something
                    break;
                case ENTERED_FLOOR: 
                    // do something
                    break;
                case OBSTRUCTION:
                    // do something
                    break;
                case TIMER:
                    // do something
                    break;
                case UP:
                    // do something
                    break;
                case DOWN:
                    // do something
                    break;
                case STAY:
                    // do something
                    break;
                default:
                    // do something
                    ;
            }
            break;
        
        case DOWN_EMPTY: 
            switch(trigger){
                case STOP:
                    // do something
                    break;
                case ENTERED_FLOOR: 
                    // do something
                    break;
                case OBSTRUCTION:
                    // do something
                    break;
                case TIMER:
                    // do something
                    break;
                case UP:
                    // do something
                    break;
                case DOWN:
                    // do something
                    break;
                case STAY:
                    // do something
                    break;
                default:
                    // do something
                    ;
            }
            break;
        
        case DOWN_UNEMPTY: 
            switch(trigger){
                case STOP:
                    // do something
                    break;
                case ENTERED_FLOOR: 
                    // do something
                    break;
                case OBSTRUCTION:
                    // do something
                    break;
                case TIMER:
                    // do something
                    break;
                case UP:
                    // do something
                    break;
                case DOWN:
                    // do something
                    break;
                case STAY:
                    // do something
                    break;
                default:
                    // do something
                    ;
            }
            break;
        
        case OPEN_EMPTY: 
            switch(trigger){
                case STOP:
                    // do something
                    break;
                case ENTERED_FLOOR: 
                    // do something
                    break;
                case OBSTRUCTION:
                    // do something
                    break;
                case TIMER:
                    // do something
                    break;
                case UP:
                    // do something
                    break;
                case DOWN:
                    // do something
                    break;
                case STAY:
                    // do something
                    break;
                default:
                    // do something
                    ;
            }
            break;

        case OPEN_UNEMPTY: 
            switch(trigger){
                case STOP:
                    // do something
                    break;
                case ENTERED_FLOOR: 
                    // do something
                    break;
                case OBSTRUCTION:
                    // do something
                    break;
                case TIMER:
                    // do something
                    break;
                case UP:
                    // do something
                    break;
                case DOWN:
                    // do something
                    break;
                case STAY:
                    // do something
                    break;
                default:
                    // do something
                    ;
            }
            break;

        case CLOSED_EMPTY: 
            switch(trigger){
                case STOP:
                    // do something
                    break;
                case ENTERED_FLOOR: 
                    // do something
                    break;
                case OBSTRUCTION:
                    // do something
                    break;
                case TIMER:
                    // do something
                    break;
                case UP:
                    // do something
                    break;
                case DOWN:
                    // do something
                    break;
                case STAY:
                    // do something
                    break;
                default:
                    // do something
                    ;
            }
            break;
        
        case CLOSED_UNEMPTY: 
            switch(trigger){
                case STOP:
                    // do something
                    break;
                case ENTERED_FLOOR: 
                    // do something
                    break;
                case OBSTRUCTION:
                    // do something
                    break;
                case TIMER:
                    // do something
                    break;
                case UP:
                    // do something
                    break;
                case DOWN:
                    // do something
                    break;
                case STAY:
                    // do something
                    break;
                default:
                    // do something
                    ;
            }
            break;
        
        case BLOCKED_EMPTY: 
            switch(trigger){
                case STOP:
                    // do something
                    break;
                case ENTERED_FLOOR: 
                    // do something
                    break;
                case OBSTRUCTION:
                    // do something
                    break;
                case TIMER:
                    // do something
                    break;
                case UP:
                    // do something
                    break;
                case DOWN:
                    // do something
                    break;
                case STAY:
                    // do something
                    break;
                default:
                    // do something
                    ;
            }
            break;

        case BLOCKED_UNEMPTY: 
            switch(trigger){
                case STOP:
                    // do something
                    break;
                case ENTERED_FLOOR: 
                    // do something
                    break;
                case OBSTRUCTION:
                    // do something
                    break;
                case TIMER:
                    // do something
                    break;
                case UP:
                    // do something
                    break;
                case DOWN:
                    // do something
                    break;
                case STAY:
                    // do something
                    break;
                default:
                    // do something
                    ;
            }
            break;
    }
    
}