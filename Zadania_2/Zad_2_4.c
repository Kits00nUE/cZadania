#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct Students{
    char name[6];
    double grade;
};


int main() {
    srand(time(NULL));
//generowanie losowych ocen oraz imion studentów
    struct Students students[100];
    for(int i=0;i<100;i++){
        //generowanie ocen od 2.00 do 5.00
        students[i].grade = (rand() % 301) / 100.0 + 2.0;
        char name[20];
        for(int j=0;j<5;j++){
            name[j] = (rand() % (122-97)) + 97;
        }
        strcpy(students[i].name,name);
    }

    //sortowanie tablicy
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(students[i].grade>students[j].grade){
                double temp = students[i].grade;
                students[i].grade = students[j].grade;
                students[j].grade = temp;
                char temp2[20];
                strcpy(temp2,students[i].name);
                strcpy(students[i].name,students[j].name);
                strcpy(students[j].name,temp2);
            }
        }
    }
    //wypisanie elementów tablicy
    for(int i=0;i<100;i++){
        printf("name: %s grade: %.2f\n",students[i].name,students[i].grade);
    }
    return 0;
}
