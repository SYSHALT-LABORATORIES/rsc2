#define TRUE 1
#define FALSE 0
#define NULL ((void*) 0x0) 

#define AND &
#define OR |
#define XOR ^
#define left_shift <<
#define right_shift >>
#define NOT ~

#define C_AND &&
#define C_NOTEQ !=
#define EXIT_SUCCESS 0
#define EXIT_FAIL 1

int unmessup (comm, s, e, i, d, ds) {
    strcat(comm, s); // "batbox /g "
    strcat(comm, e); // "batbox /g (x)"
    strcat(comm, s); // "batbox /g (x) "
    strcat(comm, i); // "batbox /g (x) (y)"
    
    system(comm);
    printf(".");
    memset(comm, 0, sizeof(comm));
    strcat(comm, "batbox /g");
    strcat(comm, s); // "batbox /g "
    strcat(comm, ds); // "batbox /g (z)"
    strcat(comm, s); // "batbox /g (z) "
    strcat(comm, d); // "batbox /g (z) (w)"
    system(comm);
    printf(".");
    memset(comm, 0, sizeof(comm));

    strcat(comm, "batbox /g");
    strcat(comm, s); // "batbox /g "
    strcat(comm, e); // "batbox /g (x)"
    strcat(comm, s); // "batbox /g (x) "
    strcat(comm, ds); // "batbox /g (x) (z)"
    system(comm);
    printf(".");
    memset(comm, 0, sizeof(comm));

    strcat(comm, "batbox /g");
    strcat(comm, s); // "batbox /g "
    strcat(comm, i); // "batbox /g (y)"
    strcat(comm, s); // "batbox /g (y) "
    strcat(comm, d); // "batbox /g (y) (w)"
    system(comm);
    printf(".");
    memset(comm, 0, sizeof(comm));
}