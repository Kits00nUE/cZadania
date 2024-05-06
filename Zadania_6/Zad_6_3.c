#include <stdio.h>

// Definicja funkcji
int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int subtract(int a, int b) {
    return a - b;
}

// Funkcja do wyboru operacji
int (*choose_operation())(int, int) {
    int (*func_ptr)(int, int) = NULL;
    int choice;

    do {
        // Pytanie użytkownika o wybór operacji
        printf("Wybierz operację: 1. Dodawanie, 2. Mnożenie, 3. Odejmowanie\n");
        scanf("%d", &choice);

        // Ustawienie wskaźnika do funkcji na odpowiednią funkcję
        switch (choice) {
            case 1:
                func_ptr = add;
                break;
            case 2:
                func_ptr = multiply;
                break;
            case 3:
                func_ptr = subtract;
                break;
            default:
                printf("Nieprawidłowy wybór.\n");
                func_ptr = NULL;
        }
    } while (func_ptr == NULL);

    return func_ptr;
}

int main() {
    // Wywołanie funkcji choose_operation i przypisanie zwróconego wskaźnika do func_ptr
    int (*func_ptr)(int, int) = choose_operation();

    // Pytanie użytkownika o dwie liczby
    printf("Podaj dwie liczby:\n");
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    // Wywołanie funkcji i wydrukowanie wyniku
    printf("Wynik: %d\n", func_ptr(num1, num2));

    return 0;
}