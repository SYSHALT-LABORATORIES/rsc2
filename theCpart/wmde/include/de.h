#define TRUE 1
#define FALSE 0
#define AND &
#define OR |
#define XOR ^
#define LSH <<
#define RSH >>
#define PI 3.14159
#define EVER ;;

#include <time.h>
#include <stdbool.h>

#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 39
#define KB_ESCAPE 27
#define KB_F8 66

int draw_window(int w, int h, int x, int y) { /* going to add char *buf later, need to make double buffer clean,
						since we don't have more than one layer (a window on top of ano
					       ther will end up overwriting the back window) and transparency
					       non-existence

						 */
    c_gotoxy(x, y);
    printf("+");

    for (int i = 2; i < w; i++) {
        printf("=");
    }
    if (w > 1) {
        printf("+");
    }
    printf("\n");

    for (int i = 2; i < h; i++) {
        c_gotoxy(1, i);
        printf("|"); 
        for (int j = 2; j < w; j++) {
            printf(" ");
        }
        if (w > 1) {
            c_gotoxy(w, i);
            printf("|"); 
        }
        printf("\n");
    }

    if (h > 1) {
        c_gotoxy(1, h);
        printf("+");
        for (int i = 2; i < w; i++) {
            printf("=");
        }
        if (w > 1) {
            printf("+");
        }
        printf("\n");
    } else if (h == 1 && w > 1) {
        c_gotoxy(w, h);
        printf("+");
    } else if (h == 1 && w == 1) {
        c_gotoxy(w, h);
        printf("+");
    }

}

int draw_circle(int w, int h, int x, int y) {
    c_gotoxy(x, y);
    int radius = h/2+w*w/(h*8);
    int negative_radius = abs(radius);
    int computed_value;
    int expected_value = radius * radius;
    for (int i = negative_radius; i <= radius; i++) {
        for (int j = negative_radius; j <= radius; j++) {
            computed_value = i * i + j * j;

            if (abs(computed_value - expected_value) <= radius) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int draw_clock_widget(bool digital) {
    time_t hora = time(NULL);
    char *time_str = ctime(&hora);
    time_str[strlen(time_str) - 1] = '\0';
    if (!digital) { // TODO: Implement triangle drawing + rotation so this actually is a clock
        draw_window(30, 25, 40, 15);
        c_gotoxy(15, 5);
        draw_circle(10, 10, 15, 5);
        return 42;
    }
    else {
        draw_window(20, 10, 100, 50); // uhh
        c_gotoxy(5, 2); // middle of window
        printf("%s", time_str);

        return 127;
    }
}

