#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "something.h"

int main(void) {
    char exc[4]; // x copy to
    char ids[4]; // y copy to
    char dsi[4]; // z copy to
    char dso[4]; // w copy from

    int x, y, z, w;
    x = scanf("v1 position: ", &x);
    y = scanf("v2 position: ", &y);
    z = scanf("v3 position: ", &z);
    w = scanf("v4 position: ", &w);

    sprintf(exc, "%d", x);
    sprintf(ids, "%d", y);
    sprintf(dsi, "%d", z);
    sprintf(dso, "%d", w);

    char space[] = " ";
    char *Command = "batbox /g";
    unmessup(Command, space, exc, ids, dsi, dso); /* Absolutely evil. */

    return EXIT_SUCCESS;
}