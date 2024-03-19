//
// Created by phant on 19.03.2024.
//
#include <stdio.h>
#include <stdlib.h>
int tab [10];
//funkcja wyszukiwania binarnego
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] > x) {
            return binarySearch(arr, l, mid - 1, x);
        }
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main() {

    for (int i = 0; i < 10; i++) {
        tab[i] = rand() % 100 + 1;
    }
    //sort tab
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (tab[j] > tab[j + 1]) {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        printf("tab[%d] = %d\n", i, tab[i]);
    }
    printf( "Podaj liczbe do wyszukania: ");
    int x;
    scanf("%d", &x);
    int result = binarySearch(tab, 0, 9, x);
    if (result == -1) {
        printf("Element nie istnieje w tablicy\n");
    } else {
        printf("Element jest na pozycji %d\n", result);
    }
    return 0;
}
