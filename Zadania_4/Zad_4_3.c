#include <stdio.h>

int tab[4]={1,2,3,4};
//permute
void permute(int* tab, int n){
    if(n==1){
        for(int i=0; i<4; i++){
            printf("%d ", tab[i]);
        }
        printf("\n");
    }
    else{
        for(int i=0; i<n; i++){
            int temp = tab[i];
            tab[i] = tab[n-1];
            tab[n-1] = temp;
            permute(tab, n-1);
            temp = tab[i];
            tab[i] = tab[n-1];
            tab[n-1] = temp;
        }
    }
}

int main() {
    printf("permutacje: \n");
    permute(tab, 4);


    return 0;
}
