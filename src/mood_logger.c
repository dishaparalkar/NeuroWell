#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int mood, energy, focus;

    printf("Enter your mood (1–5): ");
    scanf("%d", &mood);
    printf("Enter your energy level (1–5): ");
    scanf("%d", &energy);
    printf("Enter your focus level (1–5): ");
    scanf("%d", &focus);

    // Create folder if not exists (Windows-specific)
    system("mkdir log >nul 2>&1");

    FILE *log = fopen("log/mood_log.txt", "a");
    if (log == NULL) {
        printf("Failed to open log file.\n");
        return 1;
    }

    // Save only raw values (to match analyzer)
    fprintf(log, "%d %d %d\n", mood, energy, focus);
    fclose(log);

    printf("Mood log saved successfully!\n");
    return 0;
}
