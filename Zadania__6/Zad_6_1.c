#include <stdio.h>

// Definicja unii
union Data {
    int i;
    float f;
    char c;
};

int main() {
    union Data data;

    // Przypisanie i wydrukowanie wartości int
    data.i = 10;
    printf("data.i: %d\n", data.i);

    // Przypisanie i wydrukowanie wartości float
    data.f = 220.5;
    printf("data.f: %.2f\n", data.f);

    // Przypisanie i wydrukowanie wartości char
    data.c = 'C';
    printf("data.c: %c\n", data.c);

    return 0;
}