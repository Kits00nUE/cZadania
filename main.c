#include <stdio.h>
#include <string.h>

int main() {
    FILE* file = fopen("C:\\Users\\phant\\CLionProjects\\cZadania\\Zadania_7\\input2.txt", "r");
    if (file == NULL) {
        printf("Nie można otworzyć pliku.\n");
        return 1;
    }

    int game_id, count, round;
    int red, green, blue;
    char color[10];
    char line[1024];

    while (fscanf(file, "Game %d:", &game_id) == 1) {
        round = 1;
        while (fgets(line, sizeof(line), file)) {
            char* round_start = line;
            char* round_end;
            while ((round_end = strchr(round_start, ';')) != NULL) {
                *round_end = '\0';
                red = green = blue = 0; // Reset the counters for each color at the start of each round
                char* color_start = round_start;
                char* color_end;
                while ((color_end = strchr(color_start, ',')) != NULL || (color_end = strchr(color_start, ';')) != NULL) {
                    *color_end = '\0';
                    sscanf(color_start, "%d %s", &count, color);
                    if (strcmp(color, "red") == 0) {
                        red += count;
                    } else if (strcmp(color, "green") == 0) {
                        green += count;
                    } else if (strcmp(color, "blue") == 0) {
                        blue += count;
                    }
                    color_start = color_end + 1;
                }
                printf("Game %d Round %d: red %d green %d blue %d\n", game_id, round, red, green, blue);
                round++;
                round_start = round_end + 1;
            }
            break;
        }
    }

    fclose(file);

    return 0;
}