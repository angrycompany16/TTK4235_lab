#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "driver/elevio.h"

typedef enum{
    // Etasjepanel
    LAMP_CURRENT_1,
    LAMP_CURRENT_2,
    LAMP_CURRENT_3,
    LAMP_CURRENT_4,
    
    LAMP_UP_1,
    LAMP_UP_2,
    LAMP_DOWN_2,
    LAMP_UP_3,
    LAMP_DOWN_3,
    LAMP_DOWN_4,

    // Heispanel
    LAMP_ORDER_1,
    LAMP_ORDER_2,
    LAMP_ORDER_3,
    LAMP_ORDER_4,

    STOP_LAMP,
    DOOR_LAMP
} Lamp;

//Lamp* lamp_init(void);
//void lamp_deinit(Lamp* p_lamp);
void enable_lamp(Lamp m_lamp);
void disable_lamp(Lamp m_lamp);

// ikke pointers pga kun enums??