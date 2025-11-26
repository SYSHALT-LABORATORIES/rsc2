#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>
#include "include/hicolor.h"
#include "include/conio.c"

int main(void) {
	Hire prueba;
	int i;
	int j;
  int k;
	printf("\n");
	for (i = 0; i < 2047; i++) {
		prueba.rgb[0][0][i] = i ^ 0x10;
    for (j = 0; j < 2047; j++) {
			printf("%c", prueba.rgb[0][0][i]);
		}
    for (k = 0; k < 15; k++) {
      prueba.rgb[i][i][0] = k;
      printf("%i", prueba.rgb[i][i][0]);
    } 
	}
}
