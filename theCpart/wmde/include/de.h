#define TRUE 1
#define FALSE 0
#define AND &
#define OR |
#define XOR ^
#define LSH <<
#define RSH >>
#define PI 3.14159
#define EVER ;;

#include <math.h> /* can create problems with possible dupes but later fixable*/
#include <time.h>
#include <stdbool.h>
// #include <stdlib.h> duplicate

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

const char* getfield(char* line, int num) { // csv parsing
	const char* tok;
	for (tok = strtok(line, ";");
			tok && *tok;
			tok = strtok(NULL, ";\n"))
	{
		if (!--num) {
			return tok;
	}}
	return NULL;
}

int compare(const void* a, const void* b) { // for qsort(...);
	return (*(int*) a - *(int*) b);
}

void draw_line_ascii(int x0, int y0, int x1, int y1, char ch) {
    int dx = abs(x1 - x0);
    int sx = (x0 < x1) ? 1 : -1;
    int dy = -abs(y1 - y0);
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx + dy;
    int e2;

    while (1) {
        c_gotoxy(x0, y0);
        putchar(ch);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

void draw_graph2d_line(FILE *csv) {
    char line[1024];
    int prev_x = -1, prev_y = -1;
    int origin_x = 0, origin_y = 0;

    while (fgets(line, sizeof(line), csv)) {
        char *tmp = strdup(line);
        if (!tmp) continue;

        int x = atoi(getfield(tmp, 1));
        int y = atoi(getfield(tmp, 2));

        //free(tmp);        why we freeing stack

        if (prev_x == -1 && prev_y == -1) {
            origin_x = x;
            origin_y = y;
            prev_x = x;
            prev_y = y;
            continue;
        }

        int diff_x = x - origin_x;
        int diff_y = y - origin_y;

        int scr_x0 = 5 + prev_x;
        int scr_y0 = 20 - prev_y;
        int scr_x1 = 5 + diff_x;
        int scr_y1 = 20 - diff_y;

        draw_line_ascii(scr_x0, scr_y0, scr_x1, scr_y1, '*');

        prev_x = x;
        prev_y = y;
    }

    draw_window(60, 25, 2, 1);
}
