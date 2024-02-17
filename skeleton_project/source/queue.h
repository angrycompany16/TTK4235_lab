#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "request.h"

#define MAX_QUEUE_SIZE 100

typedef struct Queue {
    Request queue[MAX_QUEUE_SIZE];
    size_t last_queue_element;
} Queue;

Queue* queue_init(void);

void queue_deinit(Queue* p_queue);

void add(Queue* p_queue, Request req);

void remove_all(Queue* p_queue, int floor);

void print_queue(Queue* p_queue);

bool no_off_requests(Queue* p_queue);
