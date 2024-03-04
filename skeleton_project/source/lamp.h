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
} Lamp;

void lamp_toggle(Lamp m_lamp, int floor, bool enable);

// L3 og L4!