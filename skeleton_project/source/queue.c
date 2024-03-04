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

// bool queue_has_off_requests(Queue* p_queue) {
//     for (size_t i = 0; i < p_queue->youngest_queue_element; i++) {
//         if (p_queue->queue[i].off == true) {
//             return true;
//         }
//     }
//     return false;
// }

bool queue_query(Queue* p_queue, int floor, QueueQueryItem direction, QueueQueryItem off) {
    if (floor == -1) {
        if (direction == ANY) {
            // printf("floor: ANY, direction: ANY, off: ANY");
            return queue_query_off(p_queue, off);
        } else {
            if (off == ANY) {
                // printf("floor: ANY, direction: something, off: ANY");
                return queue_query_direction(p_queue, direction);
            } else {
                // printf("floor: ANY, direction: something, off: something");
                return queue_query_off(p_queue, off) && queue_query_direction(p_queue, direction);
            }
        }
    } else {
        if (direction == ANY) {
            if (off == ANY) {
                // printf("floor: something, direction: ANY, off: ANY");
                return queue_query_floor(p_queue, floor);
            } else {
                // printf("floor: something, direction: ANY, off: something");
                return queue_query_floor(p_queue, floor) && queue_query_off(p_queue, off);
            }
        } else {
            if (off == ANY) {
                // printf("floor: something, direction: something, off: ANY");
                return queue_query_floor(p_queue, floor) && queue_query_direction(p_queue, direction);
            } else {
                // printf("floor: something, direction: something, off: something");
                return queue_query_floor(p_queue, floor) && queue_query_off(p_queue, off) && queue_query_direction(p_queue, direction);
            }
        }
    }
    return false;
}

static bool queue_query_floor(Queue* p_queue, int floor) {
    for (size_t i = 0; i < p_queue->youngest_queue_element; i++) {
        if (p_queue->queue[i].floor == floor) {
            return true;
        }
    }
    return false;
}

static bool queue_query_direction(Queue* p_queue, bool direction) {
    for (size_t i = 0; i < p_queue->youngest_queue_element; i++) {
        if (p_queue->queue[i].direction == direction) {
            return true;
        }
    }
    return false;
}

static bool queue_query_off(Queue* p_queue, bool off) {
    for (size_t i = 0; i < p_queue->youngest_queue_element; i++) {
        if (p_queue->queue[i].off == off) {
            return true;
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
