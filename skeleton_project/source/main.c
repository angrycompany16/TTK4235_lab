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

// TODO: check pragma once

int main() {
    elevio_init();
    time_t* p_timer = timer_init();
    FSM* p_fsm = FSM_init();
    Queue* p_main_queue = queue_init();
    int target_floor = -1;

    Button* up_buttons[] = { button_init(), button_init(), button_init(), button_init() };
    Button* down_buttons[] = { button_init(), button_init(), button_init(), button_init() };
    Button* cab_buttons[] = { button_init(), button_init(), button_init(), button_init() };

    while(1) {
        run(&target_floor, p_main_queue, p_fsm, p_timer, up_buttons, down_buttons, cab_buttons);

        if (elevio_stopButton()) {
            break;
        }
        
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    }
    
    queue_deinit(p_main_queue);
    FSM_deinit(p_fsm);
    timer_deinit(p_timer);
    for (int i = 0; i < 4; i++) {
        button_deinit(up_buttons[i]);
        button_deinit(down_buttons[i]);
        button_deinit(cab_buttons[i]);
    }

    return 0;

}  
