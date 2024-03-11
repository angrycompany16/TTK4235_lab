#include "lamp.h"

void lamp_toggle(Lamp m_lamp, int floor, bool enable){
    switch(m_lamp){
        case LAMP_CURRENT:
            if (floor == -1) { break; }
            if (floor == 0) { printf("lamp floor 0 set\n"); }
            elevio_floorIndicator(floor);
            break;
        case LAMP_UP:
            if (floor == -1) { break; } 
            elevio_buttonLamp(floor, BUTTON_HALL_UP, enable);
            break;
        case LAMP_DOWN:
            if (floor == -1) { break; } 
            elevio_buttonLamp(floor, BUTTON_HALL_DOWN, enable);
            break;
        case LAMP_CAB:
            if (floor == -1) { break; } 
            elevio_buttonLamp(floor, BUTTON_CAB, enable);
            break;
        case LAMP_STOP:
            elevio_stopLamp(enable);
            break;
        case LAMP_DOOR:
            if (floor == -1) { break; } 
            elevio_doorOpenLamp(enable);
            break;
    }
}

void lamp_disable_all() {
    for (int i = 0; i < 4; i++) {
        elevio_buttonLamp(i, BUTTON_HALL_UP, 0);
        elevio_buttonLamp(i, BUTTON_HALL_DOWN, 0);
        elevio_buttonLamp(i, BUTTON_CAB, 0);
        //elevio_stopLamp(0);
        elevio_doorOpenLamp(0);
        // elevio_buttonLamp(i, , 0);
    }
}

void lamp_startup(time_t* p_timer, int* floor) {
    if (timer_limit(p_timer, 0.75)) {
        lamp_set_all_on_floor((*floor)++);
        timer_reset(p_timer);
        *floor %= 4;
    }
}

void lamp_set_all_on_floor(int floor) {
    // printf("Set all on floor was called\n");
    lamp_disable_all();
    elevio_floorIndicator(floor);
    elevio_buttonLamp(floor, BUTTON_HALL_UP, 1);
    elevio_buttonLamp(floor, BUTTON_HALL_DOWN, 1);
    elevio_buttonLamp(floor, BUTTON_CAB, 1);
}