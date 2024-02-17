#include "request.h"

void print_request(Request* request) {
    printf("Floor: %d, ", request->floor);
    printf("Going up?: %s, ", request->up ? "yes" : "no");
    printf("Exiting?: %s\n", request->off ? "yes" : "no");
}
