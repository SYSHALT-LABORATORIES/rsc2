#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "theCpart/wmde/desktop.c"
#include "theCpart/wmde/widget.c"
#include "theCpart/wmde/include/conio.c"
#include "theCpart/wmde/include/conio.h"
#include "theCpart/wmde/include/de.h"

int main(void) {
    const char *name = "rsc2";
    char *vidmem = (char*)0xb8000; // video memory
	  // implement .exe running tech
    for(EVER) {
        desktop();
    }
    return 0;
}
