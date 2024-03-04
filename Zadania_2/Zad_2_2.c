#include <stdio.h>


void sqr(float* x){
    (*x)=(*x)*2;
}

int main() {
    float x=4;
    float* pointer = &x;
    sqr(pointer);
    printf("x = %f\n", x);
    printf("pointer = %f\n", *pointer);



    return 0;
}