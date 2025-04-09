#include <stdio.h>
#include "include/conio.c"
#include "include/conio.h"
#include "include/de.h"
#include "include/png.h"
#include "include/hicolor.h"

png_infop info_ptr;
png_bytepp row_pointers;

int draw_desktop_background(char *bg_file) {
    FILE *fp = fopen(file_name, "rb");
    png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    info_ptr = png_create_info_struct(png_ptr);  
    png_init_io(png_ptr, fp);
    png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);
    row_pointers = png_get_rows(png_ptr, info_ptr);
    png_destroy_read_struct(&png_ptr, NULL, NULL); 
    fclose(fp);

    png_to_hicolor();
}