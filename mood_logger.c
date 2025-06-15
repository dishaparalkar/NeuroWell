#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int mood, energy, focus;
    FILE *fp;

    printf("Enter your mood (1-5): ");
    scanf("%d", &mood);
    printf("Enter your energy level (1-5): ");
    scanf("%d", &energy);
    printf("Enter your focus level (1-5): ");
    scanf("%d", &focus);

    // ✅ Validate the input ranges
    if (mood < 1 || mood > 5 || energy < 1 || energy > 5 || focus < 1 || focus > 5) {
        printf("❌ Invalid input. Please enter values between 1 and 5.\n");
        return 1;
    }

    // Open file to append log
    fp = fopen("log/mood_log.txt", "a");
    if (fp == NULL) {
        printf("❌ Error opening file.\n");
        return 1;
    }

    // Optional: add timestamp (helpful for future enhancements)
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    fprintf(fp, "%02d-%02d-%04d %02d:%02d:%02d -> %d %d %d\n",
        t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,
        t->tm_hour, t->tm_min, t->tm_sec,
        mood, energy, focus);

    fclose(fp);
    printf("✅ Mood log saved successfully!\n");
    return 0;
}

