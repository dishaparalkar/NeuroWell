#include <stdio.h>
#include "idle_tracker.h"
#include "mood_logger.h"
#include "late_night_watch.h"
#include "utils.h"

int main() {
    printf("Welcome to NeuroWell!\n");

    // Call idle tracker
    check_idle_time();
    prompt_mood_input();
    check_late_night_work();
    print_current_time();


    return 0;
}

