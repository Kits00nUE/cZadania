
#include <stdio.h>
#include <string.h>
#include <stdlib.h>




int main() {

    printf("podaj liczbe kolumn tablicy: ");
    int n;
    scanf("%d", &n);
    printf("podaj liczbe wierszy tablicy: ");
    int m;
    scanf("%d", &m);
    int **arr = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        arr[i] = (int *) malloc(m * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = rand() % 100;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);





    return 0;
}