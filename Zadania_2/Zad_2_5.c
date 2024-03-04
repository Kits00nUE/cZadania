#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Contact {
    char name[20];
    char surname[20];
    char phone[10];
};
//funkcja dodawania kontaktu
void addContact(struct Contact* c, char* name, char* surname, char* phone) {
    strcpy(c->name, name);
    strcpy(c->surname, surname);
    strcpy(c->phone, phone);
}
//funkcja wyszukania kontaktu po nazwisku
struct Contact* findContact(struct Contact* contacts, int size, char* surname) {
    for (int i = 0; i < size; i++) {
        if (strcmp(contacts[i].surname, surname) == 0) {
            return &contacts[i];
        }
    }
    return NULL;
}
//funkcja usuwania kontaktu po nazwisku
void deleteContact(struct Contact* contacts, int size, char* surname) {
    for (int i = 0; i < size; i++) {
        if (strcmp(contacts[i].surname, surname) == 0) {
            for (int j = i; j < size - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            break;
        }
    }
}
//funckja wypisania wszystkich kontaktow
void printContacts(struct Contact* contacts, int size) {
    for (int i = 0; i < size; i++) {
        printf("name: %s surname: %s phone: %s\n", contacts[i].name, contacts[i].surname, contacts[i].phone);
    }
}
int main() {
    srand(time(NULL));

    struct Contact contacts[10];

    // Generowanie losowych danych dla kontaktów
    for (int i = 0; i < 10; i++) {
        // Generowanie losowego imienia
        for (int j = 0; j < 5; j++) {
            contacts[i].name[j] = (rand() % 26) + 'a';
        }
        contacts[i].name[5] = '\0'; // Dodanie znaku końca ciągu znaków

        // Generowanie losowego nazwiska
        for (int j = 0; j < 5; j++) {
            contacts[i].surname[j] = (rand() % 26) + 'a';
        }
        contacts[i].surname[5] = '\0'; // Dodanie znaku końca ciągu znaków

        // Generowanie losowego numeru telefonu
        for (int j = 0; j < 9; j++) {
            contacts[i].phone[j] = (rand() % 10) + '0'; // Cyfry od '0' do '9'
        }
        contacts[i].phone[9] = '\0'; // Dodanie znaku końca ciągu znaków
    }
    //interfejs użytkownika dla wszystkich funkcji dodaj znajdz usun wypisz w pętli
    int cont = 1;
    while (cont == 1) {
        printf("1. Dodaj kontakt\n");
        printf("2. Znajdz kontakt\n");
        printf("3. Usun kontakt\n");
        printf("4. Wypisz kontakty\n");
        printf("5. Wyjdz\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            char name[20];
            char surname[20];
            char phone[10];
            printf("Podaj imie: ");
            scanf("%s", name);
            printf("Podaj nazwisko: ");
            scanf("%s", surname);
            printf("Podaj numer telefonu: ");
            scanf("%s", phone);
            addContact(&contacts[0], name, surname, phone);
        } else if (choice == 2) {
            char surname[20];
            printf("Podaj nazwisko: ");
            scanf("%s", surname);
            struct Contact* c = findContact(contacts, 10, surname);
            if (c != NULL) {
                printf("name: %s surname: %s phone: %s\n", c->name, c->surname, c->phone);
            } else {
                printf("Nie znaleziono kontaktu\n");
            }
        } else if (choice == 3) {
            char surname[20];
            printf("Podaj nazwisko: ");
            scanf("%s", surname);
            deleteContact(contacts, 10, surname);
        } else if (choice == 4) {
            printContacts(contacts, 10);
        } else if (choice == 5) {
            cont = 0;
        }
    }
    return 0;
}
