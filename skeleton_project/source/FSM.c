#include "FSM.h"

FSM* FSM_init(){

    FSM* p_fsm = (FSM*)malloc(sizeof(FSM));

    if (p_fsm!= NULL) {
        p_fsm->current_state = CLOSED_EMPTY;
        p_fsm->current_floor = 2;
        p_fsm->direction = DIR_NONE;
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
    int sensor_current_floor = elevio_floorSensor();
    switch(p_fsm->current_state) {
        case UP_EMPTY:
            lamp_toggle(LAMP_DOOR, p_fsm->current_floor, false);
            p_fsm->moving = true;
            p_fsm->direction = DIR_UP;
            elevio_motorDirection(DIRN_UP);
            break;
        case UP_UNEMPTY:
            lamp_toggle(LAMP_DOOR, p_fsm->current_floor, false);
            p_fsm->moving = true;
            p_fsm->direction = DIR_UP;
            elevio_motorDirection(DIRN_UP);
            break;
        case DOWN_EMPTY:
            lamp_toggle(LAMP_DOOR, p_fsm->current_floor, false);
            p_fsm->moving = true;
            p_fsm->direction = DIR_DOWN;
            elevio_motorDirection(DIRN_DOWN);
            break;
        case DOWN_UNEMPTY:
            lamp_toggle(LAMP_DOOR, p_fsm->current_floor, false);
            p_fsm->moving = true;
            p_fsm->direction = DIR_DOWN;
            elevio_motorDirection(DIRN_DOWN);
            break;
        case OPEN_EMPTY:
            lamp_toggle(LAMP_DOOR, p_fsm->current_floor, true);
            if (timer_limit(p_timer, 3)){
                printf("Empty elevator, timer ran out\n");
                FSM_transition(p_fsm, TIMER, p_main_queue, p_timer, &sensor_current_floor);
            }
            p_fsm->moving = false;
            p_fsm->direction = DIR_NONE;
            elevio_motorDirection(DIRN_STOP);
            break;
        case OPEN_UNEMPTY: 
            lamp_toggle(LAMP_DOOR, p_fsm->current_floor, true);
            if (timer_limit(p_timer, 3)){
                printf("Unempty elevator, timer ran out\n");
                FSM_transition(p_fsm, TIMER, p_main_queue, p_timer, &sensor_current_floor);
            }
            p_fsm->moving = false;
            p_fsm->direction = DIR_NONE;
            elevio_motorDirection(DIRN_STOP);
            break;
        case CLOSED_EMPTY:
            lamp_toggle(LAMP_DOOR, p_fsm->current_floor, false);
            p_fsm->moving = false;
            p_fsm->direction = DIR_NONE;
            elevio_motorDirection(DIRN_STOP);
            break;
        case CLOSED_UNEMPTY:
            lamp_toggle(LAMP_DOOR, p_fsm->current_floor, false);
            p_fsm->moving = false;
            p_fsm->direction = DIR_NONE;
            elevio_motorDirection(DIRN_STOP);
            break;
        case BLOCKED_EMPTY:
            if (timer_limit(p_timer, 3)){
                printf("Blocked empty elevator, timer ran out\n");
                FSM_transition(p_fsm, TIMER, p_main_queue, p_timer, &sensor_current_floor);
            }
            p_fsm->moving = false;
            p_fsm->direction = DIR_NONE;
            elevio_motorDirection(DIRN_STOP);
            break;
        case BLOCKED_UNEMPTY:
            if (timer_limit(p_timer, 3)){
                printf("Blocked unempty elevator, timer ran out\n");
                FSM_transition(p_fsm, TIMER, p_main_queue, p_timer, &sensor_current_floor);
            }
            p_fsm->moving = false;
            p_fsm->direction = DIR_NONE;
            elevio_motorDirection(DIRN_STOP);
            break;
    }
}

void FSM_transition(FSM* p_fsm, FSMTrigger trigger, Queue* p_main_queue, time_t* p_timer, int* current_floor){    

    switch(p_fsm->current_state) {

        case UP_EMPTY: 
            switch(trigger){
                case ENTERED_FLOOR: 
                    queue_remove_all(p_main_queue, *current_floor);
                    lamp_toggle(LAMP_CAB, *current_floor, false);
                    lamp_toggle(LAMP_UP, *current_floor, false);
                    lamp_toggle(LAMP_DOWN, *current_floor, false);
                    p_fsm->current_state = OPEN_UNEMPTY;
                    timer_reset(p_timer);
                    break;
                default:
                    p_fsm->current_state = UP_EMPTY;
            }
            break;

        case UP_UNEMPTY: 
            switch(trigger){
                case STOP:
                    p_fsm->current_state = CLOSED_UNEMPTY;
                    queue_clear(p_main_queue);
                    lamp_disable_all();
                    break;
                case ENTERED_FLOOR: 
                    queue_remove_all(p_main_queue, *current_floor);
                    lamp_toggle(LAMP_CAB, *current_floor, false);
                    lamp_toggle(LAMP_UP, *current_floor, false);
                    lamp_toggle(LAMP_DOWN, *current_floor, false);
                    if (queue_query(p_main_queue, -1, ANY, FALSE)){
                        timer_reset(p_timer);
                        p_fsm->current_state = OPEN_UNEMPTY;
                    } else {
                        timer_reset(p_timer);
                        p_fsm->current_state = OPEN_EMPTY;
                    }
                    break;
                default:
                    p_fsm->current_state = UP_UNEMPTY;
            }
            // timer_reset(p_timer);
            break;
        
        case DOWN_EMPTY: 
            switch(trigger){
                case ENTERED_FLOOR: 
                    p_fsm->current_state = OPEN_UNEMPTY;
                    queue_remove_all(p_main_queue, *current_floor);
                    lamp_toggle(LAMP_CAB, *current_floor, false);
                    lamp_toggle(LAMP_UP, *current_floor, false);
                    lamp_toggle(LAMP_DOWN, *current_floor, false);
                    timer_reset(p_timer);
                    break;
                default:
                    // printf("default\n");
                    p_fsm->current_state = DOWN_EMPTY;
            }
            break;
        
        case DOWN_UNEMPTY: 
            switch(trigger){
                case STOP:
                    p_fsm->current_state = CLOSED_UNEMPTY;
                    queue_clear(p_main_queue);
                    lamp_disable_all();
                    break;
                case ENTERED_FLOOR: 
                    queue_remove_all(p_main_queue, *current_floor);
                    lamp_toggle(LAMP_CAB, *current_floor, false);
                    lamp_toggle(LAMP_UP, *current_floor, false);
                    lamp_toggle(LAMP_DOWN, *current_floor, false);
                    if (queue_query(p_main_queue, *current_floor, ANY, FALSE)) {
                        timer_reset(p_timer);
                        p_fsm->current_state = OPEN_UNEMPTY;
                    } else {
                        timer_reset(p_timer);
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
                    p_fsm->current_state = BLOCKED_UNEMPTY;
                    break;
                case TIMER:
                    p_fsm->current_state = CLOSED_EMPTY;
                    break;
                case STAY:
                    p_fsm->current_state = OPEN_UNEMPTY;
                    break;
                default:
                    p_fsm->current_state = OPEN_EMPTY;
            }
            break;

        case OPEN_UNEMPTY: 
            switch(trigger){
                case STOP:
                    lamp_disable_all();
                    p_fsm->current_state = OPEN_EMPTY;
                    queue_clear(p_main_queue);
                    timer_reset(p_timer);
                    break;
                case OBSTRUCTION:
                    p_fsm->current_state = BLOCKED_UNEMPTY;
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
                    queue_remove_all(p_main_queue, *current_floor);
                    break;
                case DOWN:
                    p_fsm->current_state = DOWN_EMPTY;
                    break;
                case STAY:
                    p_fsm->current_state = OPEN_UNEMPTY;
                    timer_reset(p_timer);
                    queue_remove_all(p_main_queue, *current_floor);
                    lamp_toggle(LAMP_CAB, *current_floor, false);
                    lamp_toggle(LAMP_UP, *current_floor, false);
                    lamp_toggle(LAMP_DOWN, *current_floor, false);
                    break;
                default:
                    p_fsm->current_state = CLOSED_EMPTY;
            }
            break;
        
        case CLOSED_UNEMPTY:
            switch(trigger){
                case STOP:
                    lamp_disable_all();
                    if (*current_floor!=-1){
                        p_fsm->current_state = OPEN_EMPTY;
                    }
                    queue_clear(p_main_queue);
                    timer_reset(p_timer);
                    break;
                case UP:
                    p_fsm->current_state = UP_UNEMPTY;
                    queue_remove_all(p_main_queue, *current_floor);
                    break;
                case DOWN:
                    p_fsm->current_state = DOWN_UNEMPTY;
                    queue_remove_all(p_main_queue, *current_floor);
                    break;
                case STAY:
                    p_fsm->current_state = OPEN_UNEMPTY;
                    timer_reset(p_timer);
                    queue_remove_all(p_main_queue, *current_floor);
                    lamp_toggle(LAMP_CAB, *current_floor, false);
                    lamp_toggle(LAMP_UP, *current_floor, false);
                    lamp_toggle(LAMP_DOWN, *current_floor, false);
                    break;
                default:
                    p_fsm->current_state = CLOSED_UNEMPTY;
            }
            break;
        
        case BLOCKED_EMPTY: 
            switch(trigger){
                case TIMER:
                    p_fsm->current_state = CLOSED_EMPTY;
                    break;
                default:
                    p_fsm->current_state = BLOCKED_EMPTY;
            }
            break;

        case BLOCKED_UNEMPTY: 
            switch(trigger){
                case TIMER:
                    p_fsm->current_state = CLOSED_UNEMPTY;
                    break;
                default:
                    p_fsm->current_state = BLOCKED_UNEMPTY;
            }
            break;
    }
}