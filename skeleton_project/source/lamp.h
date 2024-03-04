#pragma once
#include "time.h"
#include "timer.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "driver/elevio.h"
#include <stdbool.h>

typedef enum{
    LAMP_CURRENT,
    LAMP_UP,
    LAMP_DOWN,
    LAMP_CAB,
    LAMP_STOP,
    LAMP_DOOR
} Lamp;

void lamp_toggle(Lamp m_lamp, int floor, bool enable);

void lamp_disable_all();

void lamp_startup(time_t* p_timer, int* floor);

void lamp_set_all_on_floor(int floor);
