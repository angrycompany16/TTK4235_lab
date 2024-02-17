#include "request.h"

void print_request(Request* request) {
    printf("Floor: %d", request->floor);
    printf("Direction: %s", request->up ? "up" : "down");
    printf("Going off: %s", request->off ? "yes" : "no");
}
