#include "lamp.h"

void lamp_toggle(Lamp m_lamp, int floor, bool enable){
    switch(m_lamp){
        case LAMP_CURRENT:
            while (elevio_floorSensor() != -1) {
                elevio_floorIndicator(floor);
            }
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