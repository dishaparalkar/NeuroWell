#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE 256

int days_diff(struct tm a, struct tm b) {
    time_t t1 = mktime(&a);
    time_t t2 = mktime(&b);
    double seconds = difftime(t1, t2);
    return (int)(seconds / (60 * 60 * 24));
}

int main() {
    FILE *in_fp = fopen("log/mood_log.txt", "r");
    FILE *out_fp = fopen("log/weekly_report.txt", "a");
    if (!in_fp || !out_fp) {
        printf("Error opening files.\n");
        return 1;
    }

    time_t now = time(NULL);
    struct tm *current = localtime(&now);

    int mood, energy, focus, count = 0;
    float total_mood = 0, total_energy = 0, total_focus = 0;

    char line[MAX_LINE], mood_str[20], energy_str[20], focus_str[20];
    int y, m, d, h, min, s;

    while (fgets(line, sizeof(line), in_fp)) {
        if (sscanf(line, "%d-%d-%d %d:%d:%d - Mood: %s | Energy: %s | Focus: %s",
                   &y, &m, &d, &h, &min, &s, mood_str, energy_str, focus_str) == 9) {
            struct tm entry_time = {0};
            entry_time.tm_year = y - 1900;
            entry_time.tm_mon = m - 1;
            entry_time.tm_mday = d;
            entry_time.tm_hour = h;
            entry_time.tm_min = min;
            entry_time.tm_sec = s;

            int diff = days_diff(*current, entry_time);
            if (diff >= 0 && diff <= 7) {
                total_mood += atof(mood_str);
                total_energy += atof(energy_str);
                total_focus += atof(focus_str);
                count++;
            }
        }
    }

    fprintf(out_fp, "\n===== Weekly Mood Report (%02d-%02d-%04d) =====\n",
            current->tm_mday, current->tm_mon + 1, current->tm_year + 1900);

    if (count == 0) {
        fprintf(out_fp, "No entries from the past 7 days.\n");
    } else {
        fprintf(out_fp, "Entries analyzed: %d\n", count);
        fprintf(out_fp, "Average Mood   : %.2f\n", total_mood / count);
        fprintf(out_fp, "Average Energy : %.2f\n", total_energy / count);
        fprintf(out_fp, "Average Focus  : %.2f\n", total_focus / count);
    }

    fclose(in_fp);
    fclose(out_fp);
    printf("✅ Weekly report generated in log/weekly_report.txt!\n");

    return 0;
}
