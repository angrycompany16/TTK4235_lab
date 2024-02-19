#include "run.h"

void run(int* target_floor, Queue* p_main_queue, Button* p_button_2_up) {
    // Setup elevator
    
    button_update(p_button_2_up, elevio_callButton(2, BUTTON_HALL_UP));

    if (p_button_2_up->was_just_pressed) {
        // queue_add(p_main_queue, (Request) {2, false, false});
        printf("Button just pressed\n");
        // queue_print(p_main_queue);
    }
    /*
    for (int i = 0; i < 4; i++) {
        if (elevio_callButton(i, BUTTON_HALL_DOWN)) {
            queue_add(p_main_queue, (Request) {i, false, false});
            queue_print(p_main_queue);
        }

        if (elevio_callButton(i, BUTTON_HALL_UP)) {
            queue_add(p_main_queue, (Request) {i, true, false});
            queue_print(p_main_queue);
        }

        if (elevio_callButton(i, BUTTON_CAB)) {
            if (i > elevio_floorSensor()) {
                queue_add(p_main_queue, (Request) {i, true, true});
                queue_print(p_main_queue);
            } else if (i < elevio_floorSensor()) {
                queue_add(p_main_queue, (Request) {i, true, false});
               queue_print(p_main_queue);
            }
        }
    }
    */
}