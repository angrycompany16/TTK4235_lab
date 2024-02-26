#include "timer.h"

/*
// ikke peker
time_t start_time;

void start_timer(){
    start_time = time(NULL);
}

bool time_limit(){
    return (difftime(time(NULL), start_time) >= 3);
}
*/

void start_timer(time_t* start_time){
    *start_time = time(NULL);
}

bool time_limit(time_t* start_time){
    return (difftime(time(NULL), *start_time) >= 3);
}