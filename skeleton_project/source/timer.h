#pragma once
#include "time.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


void start_timer(time_t* start_time);
bool time_limit(time_t* start_time);