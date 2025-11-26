#include <sys/io.h> // Windows phobic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "wmde/include/conio.h"
#include "wmde/include/conio.c"
#include "wmde/include/de.h"
#include <math.h>
#include "kernel_syscalls.h"

#define HELP 32
#define GUI  16
#define RST  8 // vacant, reset
#define SHT  4 // vacant, shutdown
#define CLS  64

typedef void (*command_fn)(void);

typedef struct {
    const char *name;
    command_fn run;
    const char *desc;
} Command;


int help(void) {
    printf("-+== COMMAND LIST ==+-\n");
    printf("help      > display commands\n");
    printf("reboot    > restart system\n");
    printf("shutdown  > shutdown system\n");
    printf("cls/clear > clear screen\n");
    printf("exit      > exit interpreter\n");
    printf("graph2d   > line graph out of csv\n");
    return HELP;
}

void reset(void) {
    printf("Rebooting...\n");
    asm volatile ("JMP 0xFFFF"); // triple fault reboot
}

int clrscr(void) {
    printf("\033[2J\033[H");
    return CLS;
}

void off(void) {
   printf("Shutting down...\n");
   outw(0x604, 0x2000); // QEMU shutdown
   asm volatile("HLT"); // freeze my boi
}

void exit_command(void) {
    printf("Exiting command interpreter.\n");
    exit(0);
}

void graph2d( void) {
  FILE *csvptr;
  const char *lechuga = "lechuga.csv";
  csvptr = fopen(lechuga, "rb");
  draw_graph2d_line(csvptr);
  fclose(csvptr);
}

Command commands[] = {
    {"help", (void*) help, "command list"}, 
    {"reboot", (void*) reset, "restart computer using triple fault/non-ACPI"},
    {"cls", (void*) clrscr, "clear screen"},
    {"clear", (void*) clrscr, "clear screen"},
    {"shutdown", (void*) off, "shutdown computer via outw"},
    {"exit", (void*) exit_command, "exit interpreter"},
    {"graph2d", (void*) graph2d, "make a graph out of csv"},
    {NULL, NULL, NULL}
};

command_fn find_command(const char* name) {
    for (int i = 0; commands[i].name; i++) {
        if (strcmp(name, commands[i].name) == 0) {
            return commands[i].run;
       }
    }
    return NULL;
}

int main(void) {
    FILE *fptr;
    char c;
    const char *fname = "mainscr.rgba";
    const int mcl = 256;
    char* command_buf = malloc(mcl * sizeof(char));

    fptr = fopen(fname, "rb");
    if (fptr == NULL) {
	printf("Splash screen didn't load correctly.");
    }

    #ifdef _WIN32
       system("chcp 437 > nul");
    #endif

  // #ifdef _RSC2PURE
	ch_charset437();
    //#endif

    while ((c = fgetc(fptr)) != EOF) {
         putchar(c);
     }

    fclose(fptr);

    if (!command_buf) {
        perror("malloc failed");
        return 1;
    }

    printf("");

    while (true) {
        printf("> ");
        if (!fgets(command_buf, mcl, stdin)) break;

        command_buf[strcspn(command_buf, "\n")] = 0;

        command_fn cmd = find_command(command_buf);
        if (cmd) {
            cmd();
        } else {
            printf(" Unknown command: %s\n", command_buf);
        }
    }

    free(command_buf);
    return 0;
	
}
