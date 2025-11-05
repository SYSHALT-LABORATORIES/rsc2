#include <stdio.h>
#include "include/de.h"
#include "include/hicolor.h" //png module 1

int draw_toolbar(int w, int h, int x, int y, bool horiz) {
	if (!horiz) {
        draw_window(5, 25, 4, 4);
    }
}

void draw_window() {
	draw_toolbar(50, 50, 50, 70, true)
}

