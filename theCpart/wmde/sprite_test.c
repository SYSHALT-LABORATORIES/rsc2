#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>

#include "include/de.h"
#include "include/hicolor.h"

int main(void) {
	Sprite displaytest = malloc(sizeof(Sprite));
	int i;
	int j;
	for(i = 0; i < 320; i++) {
		for ( j=0; j <= 64; ++j) {
			draw_window(100,75,30,30);
			c_gotoxy(50, ceil(75/2));
			displaytest->x = i;
			displaytest->y = j-i;
			displaytest->rgb[j][j][j] = rand%(255); 
		
		}
	}
}
