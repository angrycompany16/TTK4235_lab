#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include "driver/elevio.h"
#include "FSM.h"
#include "queue.h"


int main(){

    /*
    elevio_init();

    Queue* p_main_queue = queue_init();

    while(1) {
        run();
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);

        if (elevio_stopButton()) {
            break;
        }
    }
    
    queue_deinit(p_main_queue);
    */

    /*
    elevio_init();

    Queue* p_main_queue = queue_init();

    queue_add(p_main_queue, (Request){2, true, true});
    queue_add(p_main_queue, (Request){1, false, false});
    queue_add(p_main_queue, (Request){1, true, false});
    queue_add(p_main_queue, (Request){4, true, false});
    queue_add(p_main_queue, (Request){4, true, false});
    
    printf(queue_has_off_requests(p_main_queue) ? "has off requests\n" : "has no off requests\n");
    printf(queue_query(p_main_queue, true, false) ? "has query matches\n" : "has no query matches\n");

    sleep(1);

    queue_print(p_main_queue);

    nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    */

    return 0;

}  
