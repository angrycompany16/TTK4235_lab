#include "lamp.h"
/*
Lamp* lamp_init(){

    Lamp* p_lamp = (Lamp*)malloc(sizeof(Lamp));

    if (p_lamp!= NULL) {
        *p_lamp = BUTTON_HALL_DOWN;
        // *p_lamp = ; Lyse i etasjen heisen starter i?
    } else {
        printf("Error allocating memory for button\n");
    }

    return p_lamp;
}

void lamp_deinit(Lamp* p_lamp) {
    free(p_lamp);
}
*/

void toggle(Lamp_2 m_lamp, int floor, bool enable){
    switch(m_lamp){
        case LAMP_CURRENT:
            // hvordan håndtere disse lysene?
            break;
        case LAMP_UP:
            elevio_buttonLamp(floor, BUTTON_HALL_UP, enable);
            break;
        case LAMP_DOWN:
            elevio_buttonLamp(floor, BUTTON_HALL_DOWN, enable);
            break;
        case LAMP_CAB:
            elevio_buttonLamp(floor, BUTTON_CAB, enable);
            break;
        case LAMP_STOP:
            elevio_stopLamp(enable);
            break;
        case LAMP_DOOR:
            elevio_doorOpenLamp(enable);
            break;
    }
}