#include <stdio.h>
#include <time.h>
#include "utils.h"

void print_current_time() {
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    printf("[Utils] Current time: %02d:%02d:%02d\n",
           local->tm_hour, local->tm_min, local->tm_sec);
}
