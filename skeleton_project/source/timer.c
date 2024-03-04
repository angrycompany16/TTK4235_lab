#include "timer.h"

// TODO: rename all functions to start with 'timer'
time_t* timer_init(){
    time_t* p_timer = (time_t*)malloc(sizeof(time_t));

    if (p_timer != NULL) {
        *p_timer = time(NULL);
    } else {
        printf("Error allocating memory for timer\n");
    }

    return p_timer;
}

void timer_deinit(time_t* p_timer){
    free(p_timer);
}

void reset_timer(time_t* p_timer){
    *p_timer = time(NULL);
}

// checks whether the timer has ran out of time and resets it if so
bool time_limit(time_t* p_timer, int limit){
    return (difftime(time(NULL), *p_timer) >= limit);
    
    
    //     reset_timer(p_timer);
    //     return true;
    // } 
    // return false;
}