#include "queue.h"

Queue* queue_init() {
    Queue* p_queue = (Queue*)malloc(sizeof(Queue));

    // maybe not necessary?
    if (p_queue == NULL) {
        printf("Queue object could not be made\n");
        exit(EXIT_FAILURE);
    }

    p_queue->last_queue_element = 0;

    printf("Created queue struct\n");

    return p_queue;
}

void queue_deinit(Queue* p_queue) {
    printf("Deleted queue struct\n");

    free(p_queue);
}

void queue_add(Queue* p_queue, Request req) {
    p_queue->queue[p_queue->last_queue_element] = req;
    p_queue->last_queue_element++;
}

void queue_remove(Queue* p_queue, size_t pos)  {
    for (size_t i = pos; i < p_queue->last_queue_element - 1; i++) {
        p_queue->queue[i] = p_queue->queue[i + 1];
    }

    p_queue->last_queue_element--;
}

void queue_remove_all(Queue* p_queue, int floor) {
    for (size_t i = 0; i < p_queue->last_queue_element; i++) {
        if (p_queue->queue[i].floor == floor) {
            queue_remove(p_queue, i);
            i--;
        }
    }
}

void queue_print(Queue* p_queue) {
    printf("Printing queue...\n");
    for (size_t i = 0; i < p_queue->last_queue_element; i++) {
        print_request(&p_queue->queue[i]);
    }
}

bool queue_has_off_requests(Queue* p_queue) {
    for (size_t i = 0; i < p_queue->last_queue_element; i++) {
        if (p_queue->queue[i].off == true) {
            return true;
        }
    }
    return false;
}
