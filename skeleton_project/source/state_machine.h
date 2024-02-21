#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"

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
} State;

typedef enum {
    STOP,
    ENTERED_FLOOR,
    OBSTRUCTION,
    TIMER,
    UP,
    DOWN,
    STAY
} Trigger;

// functions
void behaviour(State* p_current_state);
void transition(State* p_current_state, Trigger trigger);