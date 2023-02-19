#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdio.h>

int WIDTH;
int HEIGHT;

typedef enum {false, true } bool;

void init_canvas(int, int, char*);
void back();
void clear(char*);
void draw_bounding_box(char*);
void draw_square(int, int, size_t, char, bool, char*);
void draw_char(int, int, char, char*);

#endif // GRAPHICS_H
