#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

// enums
typedef enum State {
    UP_EMPTY,
    DOWN_EMPTY,
    UP_UNEMPTY,
    DOWN_UNEMPTY,
    STATIONARY_EMPTY,
    STATIONARY_UNEMPTY
} State;

typedef enum Trigger {
    TEST_UNO,
    TEST_DOS,
    TEST_TJOHO
} Trigger;

// functions
void behaviour(State* p_current_state);
void transition(State* p_current_state, Trigger trigger);