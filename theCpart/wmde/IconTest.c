#include <stdio.h>
#include <stdlib.h>
#include "include/de.h"

int main(void) {
	Icon something;
	int i; int j;

	for (i = 0; i<80; i++) {
		for (j = 0; j<24; j++) {
			something.x = i;
			something.y = j;
			calc_icon_grid_desktop(i,j,&something);
		}
	}
	return 0;
}
