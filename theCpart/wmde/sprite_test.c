#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>

//dupe again fuck#include "include/de.h"
#include "include/hicolor.h"

int main(void) {
	Sprite displaytest;
	int i;
	int j;
	printf("\n");
	for(i = 0; i < 320; i++) {
		for ( j=0; j <= 64; ++j) {
			draw_window(60,40,30,30);
			c_gotoxy(50, ceil(75/2));
			displaytest.x = i;
			displaytest.y = j-i;
			displaytest.rgb[j][j][j] = rand()%255; 
		
		}
	}
}
