#include "timer.h"

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

void timer_reset(time_t* p_timer){
    *p_timer = time(NULL);
}

bool timer_limit(time_t* p_timer, int limit){
    return (difftime(time(NULL), *p_timer) >= limit);
}