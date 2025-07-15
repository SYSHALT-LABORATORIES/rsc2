#include <stdio.h>
#include <stdlib.h>
#include "include/conio.h"
#include "include/conio.c"
#include "include/de.h"

int main(void ) {
    int desired_size;
    printf("Size: ");
    scanf("%i", &desired_size);
    for (EVER) {
        //draw_dropdown(10, 10, 50, 50);
        draw_triangle((round(desired_size/2)), desired_size, 50, 0);
    }
    return 32;
}
