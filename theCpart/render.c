#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    strcat(Command, space); // "batbox /g "
    strcat(Command, exc); // "batbox /g (x)"
    strcat(Command, space); // "batbox /g (x) "
    strcat(Command, ids); // "batbox /g (x) (y)"
    
    system(Command);
    printf(".");
    memset(Command, 0, sizeof(Command));
    strcat(Command, "batbox /g");
    strcat(Command, space); // "batbox /g "
    strcat(Command, dsi); // "batbox /g (z)"
    strcat(Command, space); // "batbox /g (z) "
    strcat(Command, dso); // "batbox /g (z) (w)"
    system(Command);
    printf(".");
    memset(Command, 0, sizeof(Command));

    strcat(Command, "batbox /g");
    strcat(Command, space); // "batbox /g "
    strcat(Command, exc); // "batbox /g (x)"
    strcat(Command, space); // "batbox /g (x) "
    strcat(Command, dsi); // "batbox /g (x) (z)"
    system(Command);
    printf(".");
    memset(Command, 0, sizeof(Command));

    strcat(Command, "batbox /g");
    strcat(Command, space); // "batbox /g "
    strcat(Command, ids); // "batbox /g (y)"
    strcat(Command, space); // "batbox /g (y) "
    strcat(Command, dso); // "batbox /g (y) (w)"
    system(Command);
    printf(".");
    memset(Command, 0, sizeof(Command));

    return EXIT_SUCCESS;
}