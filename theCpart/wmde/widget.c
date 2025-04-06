#include <stdio.h>
#include <stdlib.h>
#include "include/conio.h"
#include "include/conio.c"
#include "include/de.h"

int main(void) {
    int h, w;
    int i, j;

    w = 10;
    h = 10;

    for(EVER) {
        c_clrscr();
        draw_window(w, h, 1, 1);
    }

    c_getch();
    return w + h;
}
