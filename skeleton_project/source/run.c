#include "run.h"

void run(
    int* target_floor, 
    Queue* p_main_queue, 
    Button** pp_up_buttons, 
    Button** pp_down_buttons, 
    Button** pp_cab_buttons
) {
    // Setup elevator
    
    // button_update(p_button_2_up, false);

    for (size_t i = 0; i < 4; i++) {
        button_update(pp_up_buttons[i], elevio_callButton(i, BUTTON_HALL_UP));
        button_update(pp_down_buttons[i], elevio_callButton(i, BUTTON_HALL_DOWN));
        button_update(pp_cab_buttons[i], elevio_callButton(i, BUTTON_CAB));
    }


    // printf("%d\n", pp_up_buttons[0]->was_just_pressed);

    if (pp_cab_buttons[3]->was_just_pressed) {
        printf("4th floor cab button pressed\n");
    }

    // button_update(p_button_2_up, elevio_callButton(2, BUTTON_HALL_UP));
    // if (elevio_callButton(2, BUTTON_HALL_UP)) {
    // }
    // sleep(0.001);

    // printf("%d\n", elevio_callButton(2, BUTTON_HALL_UP));

    // if (p_button_2_up->was_just_pressed) {
        
    //     // queue_add(p_main_queue, (Request) {2, false, false});
    //     printf("Button just pressed\n");
    //     // queue_print(p_main_queue);
    // }

    // if (p_button_2_up->was_just_released) {
        
    //     // queue_add(p_main_queue, (Request) {2, false, false});
    //     printf("Button just released\n");
    //     // queue_print(p_main_queue);
    // }

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