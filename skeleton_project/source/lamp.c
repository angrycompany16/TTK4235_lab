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

void enable_lamp(Lamp m_lamp){
    switch(m_lamp){
        case LAMP_CURRENT_1:
            // lysene her er jo ikke en knapp?
            break;
        case LAMP_CURRENT_2:
            
            break;
        case LAMP_CURRENT_3:

            break;
        case LAMP_CURRENT_4:

            break;
    
        case LAMP_UP_1:
            elevio_buttonLamp(1, BUTTON_HALL_UP, 1);
            break;
        case LAMP_UP_2:
            elevio_buttonLamp(2, BUTTON_HALL_UP, 1);
            break;
        case LAMP_DOWN_2:
            elevio_buttonLamp(2, BUTTON_HALL_DOWN, 1);
            break;
        case LAMP_UP_3:
            elevio_buttonLamp(3, BUTTON_HALL_UP, 1);
            break;
        case LAMP_DOWN_3:
            elevio_buttonLamp(3, BUTTON_HALL_DOWN, 1);
            break;
        case LAMP_DOWN_4:
            elevio_buttonLamp(4, BUTTON_HALL_DOWN, 1);
            break;

        case LAMP_ORDER_1:
            elevio_buttonLamp(1, BUTTON_CAB, 1);
            break;
        case LAMP_ORDER_2:
            elevio_buttonLamp(2, BUTTON_CAB, 1);
            break;
        case LAMP_ORDER_3:
            elevio_buttonLamp(3, BUTTON_CAB, 1);
            break;
        case LAMP_ORDER_4:
            elevio_buttonLamp(4, BUTTON_CAB, 1);
            break;

        case STOP_LAMP:
            elevio_stopLamp(1);
            break;
        case DOOR_LAMP:
            elevio_doorOpenLamp(1);
            break;
    }
}

// slå sammen disable og enable? ta inn bool for om skal skrus av eller på

void disable_lamp(Lamp m_lamp){
    switch(m_lamp){
        case LAMP_CURRENT_1:
            // lysene her er jo ikke en knapp?
            break;
        case LAMP_CURRENT_2:
            
            break;
        case LAMP_CURRENT_3:

            break;
        case LAMP_CURRENT_4:

            break;
    
        case LAMP_UP_1:
            elevio_buttonLamp(1, BUTTON_HALL_UP, 0);
            break;
        case LAMP_UP_2:
            elevio_buttonLamp(2, BUTTON_HALL_UP, 0);
            break;
        case LAMP_DOWN_2:
            elevio_buttonLamp(2, BUTTON_HALL_DOWN, 0);
            break;
        case LAMP_UP_3:
            elevio_buttonLamp(3, BUTTON_HALL_UP, 0);
            break;
        case LAMP_DOWN_3:
            elevio_buttonLamp(3, BUTTON_HALL_DOWN, 0);
            break;
        case LAMP_DOWN_4:
            elevio_buttonLamp(4, BUTTON_HALL_DOWN, 0);
            break;

        case LAMP_ORDER_1:
            elevio_buttonLamp(1, BUTTON_CAB, 0);
            break;
        case LAMP_ORDER_2:
            elevio_buttonLamp(2, BUTTON_CAB, 0);
            break;
        case LAMP_ORDER_3:
            elevio_buttonLamp(3, BUTTON_CAB, 0);
            break;
        case LAMP_ORDER_4:
            elevio_buttonLamp(4, BUTTON_CAB, 0);
            break;

        case STOP_LAMP:
            elevio_stopLamp(0);
            break;
        case DOOR_LAMP:
            elevio_doorOpenLamp(0);
            break;
    }
}