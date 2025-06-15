#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *in = fopen("mood_log.txt", "r");
    FILE *out = fopen("mood_log_clean.txt", "w");

    if (!in || !out) {
        printf("❌ Failed to open files.\n");
        return 1;
    }

    char line[256];
    int mood, energy, focus;
    while (fgets(line, sizeof(line), in)) {
        // Extract the last 3 numbers from the line
        if (sscanf(line, "%*[^>] -> %d %d %d", &mood, &energy, &focus) == 3) {
            if (mood >= 1 && mood <= 5 && energy >= 1 && energy <= 5 && focus >= 1 && focus <= 5) {
                fputs(line, out);
            }
        }
    }

    fclose(in);
    fclose(out);

    // Replace original file
    remove("mood_log.txt");
    rename("mood_log_clean.txt", "mood_log.txt");

    printf("✅ Invalid entries removed. Log cleaned!\n");
    return 0;
}

