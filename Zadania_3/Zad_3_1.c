
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//funkcja tworzenia trojkata pascala z dynamiczna pamiecią
void pascal_triangle(int n) {
    int **arr = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        arr[i] = (int *) malloc((i + 1) * sizeof(int));
    }
    for (int line = 0; line < n; line++) {
        for (int i = 0; i <= line; i++) {
            if (line == i || i == 0) {
                arr[line][i] = 1;
            } else {
                arr[line][i] = arr[line - 1][i - 1] + arr[line - 1][i];
            }
            printf("%d ", arr[line][i]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}


int main() {

    int n;
    printf("Podaj liczbe wierszy trojkata Pascala: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Liczba wierszy nie moze byc ujemna");
    } else {
        pascal_triangle(n);




    }return 0;
}