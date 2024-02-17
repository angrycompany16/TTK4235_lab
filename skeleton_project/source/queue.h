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

void queue_add(Queue* p_queue, Request req);

void queue_remove(Queue* p_queue, size_t pos);

void queue_remove_all(Queue* p_queue, int floor);

void queue_print(Queue* p_queue);

bool queue_has_off_requests(Queue* p_queue);
