#include "queue.h"

Queue* queue_init() {
    Queue* p_queue = (Queue*)malloc(sizeof(Queue));

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

void add(Queue* p_queue, Request req) {
    p_queue->queue[p_queue->last_queue_element] = req;
}

void remove_all(Queue* p_queue, int floor) {

}

void print_queue(Queue* p_queue) {
    for ()
}

bool no_off_requests(Queue* p_queue) {

}
