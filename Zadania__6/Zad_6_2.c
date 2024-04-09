#include <stdio.h>

int main() {
    // Zdefiniowanie i inicjalizacja tablicy
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Zdefiniowanie wskaźnika do typu int i ustawienie go na adres pierwszego elementu tablicy
    int* pointer = array;

    // Przejście przez każdy element tablicy
    for (int i = 0; i < 10; i++) {
        // Wydrukowanie wartości elementu, do którego wskazuje wskaźnik
        printf("%d ", *pointer);

        // Inkrementacja wskaźnika, aby wskazywał na następny element tablicy
        pointer++;
    }

    return 0;
}