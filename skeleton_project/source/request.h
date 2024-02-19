#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Request {
    int floor;
    bool up;
    bool off;
} Request;

void print_request(Request* request);