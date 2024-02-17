#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include "driver/elevio.h"
#include "queue.h"


int main(){
    elevio_init();
    Queue* p_main_queue = queue_init();
    
    elevio_motorDirection(DIRN_UP);

    sleep(1);
    // nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);


    // while(1){
    //     int floor = elevio_floorSensor();

    //     if(floor == 0){
    //         elevio_motorDirection(DIRN_UP);
    //     }

    //     if(floor == N_FLOORS-1){
    //         elevio_motorDirection(DIRN_DOWN);
    //     }

    //     nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    // }

    queue_deinit(p_main_queue);

    return 0;    
}
