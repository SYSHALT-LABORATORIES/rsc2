#include <sys/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

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
    printf("exit      > quit interpreter\n");
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
}

void exit_command(void) {
    printf("Exiting command interpreter.\n");
    exit(0);
}

Command commands[] = {
    {"help", help, "display existent commands"},
    {"reboot", reset, "restart computer using triple fault/non-ACPI"},
    {"cls", clrscr, "clear screen"},
    {"clear", clrscr, "clear screen"},
    {"shutdown", off, "shutdown computer via outw"},
    {"exit", exit_command, "exit interpreter"},
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

    fptr = fopen(fname, "r");

    if (fptr == NULL) {
	printf("Splash screen didn't load correctly.");
    }

    while((c = fgetc(fptr)) != EOF) {
	printf("%c", c);    
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
