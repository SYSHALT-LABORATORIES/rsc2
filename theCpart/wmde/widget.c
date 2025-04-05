#include <stdio.h>
#include <stdlib.h>
#include "include/conio.h"
#include "include/conio.c"

int main(void) {
    int h, w;
    int i, j;

    printf("Width: ");
    scanf("%i", &w);
    printf("Height: ");
    scanf("%i", &h);

    c_clrscr();

    c_gotoxy(1, 1);
    printf("+");
    for (i = 2; i < w; i++) {
        printf("=");
    }
    if (w > 1) {
        printf("+");
    }
    printf("\n");

    for (i = 2; i < h; i++) {
        c_gotoxy(1, i);
        printf("|"); 
        for (j = 2; j < w; j++) {
            printf(" "); 
        if (w > 1) {
            printf("|"); 
        }
        printf("\n");
    }

    if (h > 1) {
        c_gotoxy(1, h);
        printf("+");
        for (i = 2; i < w; i++) {
            printf("=");
        }
        if (w > 1) {
            printf("+");
        }
        printf("\n");
    } else if (h == 1 && w > 1) {
        c_gotoxy(w, h);
        printf("+");
    } else if (h == 1 && w == 1) {
        c_gotoxy(w, h);
        printf("+");
    }


    c_getch();
    return w + h;
}
}
