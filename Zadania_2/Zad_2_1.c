#include <iostream>


void addone(int* x){
    (*x)++;
}

int main() {
    int x=1;
    int* pointer = &x;
    addone(pointer);

    printf("x = %d\n", x);
    printf("pointer = %d\n", *pointer);



    return 0;
}