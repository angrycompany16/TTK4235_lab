#pragma once
#include "time.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

time_t* timer_init();
void timer_deinit(time_t* p_timer);
void reset_timer(time_t* p_timer);
bool time_limit(time_t* p_timer, int limit);