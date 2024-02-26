#include "FSM.h"
#include "timer.h"

FSM* FSM_init(){

    FSM* p_fsm = (FSM*)malloc(sizeof(FSM));

    if (p_fsm!= NULL) {
        p_fsm->current_state = CLOSED_EMPTY;
        p_fsm->current_floor = 2;
        p_fsm->moving = false;
    } else {
        printf("Error allocating memory for button\n");
    }

    return p_fsm;
}

void FSM_deinit(FSM* p_fsm) {
    free(p_fsm);
}

void FSM_behaviour(FSM* p_fsm, time_t* p_timer, Queue* p_main_queue){

    // Ikke tatt hensyn til Stop (timer-cases) og Obstruction enda

    switch(p_fsm->current_state) {
        case UP_EMPTY:
            p_fsm->moving = true;
            elevio_motorDirection(DIRN_UP);
            elevio_doorOpenLamp(0);
            break;
        case UP_UNEMPTY:
            p_fsm->moving = true;
            elevio_motorDirection(DIRN_UP);
            elevio_doorOpenLamp(0);
            break;
        case DOWN_EMPTY:
            p_fsm->moving = true;
            elevio_motorDirection(DIRN_DOWN);
            elevio_doorOpenLamp(0);
            break;
        case DOWN_UNEMPTY:
            p_fsm->moving = true;
            elevio_motorDirection(DIRN_DOWN);
            elevio_doorOpenLamp(0);
            break;
        case OPEN_EMPTY:
            if (time_limit(p_timer)){
                printf("timer empty\n");
                FSM_transition(p_fsm, TIMER, p_main_queue, p_timer);
            }
            p_fsm->moving = false;
            elevio_motorDirection(DIRN_STOP);
            elevio_doorOpenLamp(1);
            break;
        case OPEN_UNEMPTY: 
            if (time_limit(p_timer)){
                printf("timer unempty\n");
                FSM_transition(p_fsm, TIMER, p_main_queue, p_timer);
            }
            p_fsm->moving = false;
            elevio_motorDirection(DIRN_STOP);
            elevio_doorOpenLamp(1);
            break;
        case CLOSED_EMPTY:
            p_fsm->moving = false;
            elevio_motorDirection(DIRN_STOP);
            elevio_doorOpenLamp(0);
            break;
        case CLOSED_UNEMPTY:
            p_fsm->moving = false;
            elevio_motorDirection(DIRN_STOP);
            elevio_doorOpenLamp(0);
            break;
        case BLOCKED_EMPTY:
            p_fsm->moving = false;
            elevio_motorDirection(DIRN_STOP);
            elevio_doorOpenLamp(1);
            break;
        case BLOCKED_UNEMPTY:
            p_fsm->moving = false;
            elevio_motorDirection(DIRN_STOP);
            elevio_doorOpenLamp(1);
            break;
    }
}

