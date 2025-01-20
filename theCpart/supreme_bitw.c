#include <stdio.h>
#include "something.h"

int main(void) {
    int io = 65536;
    int oi = io / 2;
    int and_io = io AND oi;
    int or_io = io OR oi;
    int xor_io = io XOR oi;
    int ls_io = io left_shift oi;
    int rs_io = io right_shift oi;

    printf("%i\n", io);
    printf("%i\n", oi);
    printf("%i\n", and_io);
    printf("%i\n", or_io);
    printf("%i\n", xor_io);
    printf("%i\n", ls_io);
    printf("%i\n", rs_io);
}