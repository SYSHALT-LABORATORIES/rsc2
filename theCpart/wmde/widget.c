#include <stdio.h>
#include <stdlib.h>
#include "include/de.h"

int main(void) { // to compile separate use int main(void), this is for /kernel.c
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
       // c_clrscr();
        draw_window(w, h, posx, posy);
	if (c_kbhit()) {
		key_code = c_getch();
		if (key_code == KB_UP) {
<<<<<<< HEAD
           posx = 0;
		  	   posy = 100;
			     w = 80;
			     h = 12;
			     c_clrscr();
		} if (key_code == KB_DOWN) {
           posx = 0;
			     posy = 13;
			     w = 80;
			     h = 13;
			     c_clrscr();
		} if (key_code == KB_LEFT) {
		       posx = 0;
           posy = 0;
	       	 w = 40;
		       h = 25;
		       c_clrscr();
		} if (key_code == KB_RIGHT) {
		       posx = 41;
           posy = 0;
		       w = 40;
		       h = 25;
		       c_clrscr();
=======
			posy = 1000;
			w  = w * 5;
			h  = h * 10;
			c_gotoxy(posx, posy);
			draw_window(w,h,posx,posy);
		} if (key_code == KB_DOWN) {
			posy = -1000;
		        w = w * 5;
			h = h * 10;
			c_gotoxy(posx, posy);
			draw_window(w,h,posx,posy);
		} if (key_code == KB_LEFT) {
		       posx = -1000;
	       	       w = w * 3;
		       h = (h * 3) + w;	
		       c_gotoxy(posx, posy);
		       draw_window(w,h,posx,posy);
		} if (key_code == KB_RIGHT) {
		        posx = 1000;
		        w = w * 5;
			h = h * 10;
			c_gotoxy(posx, posy);
			draw_window(w,h,posx,posy   );
>>>>>>> refs/remotes/origin/main
		}   	   
	}
    }

    c_getch();
    return w + h;
}
