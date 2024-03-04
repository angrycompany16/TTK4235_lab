#include "run.h"

void run(
    int* target_floor, 
    Queue* p_main_queue, 
    FSM* p_fsm,
    time_t* p_timer,
    Button* p_stop_button,
    Button** pp_up_buttons, 
    Button** pp_down_buttons, 
    Button** pp_cab_buttons
) {
    button_update(p_stop_button, elevio_stopButton());

    for (size_t i = 0; i < 4; i++) {
        button_update(pp_up_buttons[i], elevio_callButton(i, BUTTON_HALL_UP));
        button_update(pp_down_buttons[i], elevio_callButton(i, BUTTON_HALL_DOWN));
        button_update(pp_cab_buttons[i], elevio_callButton(i, BUTTON_CAB));
    }

    if (p_stop_button->was_just_pressed) {
        FSM_transition(p_fsm, STOP, p_main_queue, p_timer);
        // queue_query_floor(p_main_queue, 2);
    }

    if (p_stop_button->pressed) { reset_timer(p_timer); }

    if (elevio_obstruction()) {
        reset_timer(p_timer);
        FSM_transition(p_fsm, OBSTRUCTION, p_main_queue, p_timer);
    }

    for (int i = 0; i < 4; i++) {
        if (p_stop_button->pressed) { continue; }

        if (pp_down_buttons[i]->was_just_pressed) {
            queue_add(p_main_queue, (Request) {i, false, false});
            queue_print(p_main_queue);
        }

        if (pp_up_buttons[i]->was_just_pressed) {
            queue_add(p_main_queue, (Request) {i, true, false});
            queue_print(p_main_queue);
        }

        if (pp_cab_buttons[i]->was_just_pressed) {
            if (i > elevio_floorSensor()) {
                queue_add(p_main_queue, (Request) {i, true, true});
                queue_print(p_main_queue);
            } else if (i < elevio_floorSensor()) {
                queue_add(p_main_queue, (Request) {i, false, true});
                queue_print(p_main_queue);
            }
        }
    }

    if (!p_fsm->moving) {
        if (queue_query(p_main_queue, -1, ANY, TRUE)) {
            *target_floor = queue_find_first_off_request(p_main_queue)->floor;
        } else { 
            if (p_main_queue->youngest_queue_element != 0) {
                *target_floor = p_main_queue->queue[0].floor;
            } else {
                *target_floor = -1;
            }
        }

        if (*target_floor == -1) {
            // do nothing
        } else if (*target_floor < p_fsm->current_floor) {
            FSM_transition(p_fsm, DOWN, p_main_queue, p_timer);
        } else if (*target_floor > p_fsm->current_floor) {
            FSM_transition(p_fsm, UP, p_main_queue, p_timer);
        } else {
            FSM_transition(p_fsm, STAY, p_main_queue, p_timer);
        }
    } else {
        // printf("Floor sensor: %d\n", elevio_floorSensor());
        if (elevio_floorSensor() != -1) {
            p_fsm->current_floor = elevio_floorSensor();
            if (queue_query(p_main_queue, elevio_floorSensor(), p_fsm->direction, ANY)) {
                FSM_transition(p_fsm, ENTERED_FLOOR, p_main_queue, p_timer);
            }
        }
        
        if (*target_floor == elevio_floorSensor()) {
            // TODO: also make elevator stop when someone enters in the same direction
            FSM_transition(p_fsm, ENTERED_FLOOR, p_main_queue, p_timer);
        }

    }

    FSM_behaviour(p_fsm, p_timer, p_main_queue);

    // queue_print(p_main_queue);
    // printf("Current state: %d\n", p_fsm->current_state);
}