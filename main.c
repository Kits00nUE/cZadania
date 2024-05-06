#include <stdio.h>
#include <string.h>

int main() {
    FILE* file = fopen("C:\\Users\\phant\\CLionProjects\\ProjektwC\\Zadania_7\\input2.txt", "r");
    char line[1024];
    int game_number = 1;
    int total_dice_power = 0;

    // First part: calculate total dice power
    while (fgets(line, sizeof(line), file)) {
        char* saveptr1;
        char* game = strtok_r(line, ":", &saveptr1);
        char* round = strtok_r(NULL, ";", &saveptr1);
        int max_red = 0, max_green = 0, max_blue = 0;

        while (round != NULL) {
            char* saveptr2;
            char* color = strtok_r(round, ",", &saveptr2);
            int red = 0, green = 0, blue = 0;

            while (color != NULL) {
                int quantity;
                char color_name[20];
                sscanf(color, "%d %s", &quantity, color_name);

                if (strcmp(color_name, "red") == 0) {
                    red += quantity;
                    if (red > max_red) {
                        max_red = red;
                    }
                } else if (strcmp(color_name, "green") == 0) {
                    green += quantity;
                    if (green > max_green) {
                        max_green = green;
                    }
                } else if (strcmp(color_name, "blue") == 0) {
                    blue += quantity;
                    if (blue > max_blue) {
                        max_blue = blue;
                    }
                }

                color = strtok_r(NULL, ",", &saveptr2);
            }

            round = strtok_r(NULL, ";", &saveptr1);
        }

        int game_dice_power = max_red * max_green * max_blue;
        total_dice_power += game_dice_power;
        game_number++;
    }

    printf("Total dice power: %d\n", total_dice_power);

    // Reset file pointer and game number for the second part
    fseek(file, 0, SEEK_SET);
    game_number = 1;
    int sum_of_possible_games = 0;

    // Second part: calculate sum of possible games
    while (fgets(line, sizeof(line), file)) {
        char* saveptr1;
        char* game = strtok_r(line, ":", &saveptr1);
        char* round = strtok_r(NULL, ";", &saveptr1);
        int is_possible = 1;

        while (round != NULL && is_possible) {
            char* saveptr2;
            char* color = strtok_r(round, ",", &saveptr2);
            int red = 0, green = 0, blue = 0;

            while (color != NULL) {
                int quantity;
                char color_name[20];
                sscanf(color, "%d %s", &quantity, color_name);

                if (strcmp(color_name, "red") == 0) {
                    red += quantity;
                } else if (strcmp(color_name, "green") == 0) {
                    green += quantity;
                } else if (strcmp(color_name, "blue") == 0) {
                    blue += quantity;
                }

                if (red > 12 || green > 13 || blue > 14) {
                    is_possible = 0;
                    break;
                }

                color = strtok_r(NULL, ",", &saveptr2);
            }

            round = strtok_r(NULL, ";", &saveptr1);
        }

        if (is_possible) {
            sum_of_possible_games += game_number;
        }

        game_number++;
    }

    fclose(file);
    printf("Sum of possible games: %d\n", sum_of_possible_games);
    return 0;
}