void FSM_transition(FSM* p_fsm, FSM_Trigger trigger, Queue* p_main_queue, time_t* p_timer){    

    switch(p_fsm->current_state) {

        case UP_EMPTY: 
            switch(trigger){
                case ENTERED_FLOOR: 
                    queue_remove_all(p_main_queue, elevio_floorSensor());
                    p_fsm->current_state = OPEN_UNEMPTY;
                    reset_timer(p_timer);

                    break;
                default:
                    p_fsm->current_state = UP_EMPTY;
            }
            break;

        case UP_UNEMPTY: 
            switch(trigger){
                case STOP:
                    p_fsm->current_state = CLOSED_UNEMPTY;
                    break;
                case ENTERED_FLOOR: 
                    queue_remove_all(p_main_queue, elevio_floorSensor());

                    if (queue_has_off_requests(p_main_queue)){
                        reset_timer(p_timer);
                        p_fsm->current_state = OPEN_UNEMPTY;
                    } else {
                        reset_timer(p_timer);
                        p_fsm->current_state = OPEN_EMPTY;
                    }

                    break;
                default:
                    p_fsm->current_state = UP_UNEMPTY;
            }reset_timer(p_timer);
            break;
        
        case DOWN_EMPTY: 
            switch(trigger){
                case ENTERED_FLOOR: 
                    p_fsm->current_state = OPEN_UNEMPTY;
                    queue_remove_all(p_main_queue, elevio_floorSensor());
                    reset_timer(p_timer);

                    break;
                default:
                    printf("default\n");
                    p_fsm->current_state = DOWN_EMPTY;
            }
            break;
        
        case DOWN_UNEMPTY: 
            switch(trigger){
                case STOP:
                    p_fsm->current_state = CLOSED_UNEMPTY;
                    break;
                case ENTERED_FLOOR: 
                    queue_remove_all(p_main_queue, elevio_floorSensor());

                    if (queue_has_off_requests(p_main_queue)){
                        reset_timer(p_timer);
                        p_fsm->current_state = OPEN_UNEMPTY;
                    } else {
                        reset_timer(p_timer);
                        p_fsm->current_state = OPEN_EMPTY;
                    }

                    break;
                default:
                    p_fsm->current_state = DOWN_UNEMPTY;
            }
            break;
        
        case OPEN_EMPTY: 
            switch(trigger){
                case OBSTRUCTION:
                    // do something
                    break;
                case TIMER:
                    // TODO: implement waiting for stop-button release before starting timer
                    p_fsm->current_state = CLOSED_EMPTY;
                    break;
                default:
                    p_fsm->current_state = OPEN_EMPTY;
                    // reset_timer(p_timer);
            }
            break;

        case OPEN_UNEMPTY: 
            switch(trigger){
                case STOP:
                    p_fsm->current_state = OPEN_EMPTY;
                    reset_timer(p_timer);

                    break;
                case OBSTRUCTION:
                    // do something
                    break;
                case TIMER:
                    p_fsm->current_state = CLOSED_UNEMPTY;
                    break;
                default:
                    p_fsm->current_state = OPEN_UNEMPTY;
            }
            break;

        case CLOSED_EMPTY: 
            switch(trigger){
                case UP:
                    p_fsm->current_state = UP_EMPTY;
                    break;
                case DOWN:
                    p_fsm->current_state = DOWN_EMPTY;
                    break;
                case STAY:
                    p_fsm->current_state = OPEN_UNEMPTY;
                    reset_timer(p_timer);
                    queue_remove_all(p_main_queue, elevio_floorSensor());

                    break;
                default:
                    p_fsm->current_state = CLOSED_EMPTY;
            }
            break;
        
        case CLOSED_UNEMPTY: 
            switch(trigger){
                case STOP:
                    if (elevio_floorSensor()!=-1){
                        p_fsm->current_state = OPEN_EMPTY;
                        reset_timer(p_timer);
                    }
                    break;
                case UP:
                    p_fsm->current_state = UP_UNEMPTY;
                    break;
                case DOWN:
                    p_fsm->current_state = DOWN_UNEMPTY;
                    break;
                case STAY:
                    p_fsm->current_state = OPEN_UNEMPTY;
                    reset_timer(p_timer);
                    queue_remove_all(p_main_queue, elevio_floorSensor());
                    break;
                default:
                    p_fsm->current_state = CLOSED_UNEMPTY;
            }
            break;
        
        case BLOCKED_EMPTY: 
            switch(trigger){
                case TIMER:
                    // waits for obstr release
                    // start_timer(time);
                    // if (time_limit(time)){
                    //     p_fsm->current_state = CLOSED_EMPTY;
                    // }
                    break;
                default:
                    p_fsm->current_state = BLOCKED_EMPTY;
            }
            break;

        case BLOCKED_UNEMPTY: 
            switch(trigger){
                case TIMER:
                    // waits for obstr release
                    // start_timer(time);
                    // if (time_limit(time)){
                    //     p_fsm->current_state = CLOSED_UNEMPTY;
                    // }
                    break;
                default:
                    p_fsm->current_state = BLOCKED_UNEMPTY;
            }
            break;
    }
}