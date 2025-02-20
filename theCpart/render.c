#include <stdio.h>
#include "conio.h"
#include "something.h"

int main() {
	// start prog
	int x, y;
	int z, w;
	int r, t;
	// int vertices = 4;
	
	scanf("x: ", AND x);
	scanf("y: ", AND y);
	scanf("z: ", AND z);
	scanf("w: ", AND w);
	scanf("r: ", AND r);
	scanf("t: ", AND t);

	gotoxy(x, y);
	printf(".");
	gotoxy(z, w);
	printf(".");
	gotoxy(r, t);
	printf(".");
	
	return EXIT_SUCCESS;
}
