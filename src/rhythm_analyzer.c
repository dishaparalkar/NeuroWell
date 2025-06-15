#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Create folder if it doesn't exist (Windows-specific)
    system("mkdir log >nul 2>&1");

    FILE *in_fp = fopen("log/mood_log.txt", "r");
    FILE *out_fp = fopen("log/report.txt", "a");  // append mode

    if (in_fp == NULL) {
        printf("❌ Error: Could not open log/mood_log.txt. Please log some mood data first.\n");
        return 1;
    }

    if (out_fp == NULL) {
        printf("❌ Error: Could not open log/report.txt for writing.\n");
        fclose(in_fp);
        return 1;
    }

    // Get current time
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    fprintf(out_fp, "\n===== Mood Report (%02d-%02d-%04d %02d:%02d:%02d) =====\n",
            t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,
            t->tm_hour, t->tm_min, t->tm_sec);

    int mood, energy, focus;
    int total_mood = 0, total_energy = 0, total_focus = 0, count = 0;

    // Read and sum values
    while (fscanf(in_fp, "%d %d %d", &mood, &energy, &focus) == 3) {
        total_mood += mood;
        total_energy += energy;
        total_focus += focus;
        count++;
    }

    if (count == 0) {
        fprintf(out_fp, "⚠️ No mood data found. Please log entries using mood_logger.exe.\n");
    } else {
        float avg_mood = (float)total_mood / count;
        float avg_energy = (float)total_energy / count;
        float avg_focus = (float)total_focus / count;

        fprintf(out_fp, "Entries analyzed: %d\n", count);
        fprintf(out_fp, "Average Mood   : %.2f\n", avg_mood);
        fprintf(out_fp, "Average Energy : %.2f\n", avg_energy);
        fprintf(out_fp, "Average Focus  : %.2f\n", avg_focus);
    }

    fclose(in_fp);
    fclose(out_fp);

    printf("✅ Report generated successfully in log/report.txt!\n");
    return 0;
}
