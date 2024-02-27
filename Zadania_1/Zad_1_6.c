
#include <stdio.h>
#include <string.h>

int main() {

    int licznikGier = 0;
    char wynik[100][2][20];
    int licznikWygranych1 = 0;
    int licznikWygranych2 = 0;
    int cont=1;
    while (cont==1) {
        printf("player 1 wybierz paper/rock/scissors: ");
        char wybor[20];
        scanf(" %s", wybor);
        printf("player2 wybierz paper/rock/scissors: ");
        char wybor2[20];
        scanf(" %s", wybor2);

        strcpy(wynik[licznikGier][0], wybor);
        strcpy(wynik[licznikGier][1], wybor2);
        licznikGier++;

        if (strcmp(wybor, "paper") == 0 && strcmp(wybor2, "rock") == 0) {
            printf("wygral player 1\n");
            licznikWygranych1++;
        } else if (strcmp(wybor, "rock") == 0 && strcmp(wybor2, "scissors") == 0) {
            printf("wygral player 1\n");
            licznikWygranych1++;
        } else if (strcmp(wybor, "scissors") == 0 && strcmp(wybor2, "paper") == 0) {
            printf("wygral player 1\n");
            licznikWygranych1++;
        } else if (strcmp(wybor, "rock") == 0 && strcmp(wybor2, "paper") == 0) {
            printf( "wygral player 2\n");
            licznikWygranych2++;
        } else if (strcmp(wybor, "scissors") == 0 && strcmp(wybor2, "rock") == 0) {
            printf( "wygral player 2\n");
            licznikWygranych2++;
        } else if (strcmp(wybor, "paper") == 0 && strcmp(wybor2, "scissors") == 0) {
            printf( "wygral player 2\n");
            licznikWygranych2++;
        } else if (strcmp(wybor, wybor2) == 0) {
            printf("remis\n");
        }else if(strcmp(wybor,"scores")==0||strcmp(wybor2,"scores")==0){
            printf("player1: %i player2: %i\n",licznikWygranych1,licznikWygranych2);
            for(int i=0;i<licznikGier-1;i++) {
                printf("player1: %s player2: %s\n", wynik[i][0], wynik[i][1]);
                cont=0;
            }
        }



    }return 0;
}