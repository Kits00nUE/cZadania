#include <stdio.h>
#include <string.h>

// Funkcja zamieniająca słowne reprezentacje liczb na numeryczne
void replace_word_with_number(char* str, const char* word, char number) {
    char* pos = strstr(str, word);
    while (pos != NULL) {
        *pos = number;
        memmove(pos + 1, pos + strlen(word), strlen(pos + strlen(word)) + 1);
        pos = strstr(str, word);
    }
}

int main() {
    FILE* input_file = fopen("C:\\Users\\phant\\CLionProjects\\cZadania\\Zadania_7\\input.txt", "r");
    FILE* output_file = fopen("C:\\Users\\phant\\CLionProjects\\cZadania\\Zadania_7\\output.txt", "w");

    char line[1024];
    while (fgets(line, sizeof(line), input_file)) {
        replace_word_with_number(line, "one", '1');
        replace_word_with_number(line, "two", '2');
        replace_word_with_number(line, "three", '3');
        replace_word_with_number(line, "four", '4');
        replace_word_with_number(line, "five", '5');
        replace_word_with_number(line, "six", '6');
        replace_word_with_number(line, "seven", '7');
        replace_word_with_number(line, "eight", '8');
        replace_word_with_number(line, "nine", '9');

        char* first_digit = strpbrk(line, "123456789");
        char* last_digit = strpbrk(line, "\n");
        while (last_digit > first_digit && !(*last_digit >= '1' && *last_digit <= '9')) {
            --last_digit;
        }

        if (first_digit != NULL && last_digit != NULL && first_digit < last_digit) {
            fprintf(output_file, "%c%c\n", *first_digit, *last_digit);
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}//
// Created by phant on 23.04.2024.
//
