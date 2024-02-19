#include "FSM.h"

FSM_State* FSM_init(){

    FSM_State* p_current_state;

    *p_current_state = CLOSED_EMPTY;

    return p_current_state;
}

void FSM_behaviour(FSM_State* p_current_state){

    // Ikke tatt hensyn til Stop (timer-cases) og Obstruction enda

    switch(*p_current_state) {
        // RETNING FULLHET DØR OBSTRUKSJON

        case UP_EMPTY:
            // opp tom lukket false
            elevio_motorDirection(DIRN_UP);
            elevio_doorOpenLamp(0);
            break;
        case UP_UNEMPTY:
            // opp utom lukket false
            elevio_motorDirection(DIRN_UP);
            elevio_doorOpenLamp(0);
            break;
        case DOWN_EMPTY:
            // ned tom lukket false
            elevio_motorDirection(DIRN_DOWN);
            elevio_doorOpenLamp(0);
            break;
        case DOWN_UNEMPTY:
            // ned utom lukket false
            elevio_motorDirection(DIRN_DOWN);
            elevio_doorOpenLamp(0);
            break;
        case OPEN_EMPTY:
            // stille tom åpen false
            elevio_motorDirection(DIRN_STOP);
            elevio_doorOpenLamp(1);
            break;
        case OPEN_UNEMPTY: 
            // stille utom åpen false
            elevio_motorDirection(DIRN_STOP);
            elevio_doorOpenLamp(1);
            break;
        case CLOSED_EMPTY:
            // stille tom lukket false
            elevio_motorDirection(DIRN_STOP);
            elevio_doorOpenLamp(0);
            break;
        case CLOSED_UNEMPTY:
            // stille utom lukket false
            elevio_motorDirection(DIRN_STOP);
            elevio_doorOpenLamp(0);
            break;
        case BLOCKED_EMPTY:
            // stille tom åpen true
            elevio_motorDirection(DIRN_STOP);
            elevio_doorOpenLamp(1);
            break;
        case BLOCKED_UNEMPTY:
            // stille utom åpen true
            elevio_motorDirection(DIRN_STOP);
            elevio_doorOpenLamp(1);
            break;
    }
}

void FSM_transition(FSM_State* p_current_state, FSM_Trigger trigger, Queue* p_main_queue){

    switch(*p_current_state) {

        case UP_EMPTY: 
            switch(trigger){
                case STOP:
                    *p_current_state = OPEN_UNEMPTY;
                    break;
                default:
                    *p_current_state = UP_EMPTY;
            }
            break;

        case UP_UNEMPTY: 
            switch(trigger){
                case STOP:
                    *p_current_state = CLOSED_UNEMPTY;
                    break;
                case ENTERED_FLOOR: 
                    queue_remove_all(p_main_queue, elevio_floorSensor());

                    if (queue_has_off_requests(p_main_queue)){
                        *p_current_state = CLOSED_UNEMPTY;
                    } else {
                        *p_current_state = CLOSED_EMPTY;
                    }

                    break;
                default:
                    *p_current_state = UP_UNEMPTY;
            }
            break;
        
        case DOWN_EMPTY: 
            switch(trigger){
                case ENTERED_FLOOR: 
                    *p_current_state = OPEN_UNEMPTY;
                    break;
                default:
                    *p_current_state = DOWN_EMPTY;
            }
            break;
        
        case DOWN_UNEMPTY: 
            switch(trigger){
                case STOP:
                    *p_current_state = CLOSED_UNEMPTY;
                    break;
                case ENTERED_FLOOR: 
                    queue_remove_all(p_main_queue, elevio_floorSensor());

                    if (queue_has_off_requests(p_main_queue)){
                        *p_current_state = CLOSED_UNEMPTY;
                    } else {
                        *p_current_state = CLOSED_EMPTY;
                    }

                    break;
                default:
                    *p_current_state = DOWN_UNEMPTY;
            }
            break;
        
        case OPEN_EMPTY: 
            switch(trigger){
                case OBSTRUCTION:
                    // do something
                    break;
                case TIMER:
                    // do something
                    break;
                default:
                    *p_current_state = OPEN_EMPTY;
            }
            break;

        case OPEN_UNEMPTY: 
            switch(trigger){
                case STOP:
                    *p_current_state = OPEN_EMPTY;
                    break;
                case OBSTRUCTION:
                    // do something
                    break;
                case TIMER:
                    // do something
                    break;
                default:
                    *p_current_state = OPEN_UNEMPTY;
            }
            break;

        case CLOSED_EMPTY: 
            switch(trigger){
                case UP:
                    *p_current_state = UP_EMPTY;
                    break;
                case DOWN:
                    *p_current_state = DOWN_EMPTY;
                    break;
                case STAY:
                    *p_current_state = OPEN_UNEMPTY;
                    break;
                default:
                    *p_current_state = CLOSED_EMPTY;
            }
            break;
        
        case CLOSED_UNEMPTY: 
            switch(trigger){
                case STOP:
                    if (elevio_floorSensor()!=-1){
                        *p_current_state = OPEN_EMPTY;
                    }
                    break;
                case UP:
                    *p_current_state = UP_UNEMPTY;
                    break;
                case DOWN:
                    *p_current_state = DOWN_UNEMPTY;
                    break;
                default:
                    *p_current_state = CLOSED_UNEMPTY;
            }
            break;
        
        case BLOCKED_EMPTY: 
            switch(trigger){
                case TIMER:
                    // do something
                    break;
                default:
                    *p_current_state = BLOCKED_EMPTY;
            }
            break;

        case BLOCKED_UNEMPTY: 
            switch(trigger){
                case TIMER:
                    // do something
                    break;
                default:
                    *p_current_state = BLOCKED_UNEMPTY;
            }
            break;
    }
}