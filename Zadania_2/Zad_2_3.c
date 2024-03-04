#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x;
    int y;
};

void move(struct Point* p) {
    p->x++;
    p->y++;
}

struct Rectangle {
    struct Point p1;
    struct Point p2;
    int width;
    int height;
};

void count(struct Rectangle* r, int* Area, int* Perimeter) {
    int width = r->width;
    int height = r->height;
    *Area = width * height;
    *Perimeter = 2 * (width + height);
}

int main() {
    struct Point a = {0, 0};
    struct Point b = {0, 0};

    a.x = 1;
    a.y = 2;
    b.x = 3;
    b.y = 4;
    move(&a);
    move(&b);

    printf("a.x = %d\t", a.x);
    printf("a.y = %d\n", a.y);
    printf("b.x = %d\t", b.x);
    printf("b.y = %d\n", b.y);

    int Area, Perimeter;
    struct Rectangle rect = {{0, 0}, {0, 0}, 5, 6};

    count(&rect, &Area, &Perimeter);

    printf("Area = %d\n", Area);
    printf("Perimeter = %d\n", Perimeter);

    return 0;
}
