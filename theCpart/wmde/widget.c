#include <stdio.h>
#include <stdlib.h>
#include "include/conio.h"
#include "include/conio.c"
#include "include/de.h"

int widget(void) { // to compile separate use int main(void), this is for /kernel.c
    int h, w;
    int i, j;
    int key_code;
    int posx, posy;

    posx = 1;
    posy = 1;

    w = 10;
    h = 10;

    char screen_buffer[2000]={' '};

    for(EVER) {
        //c_clrscr();
        draw_window(w, h, posx, posy);
	if (_kbhit()) {
		key_code = c_getch();
		if (key_code == KB_UP) {
			w=0;
			h=0;
			posy = 1000;
			w = w * 5;
			h = h * 10;
		} if (key_code == KB_DOWN) {
			w=0;
			h=0;
			posy = -1000;
			w = w * 5;
			h = h * 10;
		} if (key_code == KB_LEFT) {
			w=0;
			h=0;
		       posx = -1000;
	       	       w = w * 3;
		       h = (h * 3) + w;	
		} if (key_code == KB_RIGHT) {
			w=0;
			h=0;
		        posx = 1000;
			w = w * 5;
			h = h * 10;
		}   	   
	}
    }

    c_getch();
    return w + h;
}
