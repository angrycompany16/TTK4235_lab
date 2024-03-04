#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// NOTE: `direction` boolean has two meanings. When a button is pressed outside the elevator, `direction` refers to whether the
// pershon pressed the direction or down button. However, when a button is pressed inside the elevator, `direction` refers to
// whether the current floor is less than or greater than the floor that the person wants to go to.
// The case where a user enters the elevator and presses the button corresponding to the current floor is not handled.
typedef struct {
    int floor;
    bool direction;
    bool off;
} Request;

void print_request(Request* request);