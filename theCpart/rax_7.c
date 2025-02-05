#include <stdio.h>
#include <stdlib.h>
#include "something.h"

int main(int argc, char **argv) {
	int *ptr;
  	ptr = malloc(sizeof(argc));
	return ptr;
	free(ptr);
}
