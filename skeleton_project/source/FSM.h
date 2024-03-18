#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "driver/elevio.h"
#include "queue.h"
#include "timer.h"
#include "lamp.h"

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
} FSMState;

typedef enum {
    STOP,
    ENTERED_FLOOR,
    OBSTRUCTION,
    TIMER,
    UP,
    DOWN,
    STAY
} FSMTrigger;

typedef enum {
    DIR_NONE = -1,
    DIR_DOWN,
    DIR_UP,
} ElevatorDirection;

typedef struct {
    FSMState current_state;
    int current_floor;
    int direction;
    bool moving;
} FSM;

FSM* FSM_init(void);
void FSM_deinit(FSM* p_fsm);
void FSM_behaviour(FSM* p_fsm, time_t* p_timer, Queue* p_main_queue);
void FSM_transition(FSM* p_fsm, FSMTrigger trigger, Queue* p_main_queue, time_t* p_timer, int* current_floor);