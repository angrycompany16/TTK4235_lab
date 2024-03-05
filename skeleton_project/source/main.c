#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include "driver/elevio.h"
#include "FSM.h"
#include "queue.h"
#include "run.h"
#include "button.h"
#include "lamp.h"

int main() {
    elevio_init();
    time_t* p_timer = timer_init();
    FSM* p_fsm = FSM_init();
    Queue* p_main_queue = queue_init();
    int target_floor = -1;
    int startup_floor = 0;

    Button* pp_up_buttons[] = { button_init(), button_init(), button_init(), button_init() };
    Button* pp_down_buttons[] = { button_init(), button_init(), button_init(), button_init() };
    Button* pp_cab_buttons[] = { button_init(), button_init(), button_init(), button_init() };
    Button* p_stop_button = button_init();

    /* Startup */
    elevio_motorDirection(DIRN_DOWN);
    
    while(1) {
        int current_floor = elevio_floorSensor();
        lamp_startup(p_timer, &startup_floor);
        if (current_floor != -1) {
            p_fsm->current_state = CLOSED_EMPTY;
            p_fsm->current_floor = current_floor;
            p_fsm->direction = DIR_NONE;
            p_fsm->moving = false;
            elevio_motorDirection(DIRN_STOP);
            lamp_disable_all();
            lamp_toggle(LAMP_CURRENT, current_floor, true);
            break;
        }

        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    }
    printf("Elevator initialized!\n");

    /* Run */
    while(1) {
        run(&target_floor, p_main_queue, p_fsm, p_timer, p_stop_button, pp_up_buttons, pp_down_buttons, pp_cab_buttons);
        
        // nanosleep(&(struct timespec){0, 20*1000}, NULL);
    }
    
    queue_deinit(p_main_queue);
    FSM_deinit(p_fsm);
    timer_deinit(p_timer);
    for (int i = 0; i < 4; i++) {
        button_deinit(pp_up_buttons[i]);
        button_deinit(pp_down_buttons[i]);
        button_deinit(pp_cab_buttons[i]);
    }
    button_deinit(p_stop_button);

    return 0;

}  
