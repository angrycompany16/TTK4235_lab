#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "request.h"

#define MAX_QUEUE_SIZE 100

typedef struct {
    Request queue[MAX_QUEUE_SIZE];
    size_t youngest_queue_element;
} Queue;

typedef enum {
    FALSE,
    TRUE,
    ANY,
} QueueQueryItem;

Queue* queue_init(void);

void queue_deinit(Queue* p_queue);

void queue_add(Queue* p_queue, Request req);

void queue_remove(Queue* p_queue, size_t pos);

void queue_remove_all(Queue* p_queue, int floor);

void queue_clear(Queue* p_queue);

void queue_print(Queue* p_queue);

// bool queue_has_off_requests(Queue* p_queue);

bool queue_query(Queue* p_queue, int floor, QueueQueryItem direction, QueueQueryItem off);
bool check_request(Request* p_request, int floor, QueueQueryItem direction, QueueQueryItem off);

// static bool queue_query_floor(Queue* p_queue, int floor);
// static bool queue_query_direction(Queue* p_queue, bool direction);
// static bool queue_query_off(Queue* p_queue, bool off);

Request* queue_find_first_off_request(Queue* p_queue);
