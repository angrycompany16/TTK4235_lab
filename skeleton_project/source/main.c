#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include "driver/elevio.h"
#include "state_machine.h"
#include "queue.h"
#include "run.h"
#include "button.h"

int main() {
    elevio_init();

    Queue* p_main_queue = queue_init();
    int target_floor = 0;

    Button* p_button_2_up = init_button();

    while(1) {
        run(&target_floor, p_main_queue);

        if (elevio_stopButton()) {
            break;
        }
        
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    }
    
    queue_deinit(p_main_queue);

    return 0;

}  
