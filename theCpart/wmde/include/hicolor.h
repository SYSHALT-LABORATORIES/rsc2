/*****************************************************************************
 * SYSHALT LABORATORIES
 * Software:   RSC² - rle defs
 * File:       hicolor.h
 * Author:     João Vítor (aka @df42Karazal)
 * Copyright:  1996 - 2025 (c) SYSHALT LABS
 * SPDX-License-Identifier:
 ****************************************************************************/

 #include "de.h"
 #include "../../kernel_syscalls.h"

typedef struct {int x; int y; u8 rgb[64][64][4096];} Sprite;
typedef struct {int x; int y; u8 rgb[16][16][2048];} Hire;
typedef struct {int x; int y; u8 rgb[1][1][1];}      TransparencyHackSpr;
typedef struct {
  int count;
  TransparencyHackSpr *minisprites;

}                                    HardcodeTranspHackG;

typedef struct {u8 *rgbaData; u64 size;} png;
typedef struct {u32 width; u32 height; u8 *data;} RGBAImage;// rgba interleaved
typedef struct { u8 r,g,b; } Color;

static const Color ansi_palette[16] = {
    {0,0,0},       {128,0,0},   {0,128,0},   {128,128,0},
    {0,0,128},     {128,0,128}, {0,128,128}, {192,192,192},
    {128,128,128}, {255,0,0},   {0,255,0},   {255,255,0},
    {0,0,255},     {255,0,255}, {0,255,255}, {255,255,255}
};


u8 blend(u8 fg, u8 bg, float alpha) {
    return (u8)((1 - alpha) * bg + alpha * fg);
}

u8 add(u8 fg, u8 bg, float alpha) {
  return (u8)fminf(255.0f, (float)bg + (float)fg * alpha);
}

i8 subtract(u8 addResult) {
  return addResult * -1;
}

int rgb3bit(u8 r, u8 g, u8 b) {
    return ((r > 127) << 2) | ((g > 127) << 1) | (b > 127);
}

RGBAImage *rgba_import(const char *fname) {
  FILE *fp  = fopen(fname, "rb");
  if (!fp) return NULL;
  RGBAImage *img = malloc(sizeof(RGBAImage));
  if (!img) {fclose(fp); return NULL;}
  fread(&img->width, sizeof(u32), 1, fp);
  fread(&img->height, sizeof(u32), 1, fp);

  size_t datasize = (size_t) img->width*img->height*4;
  img->data=malloc(datasize);
  if(!img->data) {fclose(fp); free(img); return NULL;}
  fread(img->data, 1, datasize, fp);
  fclose(fp);
  return img;
}

static inline int color_distance(Color a, Color b) {
    int dr = (int)a.r - (int)b.r;
    int dg = (int)a.g - (int)b.g;
    int db = (int)a.b - (int)b.b;
    return dr*dr + dg*dg + db*db;
}

int find_nearest_ansi(Color c) {
    int best = 0;
    int min_dist = 999999;
    for (int i = 0; i < 16; i++) {
        int d = color_distance(c, ansi_palette[i]);
        if (d < min_dist) {
            min_dist = d;
            best = i;
        }
    }
    return best;
}
void quantize_to_ansi(RGBAImage *img, u8 *out_indices, float alpha_threshold) {
    size_t pixels = (size_t)img->width * img->height;

    for (size_t i = 0; i < pixels; i++) {
        u8 r = img->data[i*4 + 0];
        u8 g = img->data[i*4 + 1];
        u8 b = img->data[i*4 + 2];
        u8 a = img->data[i*4 + 3];

        if (a < (u8)(alpha_threshold * 255)) {
            out_indices[i] = 0;
        } else {
            Color c = {r,g,b};
            out_indices[i] = (u8)find_nearest_ansi(c);
        }
    }
}
void rgba_export_quantized(const char *fname, RGBAImage *img, u8 *indices) {
    FILE *fp = fopen(fname, "wb");
    if (!fp) return;

    fwrite(&img->width,  sizeof(u32), 1, fp);
    fwrite(&img->height, sizeof(u32), 1, fp);
    fwrite(indices, 1, img->width * img->height, fp);

    fclose(fp);
}
