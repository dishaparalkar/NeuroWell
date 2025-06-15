#include <stdio.h>
#include <time.h>
#include <string.h>

int main() {
    time_t now;
    struct tm *current_time;
    FILE *file;
    char response[10];

    time(&now);
    current_time = localtime(&now);

    if (current_time->tm_hour >= 23) {
        printf("It's late (%02d:%02d). Are you still working? (yes/no): ",
               current_time->tm_hour, current_time->tm_min);
        scanf("%s", response);

        if (strcmp(response, "yes") == 0) {
            file = fopen("log/overwork_log.txt", "a");
            if (file == NULL) {
                printf("Error opening log file.\n");
                return 1;
            }

            fprintf(file, "%02d-%02d-%04d %02d:%02d - Overworking Detected\n",
                    current_time->tm_mday, current_time->tm_mon + 1, current_time->tm_year + 1900,
                    current_time->tm_hour, current_time->tm_min);

            fclose(file);
            printf("Logged: Overworking Detected.\n");
        } else {
            printf("Good! You're not overworking.\n");
        }
    } else {
        printf("It's not late yet (%02d:%02d). You're safe.\n",
               current_time->tm_hour, current_time->tm_min);
    }

    return 0;
}
