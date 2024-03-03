#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include "queue.h"
#include "driver/elevio.h"
#include "button.h"
#include "FSM.h"
#include "lamp.h"

void run(
    int* target_floor, 
    Queue* p_main_queue, 
    FSM* p_current_state,
    time_t* p_timer,
    Button** pp_up_buttons, 
    Button** pp_down_buttons, 
    Button** pp_cab_buttons
);