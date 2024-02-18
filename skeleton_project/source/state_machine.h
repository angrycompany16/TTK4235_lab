#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"

// enums
typedef enum State {
    UP_EMPTY,
    DOWN_EMPTY,
    UP_UNEMPTY,
    DOWN_UNEMPTY,
    STATIONARY_EMPTY, 
    STATIONARY_UNEMPTY
    // tilstand for åpne/lukka dører? dører kan kun åpnes i stasjonær tilstand
} State;

typedef enum Trigger {
    BUTTON_PRESSED, // to ulike typer knapper for inni og utpå heisen?
    DOOR_STATUS,
    FLOOR_INDICATOR,
    MAX_FLOOR, // heisen skal ikke bevege seg forbi 4.etasje
    MIN_FLOOR, // eller under 1.
    TEST_TJOHO
} Trigger;

// functions
void behaviour(State* p_current_state);
void transition(State* p_current_state, Trigger trigger);