#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include "graphics.h"

void sig_handler(int signum) {
    printf("\e[?25h");
    _exit(EXIT_FAILURE);
}

void init_canvas(int w, int h, char* frame) {
    WIDTH = w;
    HEIGHT = h;
    for(int i=0; i<w*h; ++i) {
        frame[i] = ' ';
    }
    // hide the cursor
    // printf("\e[?25l");
    // signal(SIGINT, sig_handler);
}

// Return the cursor to the start
void back() {
    printf("\x1b[%dD", WIDTH);
    printf("\x1b[%dA", HEIGHT);
}

void clear(char* prev_frame) {
    char row[WIDTH];
    for(int ypos=0; ypos<HEIGHT; ++ypos) {
        for(int xpos=0; xpos<WIDTH; ++xpos) {
            row[xpos] = ' ';
            prev_frame[ypos*WIDTH + xpos] = ' ';
        }
        memcpy(prev_frame+(ypos*WIDTH), row, WIDTH);
        fwrite(row, WIDTH, 1, stdout);
        fputc('\n', stdout);
    }
    back();
} 

// todo: add params for starting coords and ending coords
// so we can make an arbitrary box
void draw_bounding_box(char* prev_frame) {
    char row[WIDTH];
    for(int ypos=0; ypos<HEIGHT; ypos++) {
        for(int xpos=0; xpos<WIDTH; ++xpos) {
            if(xpos == 0 || xpos == WIDTH-1) {
                row[xpos] = '|';
            }
            else if(ypos == 0 || ypos == HEIGHT - 1) {
                row[xpos] = '-';
            }
            else {
                row[xpos] = prev_frame[ypos*WIDTH + xpos];
            }
        }
        memcpy(prev_frame+(ypos*WIDTH), row, WIDTH);
        fwrite(row, WIDTH, 1, stdout);
        fputc('\n', stdout);
    }
    back();
}

// bool to determine solid square vs outline
void draw_square(int x, int y, size_t size, char c, bool fill, char* prev_frame) {

    char row[WIDTH];

    for(int ypos=0; ypos<HEIGHT; ++ypos) {
        for(int xpos=0; xpos<WIDTH; ++xpos) {
            if((x <= xpos && xpos < x + size) &&
               (y <= ypos && ypos < y + size)) { 
                row[xpos] = c;
            }
            else {
                row[xpos] = prev_frame[ypos*WIDTH + xpos];
            }
        }
        memcpy(prev_frame+(ypos*WIDTH), row, WIDTH);
        fwrite(row, WIDTH, 1, stdout);
        fputc('\n', stdout);
    }
    back();
}


// should update prev_frame in place!!
void draw_char(int x, int y, char c, char* prev_frame) {
    char row[WIDTH];
    for(int ypos=0; ypos<HEIGHT; ++ypos) {
        for(int xpos=0; xpos<WIDTH; ++xpos) {
            if(xpos == x && ypos == y) {
                row[xpos] = c;
            }
            else {
                row[xpos] = prev_frame[ypos*WIDTH + xpos];
            }
        }
        memcpy(prev_frame+(ypos*WIDTH), row, WIDTH);
        fwrite(row, WIDTH, 1, stdout);
        fputc('\n', stdout);
    }
    back();
}
