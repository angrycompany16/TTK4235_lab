#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "driver/elevio.h"
#include "queue.h"
#include "timer.h"

// enums
typedef enum {
    UP_EMPTY,
    UP_UNEMPTY,

    DOWN_EMPTY,
    DOWN_UNEMPTY,

    BLOCKED_EMPTY, 
    BLOCKED_UNEMPTY,

    OPEN_EMPTY, 
    OPEN_UNEMPTY,

    CLOSED_EMPTY, 
    CLOSED_UNEMPTY
} FSM_State;

typedef enum {
    STOP,
    ENTERED_FLOOR,
    OBSTRUCTION,
    TIMER,
    UP,
    DOWN,
    STAY
} FSM_Trigger;

// functions
FSM_State* FSM_init(void);
void FSM_behaviour(FSM_State* p_current_state);
void FSM_transition(FSM_State* p_current_state, FSM_Trigger trigger, Queue* p_main_queue, time_t* start_time);