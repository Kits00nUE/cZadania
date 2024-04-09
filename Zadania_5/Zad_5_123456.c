#include <stdio.h>
#include <stdlib.h>

// Definicja struktury dla elementu listy
typedef struct Node {
    int data;
    struct Node* next;
} Node;
//Zadanie 1

// Funkcja do dodawania elementu na początek listy
void add_first(Node** head_ref, int new_data) {
    // 1. alokacja pamięci dla nowego elementu
    Node* new_node = (Node*) malloc(sizeof(Node));

    // 2. przypisanie wartości do nowego elementu
    new_node->data = new_data;

    // 3. ustawienie wskaźnika next nowego elementu na obecny początek listy
    new_node->next = (*head_ref);

    // 4. ustawienie nowego elementu jako początek listy
    (*head_ref) = new_node;
}
//Zadanie 2
void pop(Node** head_ref) {
    // 1. sprawdzenie, czy lista nie jest pusta
    if (*head_ref == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }

    // 2. zapisanie wskaźnika do pierwszego elementu w zmiennej tymczasowej
    Node* temp = *head_ref;

    // 3. przesunięcie wskaźnika głowy listy na następny element
    *head_ref = (*head_ref)->next;

    // 4. usunięcie pierwszego elementu
    free(temp);
}
//Zadanie 3
void remove_last(Node** head_ref) {
    // 1. sprawdzenie, czy lista nie jest pusta
    if (*head_ref == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }

    // 2. zapisanie wskaźnika do pierwszego elementu w zmiennej tymczasowej
    Node* temp = *head_ref;

    // 3. przesunięcie wskaźnika do momentu, kiedy następny element jest ostatnim na liście
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // 4. usunięcie ostatniego elementu
    free(temp->next);

    // 5. ustawienie wskaźnika next elementu przed ostatnim na NULL
    temp->next = NULL;
}
//Zadanie 4
void remove_by_index(Node** head_ref, int index) {
    // 1. sprawdzenie, czy lista nie jest pusta
    if (*head_ref == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }

    // 2. zapisanie wskaźnika do pierwszego elementu w zmiennej tymczasowej
    Node* temp = *head_ref;

    // Jeśli indeks to 0, usuwamy pierwszy element
    if (index == 0) {
        *head_ref = temp->next; // Zmieniamy głowę
        free(temp); // Usuwamy stary węzeł głowy
        return;
    }

    // 3. przesunięcie wskaźnika do momentu, kiedy dotrzemy do indeksu elementu, który chcemy usunąć
    for (int i=0; temp!=NULL && i<index-1; i++)
        temp = temp->next;

    // Jeśli indeks jest większy niż liczba elementów
    if (temp == NULL || temp->next == NULL)
        return;

    // Node temp->next to węzeł do usunięcia
    // Przechowaj wskaźnik do następnego węzła, który ma być usunięty
    Node *next = temp->next->next;

    // 4. usunięcie wybranego elementu
    free(temp->next);  // Usuń węzeł

    // 5. ustawienie wskaźnika next elementu przed usuniętym elementem na element po usuniętym elemencie
    temp->next = next;  // Odłącz usunięty węzeł od listy
}
//Zadanie 5
void remove_by_value(Node** head_ref, int value) {
    // 1. sprawdzenie, czy lista nie jest pusta
    if (*head_ref == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }

    // 2. zapisanie wskaźnika do pierwszego elementu w zmiennej tymczasowej
    Node* temp = *head_ref;

    // Jeśli wartość to wartość pierwszego elementu, usuwamy pierwszy element
    if (temp != NULL && temp->data == value) {
        *head_ref = temp->next; // Zmieniamy głowę
        free(temp); // Usuwamy stary węzeł głowy
        return;
    }

    // 3. przesunięcie wskaźnika do momentu, kiedy dotrzemy do elementu o określonej wartości
    Node* prev = NULL;
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // Jeśli wartość nie istnieje w liście
    if (temp == NULL) return;

    // Odłącz węzeł od listy
    prev->next = temp->next;

    // 4. usunięcie wybranego elementu
    free(temp);  // Usuń węzeł
}
//Zadanie 6
void insert_at_index(Node** head_ref, int new_data, int index) {
    // 1. alokacja pamięci dla nowego elementu
    Node* new_node = (Node*) malloc(sizeof(Node));

    // 2. przypisanie wartości do nowego elementu
    new_node->data = new_data;

    // Jeśli indeks to 0, dodajemy element na początek listy
    if (index == 0) {
        new_node->next = (*head_ref);
        (*head_ref) = new_node;
        return;
    }

    // 3. zapisanie wskaźnika do pierwszego elementu w zmiennej tymczasowej
    Node* temp = *head_ref;

    // 4. przesunięcie wskaźnika do momentu, kiedy dotrzemy do indeksu, na którym chcemy dodać nowy element
    for (int i=0; temp!=NULL && i<index-1; i++)
        temp = temp->next;

    // Jeśli indeks jest większy niż liczba elementów
    if (temp == NULL)
        return;

    // 5. ustawienie wskaźnika next nowego elementu na element, który był wcześniej na tym indeksie
    new_node->next = temp->next;

    // 6. ustawienie wskaźnika next elementu przed nowym elementem na nowy element
    temp->next = new_node;
}

int main() {



    return 0;
}