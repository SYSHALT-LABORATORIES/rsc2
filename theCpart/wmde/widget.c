#include <stdio.h>
#include <stdlib.h>
#include "include/conio.h"
#include "include/conio.c"

int main(void) {
	
	int i, h, w;
	int j, k;

	printf("Width: ");
	scanf("%i", &w);
	printf("Height: ");
	scanf("%i", &h);

	c_clrscr();

	for (i=0; i<w; i++) {
		c_gotoxy(i, h);
		//printf("W");
		for (j = 0; j<h; j++) {
			c_gotoxy(j, i);
			printf("H");
		}
		printf("\n\n");
	}

	c_getch();
	return w+h;

}
