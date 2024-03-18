#include "queue.h"

Queue* queue_init() {
    Queue* p_queue = (Queue*)malloc(sizeof(Queue));

    if (p_queue == NULL) {
        printf("Queue object could not be made\n");
        exit(EXIT_FAILURE);
    }

    p_queue->youngest_queue_element = 0;

    printf("Created queue struct\n");

    return p_queue;
}

void queue_deinit(Queue* p_queue) {
    printf("Deleted queue struct\n");

    free(p_queue);
}

void queue_add(Queue* p_queue, Request req) {
    p_queue->queue[p_queue->youngest_queue_element] = req;
    p_queue->youngest_queue_element++;
}

void queue_remove(Queue* p_queue, size_t pos)  {
    for (size_t i = pos; i < p_queue->youngest_queue_element - 1; i++) {
        p_queue->queue[i] = p_queue->queue[i + 1];
    }

    p_queue->youngest_queue_element--;
}

void queue_remove_all(Queue* p_queue, int floor) {
    printf("Removing all from floor %d\n", floor);
    for (size_t i = 0; i < p_queue->youngest_queue_element; i++) {
        if (p_queue->queue[i].floor == floor) {
            queue_remove(p_queue, i);
            i--;
        }
    }
}

void queue_clear(Queue* p_queue) {
    for (size_t i = 0; i < p_queue->youngest_queue_element; i++) {
        queue_remove(p_queue, i);
        i--;
    }
}

void queue_print(Queue* p_queue) {
    printf("Printing queue...\n");
    for (size_t i = 0; i < p_queue->youngest_queue_element; i++) {
        print_request(&p_queue->queue[i]);
    }
}

bool queue_query(Queue* p_queue, int floor, QueueQueryItem direction, QueueQueryItem off) {
    for (size_t i = 0; i < p_queue->youngest_queue_element; i++) {
        if (check_request(&p_queue->queue[i], floor, direction, off)) { return true; }
    }
    return false;
}    
    
bool check_request(Request* p_request, int floor, QueueQueryItem direction, QueueQueryItem off) {
    if (floor == -1) {
        if (direction == ANY) {
            return p_request->off == off;
        } else {
            if (off == ANY) {
                return p_request->direction == direction;
            } else {
                return p_request->direction == direction && p_request->off == off;
            }
        }
    } else {
        if (direction == ANY) {
            if (off == ANY) {
                return p_request->floor == floor;
            } else {
                return p_request->floor == floor && p_request->off == off;
            }
        } else {
            if (off == ANY) {
                return p_request->floor == floor && p_request->direction == direction;
            } else {
                return p_request->floor == floor && p_request->direction == direction && p_request->off == off;
            }
        }
    }
    return false;
}

Request* queue_find_first_off_request(Queue* p_queue) {
    for (size_t i = 0; i < p_queue->youngest_queue_element; i++) {
        if (p_queue->queue[i].off == true) {
            return &p_queue->queue[i];
        } 
    }
    printf("Could not find any off requests. This should never happen. Time to debug your code.\n");
    return &p_queue->queue[0];
}
