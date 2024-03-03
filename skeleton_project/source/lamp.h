#pragma once
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
} Lamp_2;

//Lamp* lamp_init(void);
//void lamp_deinit(Lamp* p_lamp);

void lamp_toggle(Lamp_2 m_lamp, int floor, bool enable);

// ikke pointers pga kun enums??

// L3 og L4!